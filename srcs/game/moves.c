/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:42:29 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/06 17:30:00 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// field of vision rotate right (left arrow)
// field of vision rotate left (right arrow)

// move right / left (D or A key)
// move forwards / backwards (W or S key)

void	move_forwards(t_mlx *mlx_struct, t_data *data, t_player *player)
{
	(void)mlx_struct;
	//printf("before move_forwards %f %f\n", player->pos.x, player->pos.y);
	//printf("data->map[(int)(player->pos.x + PLAYER_SPEED * player->dir.x)][(int)(player->pos.y)] = %i %i\n", (int)(player->pos.x + PLAYER_SPEED * player->dir.x), (int)(player->pos.y));
	if (data->map[(int)(player->pos.y)][(int)(player->pos.x + PLAYER_SPEED * player->dir.x)] != '1')
		player->pos.x += player->dir.x * PLAYER_SPEED;
	if (data->map[(int)(player->pos.y + PLAYER_SPEED * player->dir.y)][(int)(player->pos.x)] != '1')
		player->pos.y += player->dir.y * PLAYER_SPEED;
	//printf("after move_forwards %f %f\n", player->pos.x, player->pos.y);
}

void	move_backwards(t_mlx *mlx_struct, t_data *data, t_player *player)
{
	(void)mlx_struct;
	if (data->map[(int)(player->pos.y)][(int)(player->pos.x - PLAYER_SPEED * player->dir.x)] != '1')
		player->pos.x -= player->dir.x * PLAYER_SPEED;
	if (data->map[(int)(player->pos.y - PLAYER_SPEED * player->dir.y)][(int)(player->pos.x)] != '1')
		player->pos.y -= player->dir.y * PLAYER_SPEED;
}

void	move_left(t_mlx *mlx_struct, t_data *data, t_player *player)
{
	(void)mlx_struct;
	if (data->map[(int)(player->pos.y)][(int)(player->pos.x - PLAYER_SPEED * player->dir.x)] != '1')
		player->pos.x -= player->dir.y * PLAYER_SPEED;
	if (data->map[(int)(player->pos.y - PLAYER_SPEED * player->dir.y)][(int)(player->pos.x)] != '1')
		player->pos.y += player->dir.x * PLAYER_SPEED;
}

void	move_right(t_mlx *mlx_struct, t_data *data, t_player *player)
{
	(void)mlx_struct;
	if (data->map[(int)(player->pos.y)][(int)(player->pos.x - PLAYER_SPEED * player->dir.x)] != '1')
		player->pos.x += player->dir.y * PLAYER_SPEED;
	if (data->map[(int)(player->pos.y - PLAYER_SPEED * player->dir.y)][(int)(player->pos.x)] != '1')
		player->pos.y -= player->dir.x * PLAYER_SPEED;
}

void	rotate_player(t_player *player, t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	if (player->rot == 1) // right
	{
		player->dir_deg += ROTATION_SPEED;
		if (player->dir_deg > 359)
			player->dir_deg -= 359;
		old_dir_x = player->dir.x;
		player->dir.x = player->dir.x * cos(-ROTATION_SPEED) - player->dir.y * sin(-ROTATION_SPEED);
		player->dir.y = old_dir_x * sin(-ROTATION_SPEED) + player->dir.y * cos(-ROTATION_SPEED);
		old_plane_x = data->ray->plane.x;
		data->ray->plane.x = data->ray->plane.x * cos(-ROTATION_SPEED) - data->ray->plane.y * sin(-ROTATION_SPEED);
		data->ray->plane.y = old_plane_x * sin(-ROTATION_SPEED) + data->ray->plane.y * cos(-ROTATION_SPEED);

	}
	else if (player->rot == -1) // left
	{
		player->dir_deg -= ROTATION_SPEED;
		if (player->dir_deg < 0)
			player->dir_deg += 359;
		old_dir_x = player->dir.x;
		player->dir.x = player->dir.x * cos(ROTATION_SPEED) - player->dir.y * sin(ROTATION_SPEED);
		player->dir.y = old_dir_x * sin(ROTATION_SPEED) + player->dir.y * cos(ROTATION_SPEED);
		old_plane_x = data->ray->plane.x;
		data->ray->plane.x = data->ray->plane.x * cos(ROTATION_SPEED) - data->ray->plane.y * sin(ROTATION_SPEED);
		data->ray->plane.y = old_plane_x * sin(ROTATION_SPEED) + data->ray->plane.y * cos(ROTATION_SPEED);
	}
	printf("%splayer direction = %f%s\n",BGREEN,  player->dir_deg, RESET);
}
