/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:03:03 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/10 19:12:56 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// degrees to radians calculator
float	deg_to_rad(int deg)
{
	float	rad;

	rad = deg * (M_PI / 180);
	return (rad);
}

// radians to degrees calculator
int	rad_to_deg(float rad)
{
	int	deg;

	deg = rad * (180 / M_PI);
	return (deg);
}

void	init_camera_position(t_data *data, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)S_W - 1;
	data->ray->ray_dir.x = data->player->dir.x + data->ray->plane.x * camera_x;
	data->ray->ray_dir.y = data->player->dir.y + data->ray->plane.y * camera_x;
}

int	calculations(t_data *data)
{
	int	x;

	x = 0;
	while (x < S_W)
	{
		init_camera_position(data, x);
		data->ray->map.x = (int)data->player->pos.x;
		data->ray->map.y = (int)data->player->pos.y;
		calculate_steps(data);
		find_next_wall(data);
		// calculate distance to closest wall
		if (data->ray->texture == 'W' || data->ray->texture == 'E') // side == 0
			data->ray->distance_to_wall = (data->ray->map.x - data->player->pos.x + (1 - data->ray->step_flag.x) / 2) / data->ray->ray_dir.x;
		else
			data->ray->distance_to_wall = (data->ray->map.y - data->player->pos.y + (1 - data->ray->step_flag.y) / 2) / data->ray->ray_dir.y;
		calculate_wall_len(data);
		// draw_walls_colours(data, x);
		draw_walls_textures(data, x);
		x++;
	}
	return (0);
}
