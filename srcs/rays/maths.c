/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:03:03 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/21 00:51:54 by lbarry           ###   ########.fr       */
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

void	calculate_collisions(t_data *data, t_player *player)
{
	(void)data;
	// calculate next y axes collision

	// collision y coord
	float y_collision = (player->player_y / TILE_SIZE) * TILE_SIZE;
	// collision x coord
	float x_collision = player->player_x + (y_collision - player->player_y) / tan(player->direction);

	mlx_pixel_put(data->mlx->mlx_ptr, data->mlx->mlx_win, x_collision, y_collision, 0x000099FF);
	printf("%sy_collision = %f%s\n", GREEN, y_collision, RESET);
	printf("%sx_collision = %f%s\n", GREEN, x_collision, RESET);


	// distance
	float distance = sqrt(pow(player->player_x - x_collision, 2) + pow(player->player_y - y_collision, 2));
	printf("%sdistance = %f%s\n", GREEN, distance, RESET);

	// y step
	float y_step = TILE_SIZE;

	// x step
	float x_step = TILE_SIZE / tan(player->direction);

	(void)y_step;
	(void)x_step;

	//printf("%sy_step = %f%s\n", RED, y_step, RESET);
	//printf("%sx_step = %f%s\n", RED, x_step, RESET);

	// distance to y collision (length of hypotheneuse)
}

// float	nor_angle(float angle)	// normalize the angle
// {
// 	if (angle < 0)
// 		angle += (2 * M_PI);
// 	if (angle > (2 * M_PI))
// 		angle -= (2 * M_PI);
// 	return (angle);
// }
