/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:08:28 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/11 00:17:08 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// mlx xpm file to image for textures- give path and textures struct variables, get img ptr
// get data addr for textures
void	setup_textures(t_data *data)
{
	// turn this into double tableau de struct textures - do each step 4 times
	static t_textures textures = {0};
	data->textures = &textures;
	textures.img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, "./textures/thisisfine.xpm", &(textures.w), &(textures.h));
	if (!textures.img)
		printf("test texture not initialised\n");
	textures.addr = (int *)mlx_get_data_addr(textures.img, &(textures.bpp), &(textures.line_l), &(textures.endian));
	printf("%stextures addr %p%s\n", GREEN, textures.addr, RESET);
	printf("%stextures bpp %d%s\n", GREEN, textures.bpp, RESET);
	printf("%stextures line_l %d%s\n", GREEN, textures.line_l, RESET);
	printf("%stextures endian %d%s\n", GREEN, textures.endian, RESET);
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

// NEXT
// in screen width loop, call func which displays textures, in which:
// 1. get colours (rgb to int) - already done
// 2. draw celing --> draw start
// 3. from draw start to draw end, call draw wall textures func
// 3.a. find which texture, which direction we're facting (ray_dir -1 or 1)
// calculate texture x coord depending on if we're facing N/S or E/W
// 3.b. calculations (texture step and pos) to make texture coords proportional
// 3.c. stock texture start pos in double text pos variable (used to calc texture y coord)
// 3.d. loop through y, update y coord, update text pos variable (+ step), write into buffer
// --> write into bufffer : protect with screen_h and screen_w
// --> go to right memory address in mlx.addr[] using y * line_l / 4 + x
// / 4 takes into account 4 bytes per pixel, * y to go to right row, + x to go to right pixel
// same calculations within texture array to find corresponding exact pixel color value
// 4. draw floor --> screen height


void	draw_ceiling(t_data *data, int x)
{
	int		ceiling;

	ceiling = 0;
	while (ceiling < data->ray->draw_start)
	{
		printf("%sceiling %d%s\n", BLUE, ceiling, RESET);
		printf("%sray draw start %d%s\n", YELLOW, data->ray->draw_start, RESET);
		printf("trying to put ceiling colour %d at buffer addr %d\n", data->rgb_ceiling, (ceiling * data->mlx->screen_buffer->line_l / 4 + x));
		data->mlx->screen_buffer->addr[ceiling * data->mlx->screen_buffer->line_l / 4 + x] = data->rgb_ceiling;
		ceiling++;
	}
}
void	draw_walls_textures(t_data *data, int x)
{
	int		wall;
	int		floor;

	wall = data->ray->draw_start;
	floor = data->ray->draw_end;

	(void)x;

	// draw ceiling
	// put_line(data, x, 0, data->ray->draw_start, data->rgb_ceiling);
	draw_ceiling(data, x);
/*
	// stuff in amir's init game textures func
	// find which texture, which direction we're facting (ray_dir -1 or 1)
	// translate N S E W into 0 1 2 3 for array index
	// side == 0 = e w, side == 1 = n s
	if (data->ray->texture == 'E' || data->ray->texture == 'W')
		wall_hit_x = data->player->pos.y + data->ray->distance_to_wall * data->ray->ray_dir.y;
	else
		wall_hit_x = data->player->pos.x + data->ray->distance_to_wall * data->ray->ray_dir.x;
	// game->t.wall_x -= floor(game->t.wall_x); <- find out what this line does- floor seems to be either 1 or -1

	// calculations (texture step and pos) to make texture coords proportional
	step = 1.0 * data->textures->h / data->textures->line_l;
	texture_x = (int)(wall_hit_x * data->textures->w);
	if (data->ray->texture == 'E' || data->ray->texture == 'W')
		texture_x = data->textures->w - texture_x - 1;
	text_pos = (data->ray->draw_start - S_H / 2 + data->ray->wall_len / 2) * step;

	// while wall len
	while (wall < data->ray->draw_end)
	{
		texture_y = (int)text_pos & (data->textures->h - 1); // check how this binary comp works
		text_pos += step;
		if (x < S_W && wall < S_H)
			data->mlx->screen_buffer->addr[wall * data->mlx->screen_buffer->line_l / 4 + x] \
				= data->textures->addr[texture_y * data->textures->line_l / 4 + texture_x];
		wall++;
	}
*/

	// put_line(data, x, data->ray->draw_end, S_H, data->rgb_floor);
	// floor = data->ray->draw_end;
	// while (floor < S_H)
	// {
	// 	data->mlx->screen_buffer->addr[floor * data->mlx->screen_buffer->line_l / 4 + floor] = data->rgb_floor;
	// 	floor++;
	// }
}

	// int		y;
	// int		color;
	// double	text_pos;
	// int		tex_x;
	// int		tex_y;

	// y = data->ray->draw_start;
	// while (y < data->ray->draw_end)
	// {
	// 	text_pos = (y - S_H / 2 + data->ray->wall_len / 2) * (data->textures->h / data->ray->wall_len);
	// 	tex_x = (int)text_pos;
	// 	tex_y = (int)data->ray->texture;
	// 	color = data->textures->addr[tex_y * data->textures->line_l / 4 + tex_x];
	// 	data->mlx->screen_buffer->addr[y * data->mlx->screen_buffer->line_l / 4 + x] = color;
	// 	y++;
	// }
