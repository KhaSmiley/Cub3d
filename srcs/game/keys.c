/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:33:54 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/08 00:49:43 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// hook on function listening to key press
// set variable to 1 when key being pressed

int	key_press(int keycode, t_mlx *mlx_struct)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(mlx_struct->mlx_ptr, mlx_struct->mlx_win);
		mlx_destroy_display(mlx_struct->mlx_ptr);
		free(mlx_struct->mlx_ptr);
		exit(0);
	}
	// ft_printf("Keycode: %d\n", keycode);
	if (keycode == KEY_W)
		move_forwards(mlx_struct, mlx_struct->player);
	if (keycode == KEY_A)
		move_left(mlx_struct, mlx_struct->player);
	if (keycode == KEY_S)
		move_backwards(mlx_struct, mlx_struct->player);
	if (keycode == KEY_D)
		move_right(mlx_struct, mlx_struct->player);
	if (keycode == KEY_LEFT)
		ft_printf("look left\n");
	if (keycode == KEY_RIGHT)
		ft_printf("look right\n");
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
