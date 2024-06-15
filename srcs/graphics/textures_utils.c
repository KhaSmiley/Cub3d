/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:18:56 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/15 18:11:21 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	setup_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->textures[i].img = mlx_xpm_file_to_image(data->mlx->mlx_ptr,
				data->texture[i], &data->textures[i].w, &data->textures[i].h);
		if (!data->textures[i].img)
			ft_printf("texture %d not initialised\n", i);
		data->textures[i].addr = (int *)mlx_get_data_addr(data->textures[i].img,
				&data->textures[i].bpp, &data->textures[i].line_l,
				&data->textures[i].endian);
		if (!data->textures[i].addr)
			ft_printf("texture %d addr not initialised\n", i);
		i++;
	}
}

void	setup_screen_buffer(t_mlx *mlx)
{
	static t_textures	screen_buffer = {0};

	mlx->screen_buffer = &screen_buffer;
	mlx->screen_ptr = mlx_new_image(mlx->mlx_ptr, S_W, S_H);
	if (!mlx->screen_ptr)
		ft_printf("screen buffer not initialised\n");
	mlx->screen_buffer->addr = (int *)mlx_get_data_addr(mlx->screen_ptr,
			&(mlx->screen_buffer->bpp), &(mlx->screen_buffer->line_l),
			&(mlx->screen_buffer->endian));
}

// calculate texture x coord depending on if we're facing N/S or E/W
// calculations (texture step and pos) to make texture coords proportional
// stock texture start pos in double text pos variable (--> texture y coord)
// floor = maths.h func which leaves only fractional part of the coordinate
// where the wall was hit, removes int part,
// leaves value between 0 and 1. textures are typically accessed
// using normalized coordinates (between 0 and 1).
// repair flipped image problem
// get the exact texture position on collumn being drawn
void	calculate_text_x_coord(t_data *data, t_ray *ray, int i)
{
	if (ray->texture == 'E' || ray->texture == 'W')
		ray->wall_x = data->player->pos.y + ray->distance_to_wall
			* ray->ray_dir.y;
	else
		data->ray->wall_x = data->player->pos.x + ray->distance_to_wall
			* ray->ray_dir.x;
	ray->wall_x -= floor(ray->wall_x);
	ray->text_step = 1.0 * data->textures[i].h / data->ray->wall_len;
	ray->text_coord.x = (int)(ray->wall_x * (double)data->textures[i].w);
	if (data->ray->texture == 'N' || data->ray->texture == 'E')
		ray->text_coord.x = 64 - ray->text_coord.x - 1;
	ray->text_pos = (ray->draw_start - S_H / 2 + ray->wall_len / 2)
		* ray->text_step;
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
