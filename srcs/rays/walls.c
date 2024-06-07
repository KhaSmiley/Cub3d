/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:24:47 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/07 17:59:31 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_walls(t_data *data, int x)
{
	int	color;

	// protections ? if == 2 || < 0
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
	// protections ? if == 2 || < 0

	//Calculate height of line to draw on screen
	data->ray->wall_len = (int)(S_H / data->ray->distance_to_wall);

	//calculate lowest and highest pixel to fill in current stripe
	data->ray->draw_start = -data->ray->wall_len / 2 + S_H / 2;

	if(data->ray->draw_start < 0)
		data->ray->draw_start = 0;
	data->ray->draw_end = data->ray->wall_len / 2 + S_H / 2;
	if(data->ray->draw_end >= S_H)
		data->ray->draw_end = S_H - 1;
}

void	find_next_wall(t_data *data)
{
	int	hit; //was there a wall hit?

	hit = 0;
	while (hit == 0)
	{
		//jump to next map square, either in x-direction, OR in y-direction
		if (data->ray->first_step.x < data->ray->first_step.y)
		{
			data->ray->first_step.x += data->ray->next_step.x;
			data->ray->map.x += data->ray->step_flag.x;
			if (data->ray->step_flag.x == -1)
				data->ray->texture = 'W';
			else
				data->ray->texture = 'E';
		}
		else
		{
			data->ray->first_step.y += data->ray->next_step.y;
			data->ray->map.y += data->ray->step_flag.y;
			if (data->ray->step_flag.y == -1)
				data->ray->texture = 'N';
			else
				data->ray->texture = 'S';
		}
		// protections ? if == 2 || < 0
		//Check if ray has hit a wall
		if (data->map[data->ray->map.y][data->ray->map.x] == '1')
			hit = 1;
	}

}

// first step = length of ray from current position to next x or y-side (le reste du carré)
// next step = length of ray from one x or y-side to next x or y-side (un cote du triangle tjrs fixe a 1)
void	calculate_steps(t_data *data)
{
	// protections ? if == 2 || < 0
	data->ray->next_step.x = fabs(1 / data->ray->ray_dir.x); // fabs puts negative floats to positive
	data->ray->next_step.y = fabs(1 / data->ray->ray_dir.y);

	// what direction to step in x or y-direction (either +1 [right or down] or -1 [left or up])
	// on va pas check tous les murs, on va juste check les murs qui sont sur le chemin du rayon
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
