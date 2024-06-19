/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:03:03 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/17 17:09:17 by lbarry           ###   ########.fr       */
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

	camera_x = 2 * (S_W - x) / (double)S_W - 1;
	data->ray->ray_dir.x = data->player->dir.x + data->ray->plane.x * camera_x;
	data->ray->ray_dir.y = data->player->dir.y + data->ray->plane.y * camera_x;
}

int	calculations(t_data *data, t_ray *ray)
{
	int	x;

	x = 0;
	while (x < S_W)
	{
		init_camera_position(data, x);
		ray->map.x = (int)data->player->pos.x;
		ray->map.y = (int)data->player->pos.y;
		calculate_steps(data->player, data->ray);
		find_next_wall(data, data->ray);
		if (ray->texture == 'W' || ray->texture == 'E')
			ray->distance_to_wall = (ray->map.x - data->player->pos.x
					+ (1 - ray->step_flag.x) / 2) / ray->ray_dir.x;
		else
			ray->distance_to_wall = (ray->map.y - data->player->pos.y
					+ (1 - ray->step_flag.y) / 2) / ray->ray_dir.y;
		calculate_wall_len(data);
		draw_walls_textures(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->mlx_win,
		data->mlx->screen_ptr, 0, 0);
	return (0);
}
