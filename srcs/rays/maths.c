/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:03:03 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/06 00:26:48 by lbarry           ###   ########.fr       */
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

void	draw_walls(t_data *data, int x)
{
		int	color;

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
		put_line(data, x, 0, data->ray->draw_start, 0x123AAA);
		put_line(data, x, data->ray->draw_end, S_H, 0x432411);
}

void	calculate_wall_len(t_data *data)
{
	//Calculate height of line to draw on screen
	data->ray->wall_len = (int)(S_H / data->ray->distance_to_wall);

	//calculate lowest and highest pixel to fill in current stripe
	data->ray->draw_start = -data->ray->wall_len / 2 + S_H / 2;
	if(data->ray->draw_start < 0)
		data->ray->draw_start = 0;
	// printf("drawStart = %d\n", data->ray->draw_start);
	data->ray->draw_end = data->ray->wall_len / 2 + S_H / 2;
	if(data->ray->draw_end >= S_H)
		data->ray->draw_end = S_H - 1;
	// printf("drawEnd = %d\n", data->ray->draw_end);
}

void	find_next_wall(t_data *data)
{
	int	hit; //was there a wall hit?

	hit = 0;
	// on avance de sidedist x ou y selon quelle
	// intersection et le plus proche, et on regarde si on a un 1 dans cette case
	while (hit == 0)
	{
		//jump to next map square, either in x-direction, OR in y-direction
		if (data->ray->first_step.x < data->ray->first_step.y)
		{
			data->ray->first_step.x += data->ray->next_step.x;
			if (data->ray->step_flag.x == -1)
				data->ray->texture = 'W';
			else
				data->ray->texture = 'E';
			// change protections
			if (data->ray->map.x + 1 < data->w_map && data->ray->map.x - 1 >= 0)
				data->ray->map.x += data->ray->step_flag.x;
			else
			{
				hit = 1;
				break;
			}
		}
		else
		{
			data->ray->first_step.y += data->ray->next_step.y;
			if (data->ray->step_flag.y == -1)
				data->ray->texture = 'N';
			else
				data->ray->texture = 'S';
			// change protections
			if (data->ray->map.y + 1 < data->nb_line && data->ray->map.y - 1 >= 0)
				data->ray->map.y += data->ray->step_flag.y;
			else
			{
				hit = 1;
				break;
			}
		}
		//Check if ray has hit a wall
		// printf("map.x = %d\n", data->ray->map.x);
		// printf("map.y = %d\n", data->ray->map.y);
		if (data->map[data->ray->map.y][data->ray->map.x] == '1')
		{
			hit = 1;
		}
	}

}

void	calculate_steps(t_data *data)
{
	// length of ray from one x or y-side to next x or y-side
	// on est pas dans ces carrés la (un cote du triangle tjrs fixe a 1)
	data->ray->next_step.x = fabs(1 / data->ray->ray_dir.x); // fabs puts negative floats to positive
	data->ray->next_step.y = fabs(1 / data->ray->ray_dir.y);

	// what direction to step in x or y-direction (either +1 [right or down] or -1 [left or up])
	// on va pas check tous les murs, on va juste check les murs qui sont sur le chemin du rayon

	// next step = length of ray from current position to next x or y-side (le reste du carré)
	if (data->ray->ray_dir.x < 0)
	{
		data->ray->step_flag.x = -1; // going left
		data->ray->first_step.x = (data->player->pos.x - data->ray->map.x) * data->ray->next_step.x;
	}
	else
	{
		data->ray->step_flag.x = 1; // going right
		data->ray->first_step.x = (data->ray->map.x + 1.0 - data->player->pos.x) * data->ray->next_step.x;
	}
	if (data->ray->ray_dir.y < 0)
	{
		data->ray->step_flag.y = -1; // going up
		data->ray->first_step.y = (data->player->pos.y - data->ray->map.y) * data->ray->next_step.y;
	}
	else
	{
		data->ray->step_flag.y = 1; // going down
		data->ray->first_step.y = (data->ray->map.y + 1.0 - data->player->pos.y) * data->ray->next_step.y;
	}
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
		if (data->ray->texture == 'W' || data->ray->texture == 'E')
			data->ray->distance_to_wall = (data->ray->map.x - data->player->pos.x + (1 - data->ray->step_flag.x) / 2) / data->ray->ray_dir.x;
		else
			data->ray->distance_to_wall = (data->ray->map.y - data->player->pos.y + (1 - data->ray->step_flag.y) / 2) / data->ray->ray_dir.y;
		calculate_wall_len(data);
		// replace with wall textures / buffer fill funcs (no more put pixel)
		draw_walls(data, x);
		x++;
	}
	return (0);
}
