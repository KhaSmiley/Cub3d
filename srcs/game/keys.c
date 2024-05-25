/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:33:54 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/25 19:29:24 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// hook on function listening to key press
// set variable to 1 when key being pressed

int	move_rotate(t_data *data)
{
	if (data->player->key_flags.w == 1)
		move_forwards(data->mlx, data, data->mlx->player);
	if (data->player->key_flags.a == 1)
		move_left(data->mlx, data, data->mlx->player);
	if (data->player->key_flags.s == 1)
		move_backwards(data->mlx, data, data->mlx->player);
	if (data->player->key_flags.d == 1)
		move_right(data->mlx, data, data->mlx->player);
	if (data->player->key_flags.left == 1)
	{
		data->player->rot = -1;
		rotate_player(data->mlx->player);
	}
	if (data->player->key_flags.right == 1)
	{
		data->player->rot = 1;
		rotate_player(data->mlx->player);
	}
	if (data->player->key_flags.esc == 1)
	{
		mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->mlx_win);
		mlx_destroy_display(data->mlx->mlx_ptr);
		free(data->mlx->mlx_ptr);
		exit(0);
	}
	calculations(data);
	return (1);
}


int	key_press(int keycode, t_mlx *mlx_struct)
{
	if (keycode == KEY_W)
		mlx_struct->player->key_flags.w = 1;
	if (keycode == KEY_A)
		mlx_struct->player->key_flags.a = 1;
	if (keycode == KEY_S)
		mlx_struct->player->key_flags.s = 1;
	if (keycode == KEY_D)
		mlx_struct->player->key_flags.d = 1;
	if (keycode == KEY_LEFT)
		mlx_struct->player->key_flags.left = 1;
	if (keycode == KEY_RIGHT)
		mlx_struct->player->key_flags.right = 1;
	if (keycode == KEY_ESC)
		mlx_struct->player->key_flags.esc = 1;
	return (1);
}

int	key_release(int keycode, t_mlx *mlx_struct)
{
	if (keycode == KEY_W)
		mlx_struct->player->key_flags.w = 0;
	if (keycode == KEY_A)
		mlx_struct->player->key_flags.a = 0;
	if (keycode == KEY_S)
		mlx_struct->player->key_flags.s = 0;
	if (keycode == KEY_D)
		mlx_struct->player->key_flags.d = 0;
	if (keycode == KEY_LEFT)
		mlx_struct->player->key_flags.left = 0;
	if (keycode == KEY_RIGHT)
		mlx_struct->player->key_flags.right = 0;
	if (keycode == KEY_ESC)
		mlx_struct->player->key_flags.esc = 0;
	return (1);
}

// hook on function listening to key release
// set variable to 0 when key released

// swap images (?)
