/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:08:28 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/16 21:09:48 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	cast_rays(t_data *data)
{
	float ray_end_x;
	float ray_end_y;
	double ratio;
	int i  = 0;
	int	pixels = 100;
	float	distance_to_wall = 200;
	// calculate distances to walls to have both collisions - x and y - distance to wall variable = first collision (shortest hypothenuse)

	ray_end_x = data->player->player_x + cos(deg_to_rad(data->player->direction)) * distance_to_wall;
	ray_end_y = data->player->player_y + sin(deg_to_rad(data->player->direction)) * distance_to_wall;

	while (i < pixels)
	{
		ratio = (double)i / (double)(pixels - 1);
		mlx_pixel_put(data->mlx->mlx_ptr, data->mlx->mlx_win, data->player->player_x + ratio * (ray_end_x - data->player->player_x), data->player->player_y + ratio * (ray_end_y - data->player->player_y), 0x00CC00FF);
		i++;
	}
	return (0);
}
