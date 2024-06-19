/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:08:28 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/17 17:46:38 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_ceiling(t_data *data, int x)
{
	int	ceiling;

	ceiling = 0;
	while (ceiling < data->ray->draw_start)
	{
		if (ceiling < S_H && ceiling >= 0)
			data->mlx->screen_buffer->addr[ceiling
				* data->mlx->screen_buffer->line_l / 4 + x] = data->rgb_ceiling;
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
			data->mlx->screen_buffer->addr[floor
				* data->mlx->screen_buffer->line_l / 4 + x] = data->rgb_floor;
		floor++;
	}
}

// loop through y, update y coord, update text pos variable (+ step)
// write into buffer
// --> write into bufffer : protect with screen_h and screen_w
// --> go to right memory address in mlx.addr[] using y * line_l / 4 + x
// takes into account 4 bytes per pixel, * y to go to right row
// + x to go to right pixel
// same calculations within texture array to find corresponding
// exact pixel color value

void	draw_walls(t_data *data, int x, int i)
{
	int	wall;
	int	buffer_index;
	int	texture_index;

	wall = data->ray->draw_start;
	while (wall < data->ray->draw_end)
	{
		data->ray->text_coord.y = (int)data->ray->text_pos
			& (data->textures[i].h - 1);
		data->ray->text_pos += data->ray->text_step;
		buffer_index = wall * data->mlx->screen_buffer->line_l / 4 + x;
		texture_index = data->ray->text_coord.y
			* data->textures[i].line_l / 4 + data->ray->text_coord.x;
		if (x < S_W && wall < S_H)
			data->mlx->screen_buffer->addr[buffer_index]
				= data->textures[i].addr[texture_index];
		wall++;
	}
}

void	draw_walls_textures(t_data *data, int x)
{
	int	texture;

	texture = -1;
	draw_ceiling(data, x);
	draw_floor(data, x);
	texture = get_wall_texture(data);
	calculate_text_x_coord(data, data->ray, texture);
	draw_walls(data, x, texture);
}
