/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:10:37 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/10 15:17:00 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	play_game(t_data *data)
{
	mlx_hook(data->mlx->mlx_win, 2, 1L << 0, &key_press, data->mlx);
	mlx_hook(data->mlx->mlx_win, 3, 1L << 1, &key_release, data->mlx);
	mlx_hook(data->mlx->mlx_win, DestroyNotify, StructureNotifyMask, &on_destroy, data);
	mlx_loop_hook(data->mlx->mlx_ptr, &move_rotate, data);
	mlx_loop(data->mlx->mlx_ptr);
}
