/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:33:54 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/21 00:22:09 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// hook on function listening to key press
// set variable to 1 when key being pressed

int	key_press_castrays(t_data *data)
{

	// mlx_clear_window(data->mlx->mlx_ptr, data->mlx->mlx_win);
	// img_background(data->mlx);
	// display_map(data);
	cast_rays(data);
	if (data->mlx->player->w == 1)
		move_forwards(data->mlx, data, data->mlx->player);
	if (data->mlx->player->a == 1)
		move_left(data->mlx, data, data->mlx->player);
	if (data->mlx->player->s == 1)
		move_backwards(data->mlx, data, data->mlx->player);
	if (data->mlx->player->d == 1)
		move_right(data->mlx, data, data->mlx->player);
	if (data->mlx->player->left == 1)
	{
		data->mlx->player->rot = -1;
		rotate_player(data->mlx->player);
	}
	if (data->mlx->player->right == 1)
	{
		data->mlx->player->rot = 1;
		rotate_player(data->mlx->player);
	}
	if (data->mlx->player->esc == 1 || data->mlx->player->q == 1)
	{
		mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->mlx_win);
		mlx_destroy_display(data->mlx->mlx_ptr);
		free(data->mlx->mlx_ptr);
		exit(0);
	}
	return (1);
}


int	key_press(int keycode, t_mlx *mlx_struct)
{
	if (keycode == KEY_W)
		mlx_struct->player->w = 1;
	if (keycode == KEY_A)
		mlx_struct->player->a = 1;
	if (keycode == KEY_S)
		mlx_struct->player->s = 1;
	if (keycode == KEY_D)
		mlx_struct->player->d = 1;
	if (keycode == KEY_LEFT)
		mlx_struct->player->left = 1;
	if (keycode == KEY_RIGHT)
		mlx_struct->player->right = 1;
	if (keycode == KEY_ESC)
		mlx_struct->player->esc = 1;
	return (1);
}

int	key_release(int keycode, t_mlx *mlx_struct)
{
	if (keycode == KEY_W)
		mlx_struct->player->w = 0;
	if (keycode == KEY_A)
		mlx_struct->player->a = 0;
	if (keycode == KEY_S)
		mlx_struct->player->s = 0;
	if (keycode == KEY_D)
		mlx_struct->player->d = 0;
	if (keycode == KEY_LEFT)
		mlx_struct->player->left = 0;
	if (keycode == KEY_RIGHT)
		mlx_struct->player->right = 0;
	if (keycode == KEY_ESC)
		mlx_struct->player->esc = 0;
	return (1);
}

// hook on function listening to key release
// set variable to 0 when key released

// swap images (?)
