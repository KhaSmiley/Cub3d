/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:24:47 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/14 18:45:33 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*
void	draw_walls_colors(t_data *data, int x)
{
	int	color;

	(void)x;
	if (data->map[data->ray->map.y][data->ray->map.x] == '1')
	{
		if (data->ray->texture == 'N')
			color = 0x00FF00;
		else if (data->ray->texture == 'S')
			color = 0x0000FF;
		else if (data->ray->texture == 'W')
			color = 0xFF0000;
		else
			color = 0xFFFF00;
	}
	else
		color = 0x00FFFF;
	put_line(data, x, data->ray->draw_start, data->ray->draw_end, color);
	put_line(data, x, 0, data->ray->draw_start, data->rgb_ceiling);
	put_line(data, x, data->ray->draw_end, S_H, data->rgb_floor);
}
*/

// Calculate height of line to draw on screen
// calculate lowest and highest pixel to fill in current stripe
void	calculate_wall_len(t_data *data)
{
	data->ray->wall_len = (int)(S_H / data->ray->distance_to_wall);
	data->ray->draw_start = -data->ray->wall_len / 2 + S_H / 2;
	if (data->ray->draw_start < 0)
		data->ray->draw_start = 0;
	data->ray->draw_end = data->ray->wall_len / 2 + S_H / 2;
	if (data->ray->draw_end >= S_H)
		data->ray->draw_end = S_H - 1;
}

// was there a wall hit?
//jump to next map square, either in x-direction, OR in y-direction
void	find_next_wall(t_data *data, t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->first_step.x < ray->first_step.y)
		{
			ray->first_step.x += ray->next_step.x;
			ray->map.x += ray->step_flag.x;
			if (ray->step_flag.x == -1)
				ray->texture = 'W';
			else
				ray->texture = 'E';
		}
		else
		{
			ray->first_step.y += ray->next_step.y;
			ray->map.y += ray->step_flag.y;
			if (ray->step_flag.y == -1)
				ray->texture = 'N';
			else
				ray->texture = 'S';
		}
		if (data->map[ray->map.y][ray->map.x] == '1')
			ray->hit = 1;
	}
}

// first step = length of ray from current position to next x or y-side
// next step = length of ray from one x or y-side to next x or y-side
// what direction to step in for x and y
// (either +1 [right or down] or -1 [left or up])
// on va pas check tous les murs, juste les murs qui sont sur le chemin du rayon
// fabs puts negative floats to positive
// going left, going right, going up, going down
void	calculate_steps(t_player *player, t_ray *ray)
{
	ray->next_step.x = fabs(1 / ray->ray_dir.x);
	ray->next_step.y = fabs(1 / ray->ray_dir.y);
	if (ray->ray_dir.x < 0)
	{
		ray->step_flag.x = -1;
		ray->first_step.x = (player->pos.x - ray->map.x) * ray->next_step.x;
	}
	else
	{
		ray->step_flag.x = 1;
		ray->first_step.x = (ray->map.x + 1.0 - player->pos.x)
			* ray->next_step.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step_flag.y = -1;
		ray->first_step.y = (player->pos.y - ray->map.y) * ray->next_step.y;
	}
	else
	{
		ray->step_flag.y = 1;
		ray->first_step.y = (ray->map.y + 1.0 - player->pos.y)
			* ray->next_step.y;
	}
}
