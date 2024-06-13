/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:08:28 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/13 23:47:46 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// char ** data->texture
// [0] = NO
// [1] = SO
// [2] = WE
// [3] = EA

// mlx xpm file to image for textures- give path and textures struct variables, get img ptr
// get data addr for textures
void	setup_textures(t_data *data)
{
	int	i;

	i = 0;
    while (i < 4)
    {
        printf("first texture %d = *******%s*******\n", i, data->texture[0]);
        data->textures[i].img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, data->texture[0], &data->textures[i].w,  &data->textures[i].h);
        if (!data->textures[i].img)
            printf("texture %d not initialised\n", i);
        data->textures[i].addr = (int *)mlx_get_data_addr(data->textures[i].img, &data->textures[i].bpp, &data->textures[i].line_l, &data->textures[i].endian);
		if (!data->textures[i].addr)
			printf("texture %d addr not initialised\n", i);
        printf("%stextures addr %p%s\n", GREEN, data->textures[i].addr, RESET);
        printf("%stextures bpp %d%s\n", GREEN, data->textures[i].bpp, RESET);
        printf("%stextures line_l %d%s\n", GREEN, data->textures[i].line_l, RESET);
        printf("%stextures endian %d%s\n", GREEN, data->textures[i].endian, RESET);
        i++;
    }
}

// mlx new img to get img ptr for screen, get data addr using this ptr - creates buffer
void	setup_screen_buffer(t_data *data)
{
	static	t_textures screen_buffer = {0};
	data->mlx->screen_buffer = &screen_buffer;
	data->mlx->screen_ptr = mlx_new_image(data->mlx->mlx_ptr, S_W, S_H);
	if (!data->mlx->screen_ptr)
		printf("screen buffer not initialised\n");
	data->mlx->screen_buffer->addr = (int *)mlx_get_data_addr(data->mlx->screen_ptr, \
		&(data->mlx->screen_buffer->bpp), &(data->mlx->screen_buffer->line_l), &(data->mlx->screen_buffer->endian));
	printf("%sscreen buffer addr %p%s\n", CYAN, data->mlx->screen_buffer->addr, RESET);
	printf("%sscreen buffer bpp %d%s\n", CYAN, data->mlx->screen_buffer->bpp, RESET);
	printf("%sscreen buffer line_l %d%s\n", CYAN, data->mlx->screen_buffer->line_l, RESET);
	printf("%sscreen buffer endian %d%s\n", CYAN, data->mlx->screen_buffer->endian, RESET);
}

void	draw_ceiling(t_data *data, int x)
{
	int	ceiling;

	ceiling = 0;
	while (ceiling < data->ray->draw_start)
	{
		if (ceiling < S_H && ceiling >= 0)
			data->mlx->screen_buffer->addr[ceiling * data->mlx->screen_buffer->line_l / 4 + x] = data->rgb_ceiling;
		ceiling++;
	}
}

void	draw_floor(t_data *data, int x)
{
	int	floor;

	floor = data->ray->draw_end;
	while (floor < S_H)
	{
		if (floor < S_H && floor >= 0)
			data->mlx->screen_buffer->addr[floor * data->mlx->screen_buffer->line_l / 4 + x] = data->rgb_floor;
		floor++;
	}
}

// loop through y, update y coord, update text pos variable (+ step), write into buffer
// --> write into bufffer : protect with screen_h and screen_w
// --> go to right memory address in mlx.addr[] using y * line_l / 4 + x
// takes into account 4 bytes per pixel, * y to go to right row, + x to go to right pixel
// same calculations within texture array to find corresponding exact pixel color value
void	draw_walls(t_data *data, int x, int i)
{
	int	wall;

	wall = data->ray->draw_start;
	while (wall < data->ray->draw_end)
	{
		data->ray->text_coord.y = (int)data->ray->text_pos & (data->textures[i].h - 1);
		data->ray->text_pos += data->ray->text_step;
		if (x < S_W && wall < S_H)
			data->mlx->screen_buffer->addr[wall * data->mlx->screen_buffer->line_l / 4 + x]	= data->textures[i].addr[data->ray->text_coord.y * data->textures[i].line_l / 4 + data->ray->text_coord.x];
		wall++;
	}
}

// calculate texture x coord depending on if we're facing N/S or E/W
// calculations (texture step and pos) to make texture coords proportional
// stock texture start pos in double text pos variable (used to calc texture y coord)
// floor = maths.h func which leaves only fractional part of the coordinate where the wall was hit, removes int part, leaves value between 0 and 1. textures are typically accessed using normalized coordinates (between 0 and 1).
// repair flipped image problem
// get the exact texture position on collumn being drawn
void	calculate_text_x_coord(t_data *data, int i)
{
	if (data->ray->texture == 'E' || data->ray->texture == 'W')
		data->ray->wall_x = data->player->pos.y + data->ray->distance_to_wall * data->ray->ray_dir.y;
	else
		data->ray->wall_x = data->player->pos.x + data->ray->distance_to_wall * data->ray->ray_dir.x;
	data->ray->wall_x -= floor(data->ray->wall_x);
	data->ray->text_step = 1.0 * data->textures[i].h / data->ray->wall_len;
	data->ray->text_coord.x = (int)(data->ray->wall_x * (double)data->textures[i].w);
	if (data->ray->texture == 'N' || data->ray->texture == 'E')
		data->ray->text_coord.x = 64 - data->ray->text_coord.x - 1;
	data->ray->text_pos = (data->ray->draw_start - S_H / 2 + data->ray->wall_len / 2) * data->ray->text_step;
}

int	get_wall_texture(t_data *data)
{
	int	texture;
	if (data->ray->texture == 'N')
		texture = 0;
	else if (data->ray->texture == 'S')
		texture = 1;
	else if (data->ray->texture == 'W')
		texture = 2;
	else
		texture = 3;
	return (texture);
}
void	draw_walls_textures(t_data *data, int x)
{
	int	texture;

	texture = -1;
	draw_ceiling(data, x);
	draw_floor(data, x);
	texture = get_wall_texture(data);
	calculate_text_x_coord(data, texture);
	draw_walls(data, x, texture);
}
