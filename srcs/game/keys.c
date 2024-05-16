/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:33:54 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/16 20:33:51 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// hook on function listening to key press
// set variable to 1 when key being pressed

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->mlx_win);
		mlx_destroy_display(data->mlx->mlx_ptr);
		free(data->mlx->mlx_ptr);
		exit(0);
	}
	// ft_printf("Keycode: %d\n", keycode);
	if (keycode == KEY_W)
		move_forwards(data->mlx, data->mlx->player);
	if (keycode == KEY_A)
		move_left(data->mlx, data->mlx->player);
	if (keycode == KEY_S)
		move_backwards(data->mlx, data->mlx->player);
	if (keycode == KEY_D)
		move_right(data->mlx, data->mlx->player);
	if (keycode == KEY_LEFT)
	{
		data->player->rot = -1;
		rotate_player(data->player);
	}
	if (keycode == KEY_RIGHT)
	{
		data->player->rot = 1;
		rotate_player(data->player);
	}
	return (1);
}

int	key_release(int keycode, t_mlx *mlx_struct)
{
	if (keycode == KEY_W)
		mlx_struct->player->f_b = 0;
	if (keycode == KEY_A)
		mlx_struct->player->l_r = 0;
	if (keycode == KEY_S)
		mlx_struct->player->f_b = 0;
	if (keycode == KEY_D)
		mlx_struct->player->l_r = 0;
	return (1);
}

// hook on function listening to key release
// set variable to 0 when key released

// swap images (?)
