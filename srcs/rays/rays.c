/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:08:28 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/18 00:09:44 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_ray(t_data *data, t_player *player, float ray_end_x, float ray_end_y)
{
	double ratio;
	int i  = 0;
	int	pixels = 100;
	int	ray_colour = 0x00CC00FF;

	while (i < pixels)
	{
		//printf("drawing ray\n");
		// just a thing to calculate spacing between pixels relative to length of ray
		ratio = (double)i / (double)(pixels - 1);
		mlx_pixel_put(data->mlx->mlx_ptr, data->mlx->mlx_win, player->player_x + ratio * (ray_end_x - player->player_x) + 4,
			player->player_y + ratio * (ray_end_y - player->player_y) + 4, ray_colour);
		i++;
	}
}

void	put_rays_fov(t_data *data, t_ray *ray, float distance_to_wall)
{
	float	ray_end_x;
	float	ray_end_y;

	ray->ray_dir = data->player->direction;
	// printing 30 rays right of player direction
	while (ray->ray_dir - data->player->direction < FOV / 2)
	{
		ray_end_x = data->player->player_x + cos(deg_to_rad(ray->ray_dir)) * distance_to_wall;
		ray_end_y = data->player->player_y + sin(deg_to_rad(ray->ray_dir)) * distance_to_wall;
		put_ray(data, data->player, ray_end_x, ray_end_y);
		// printf("ray direction = %f\n", ray->ray_dir);
		ray->ray_dir += 1;
	}
	//printing 30 rays left of player direction
	ray->ray_dir = data->player->direction;
	while (data->player->direction - ray->ray_dir < FOV / 2)
	{
		ray_end_x = data->player->player_x + cos(deg_to_rad(ray->ray_dir)) * distance_to_wall;
		ray_end_y = data->player->player_y + sin(deg_to_rad(ray->ray_dir)) * distance_to_wall;
		put_ray(data, data->player, ray_end_x, ray_end_y);
		// printf("ray direction = %f\n", ray->ray_dir);
		ray->ray_dir -= 1;
	}
}

int	cast_rays(t_data *data)
{
	float	distance_to_wall = 200;
	// calculate distances to walls to have both collisions - x and y
	// distance to wall variable = first collision (shortest hypothenuse)

	put_rays_fov(data, data->ray, distance_to_wall);
	calculate_collisions(data, data->player);

	return (0);
}
