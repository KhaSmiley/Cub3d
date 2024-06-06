/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:20:48 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/06 17:21:12 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// init dir x and y correctly
void	set_start_direction(t_player *player, char dir)
{
	if (dir == 'N')
	{
		player->dir.x = 0;
		player->dir.y = 1;
		player->dir_deg = 90;
	}
	else if (dir == 'S')
	{
		player->dir.x = 0;
		player->dir.y = -1;
		player->dir_deg = 270;
	}
	else if (dir == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
		player->dir_deg = 180;
	}
	else if (dir == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
		player->dir_deg = 0;
	}
}

void	set_player_start_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->nb_line)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				data->start_pos.x = j;
				data->start_pos.y = i;
				data->player_dir = data->map[i][j];
				data->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	get_map_width_height(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->w_map = 0;
	data->h_map = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
			j++;
		if (j > data->w_map)
			data->w_map = j;
		i++;
	}
	data->h_map = i;
}
void	display_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				put_tiles(data->mlx->mlx_ptr, data->mlx->mlx_win, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}
