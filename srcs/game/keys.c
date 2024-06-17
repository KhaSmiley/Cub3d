/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:33:54 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/15 18:22:09 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	move_rotate(t_data *data)
{
	if (data->player->key_flags->w == 1)
		move_forwards(data, data->mlx->player);
	if (data->player->key_flags->a == 1)
		move_left(data, data->mlx->player);
	if (data->player->key_flags->s == 1)
		move_backwards(data, data->mlx->player);
	if (data->player->key_flags->d == 1)
		move_right(data, data->mlx->player);
	if (data->player->key_flags->left == 1)
	{
		data->player->rot = -1;
		rotate_player(data->mlx->player, data);
	}
	if (data->player->key_flags->right == 1)
	{
		data->player->rot = 1;
		rotate_player(data->mlx->player, data);
	}
	if (data->player->key_flags->esc == 1)
		on_destroy(data);
	calculations(data, data->ray);
	return (1);
}

int	key_press(int keycode, t_mlx *mlx_struct)
{
	if (keycode == KEY_W)
		mlx_struct->player->key_flags->w = 1;
	if (keycode == KEY_A)
		mlx_struct->player->key_flags->a = 1;
	if (keycode == KEY_S)
		mlx_struct->player->key_flags->s = 1;
	if (keycode == KEY_D)
		mlx_struct->player->key_flags->d = 1;
	if (keycode == KEY_LEFT)
		mlx_struct->player->key_flags->left = 1;
	if (keycode == KEY_RIGHT)
		mlx_struct->player->key_flags->right = 1;
	if (keycode == KEY_ESC)
		mlx_struct->player->key_flags->esc = 1;
	if (keycode == KEY_CTRL)
		mlx_struct->player->key_flags->ctrl = 1;
	return (1);
}

int	key_release(int keycode, t_mlx *mlx_struct)
{
	if (keycode == KEY_W)
		mlx_struct->player->key_flags->w = 0;
	if (keycode == KEY_A)
		mlx_struct->player->key_flags->a = 0;
	if (keycode == KEY_S)
		mlx_struct->player->key_flags->s = 0;
	if (keycode == KEY_D)
		mlx_struct->player->key_flags->d = 0;
	if (keycode == KEY_LEFT)
		mlx_struct->player->key_flags->left = 0;
	if (keycode == KEY_RIGHT)
		mlx_struct->player->key_flags->right = 0;
	if (keycode == KEY_ESC)
		mlx_struct->player->key_flags->esc = 0;
	if (keycode == KEY_CTRL)
		mlx_struct->player->key_flags->ctrl = 0;
	return (1);
}

void	rotate_right(t_data *data, t_player *player)
{
	player->dir_deg += ROTATION_SPEED;
	if (player->dir_deg > 359)
		player->dir_deg -= 359;
	player->old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cos(-ROTATION_SPEED)
		- player->dir.y * sin(-ROTATION_SPEED);
	player->dir.y = player->old_dir_x * sin(-ROTATION_SPEED)
		+ player->dir.y * cos(-ROTATION_SPEED);
	player->old_plane_x = data->ray->plane.x;
	data->ray->plane.x = data->ray->plane.x * cos(-ROTATION_SPEED)
		- data->ray->plane.y * sin(-ROTATION_SPEED);
	data->ray->plane.y = player->old_plane_x * sin(-ROTATION_SPEED)
		+ data->ray->plane.y * cos(-ROTATION_SPEED);
}

void	rotate_left(t_data *data, t_player *player)
{
	player->dir_deg -= ROTATION_SPEED;
	if (player->dir_deg < 0)
		player->dir_deg += 359;
	player->old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cos(ROTATION_SPEED)
		- player->dir.y * sin(ROTATION_SPEED);
	player->dir.y = player->old_dir_x * sin(ROTATION_SPEED)
		+ player->dir.y * cos(ROTATION_SPEED);
	player->old_plane_x = data->ray->plane.x;
	data->ray->plane.x = data->ray->plane.x * cos(ROTATION_SPEED)
		- data->ray->plane.y * sin(ROTATION_SPEED);
	data->ray->plane.y = player->old_plane_x * sin(ROTATION_SPEED)
		+ data->ray->plane.y * cos(ROTATION_SPEED);
}
