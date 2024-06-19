/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:42:29 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/17 17:12:19 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_forwards(t_data *data, t_player *player)
{
	if (data->map[(int)(player->pos.y)][(int)(player->pos.x)] == 1)
		return ;
	if (data->map[(int)(player->pos.y)][(int)(player->pos.x + player->dir.x
			* PLAYER_SPEED)] != '1')
		player->pos.x += player->dir.x * PLAYER_SPEED;
	if (data->map[(int)(player->pos.y + player->dir.y
			* PLAYER_SPEED)][(int)(player->pos.x)] != '1')
		player->pos.y += player->dir.y * PLAYER_SPEED;
}

void	move_backwards(t_data *data, t_player *player)
{
	if (data->map[(int)(player->pos.y)][(int)(player->pos.x)] == 1)
		return ;
	if (data->map[(int)(player->pos.y)][(int)(player->pos.x - player->dir.x
			* PLAYER_SPEED)] != '1')
		player->pos.x -= player->dir.x * PLAYER_SPEED;
	if (data->map[(int)(player->pos.y - player->dir.y
			* PLAYER_SPEED)][(int)(player->pos.x)] != '1')
		player->pos.y -= player->dir.y * PLAYER_SPEED;
}

void	move_left(t_data *data, t_player *player)
{
	if (data->map[(int)(player->pos.y)][(int)(player->pos.x)] == 1)
		return ;
	if (data->map[(int)(player->pos.y)][(int)(player->pos.x + player->dir.y
			* PLAYER_SPEED)] != '1')
		player->pos.x += player->dir.y * PLAYER_SPEED;
	if (data->map[(int)(player->pos.y - player->dir.x
			* PLAYER_SPEED)][(int)(player->pos.x)] != '1')
		player->pos.y -= player->dir.x * PLAYER_SPEED;
}

void	move_right(t_data *data, t_player *player)
{
	if (data->map[(int)(player->pos.y)][(int)(player->pos.x - player->dir.y
			* PLAYER_SPEED)] != '1')
		player->pos.x -= player->dir.y * PLAYER_SPEED;
	if (data->map[(int)(player->pos.y + player->dir.x
			* PLAYER_SPEED)][(int)(player->pos.x)] != '1')
		player->pos.y += player->dir.x * PLAYER_SPEED;
}

void	rotate_player(t_player *player, t_data *data)
{
	if (data->map[(int)(player->pos.y)][(int)(player->pos.x)] == 1)
		return ;
	if (player->rot == 1)
		rotate_left(data, data->player);
	else if (player->rot == -1)
		rotate_right(data, data->player);
}
