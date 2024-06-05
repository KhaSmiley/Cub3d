/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:08:28 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/06 00:27:30 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_ray(t_data *data, t_player *player, float ray_end_x, float ray_end_y)
{
	double ratio = 0;
	int i  = 0;
	int	pixels = 100;
	int	ray_colour = 0x00CC00FF;
	t_moha2i pos = {0};

	while (i < pixels)
	{
		// just a thing to calculate spacing between pixels relative to length of ray
		ratio = (double)i / (double)(pixels - 1);

		pos.x = player->pos.x + ratio * (ray_end_x - player->pos.x) + 4;
		pos.y = player->pos.y + ratio * (ray_end_y - player->pos.y) + 4;
		if (pos.x < 0 || pos.x > S_W || pos.y < 0 || pos.y > S_H)
			break ;
		// COLLISIONS
		if (data->map[(int)(pos.y / TILE_SIZE)][(int)(pos.x / TILE_SIZE)] == '1')
		{
			// stock coord to have distance to wall
			break ;
		}

		mlx_pixel_put(data->mlx->mlx_ptr, data->mlx->mlx_win, player->pos.x + ratio * (ray_end_x - player->pos.x) + 4,
			player->pos.y + ratio * (ray_end_y - player->pos.y) + 4, ray_colour);
		i++;
	}
}

void	put_rays_fov(t_data *data, t_ray *ray)
{
	float	ray_end_x;
	float	ray_end_y;

	// replace
	float distance_to_wall = 100;

	ray->ray_dir_deg = data->player->dir_deg;
	// printing 30 rays right of player direction
	while (ray->ray_dir_deg - data->player->dir_deg < FOV / 2)
	{
		ray_end_x = data->player->pos.x + cos(deg_to_rad(ray->ray_dir_deg)) * distance_to_wall;
		ray_end_y = data->player->pos.y + sin(deg_to_rad(ray->ray_dir_deg)) * distance_to_wall;
		put_ray(data, data->player, ray_end_x, ray_end_y);
		// printf("ray direction = %f\n", ray->ray_dir_deg);
		ray->ray_dir_deg += 1;
	}
	//printing 30 rays left of player direction
	ray->ray_dir_deg = data->player->dir_deg;
	while (data->player->dir_deg - ray->ray_dir_deg < FOV / 2)
	{
		ray_end_x = data->player->pos.x + cos(deg_to_rad(ray->ray_dir_deg)) * distance_to_wall;
		ray_end_y = data->player->pos.y + sin(deg_to_rad(ray->ray_dir_deg)) * distance_to_wall;
		put_ray(data, data->player, ray_end_x, ray_end_y);
		// printf("ray direction = %f\n", ray->ray_dir_deg);
		ray->ray_dir_deg -= 1;
	}
}

int	cast_rays(t_data *data)
{
	// at some point take out the put rays fov pixel putting- only needed for calculations
	printf("player direction = %f\n", data->player->dir_deg);
	put_rays_fov(data, data->ray);
	// calculations
	return (0);
}
