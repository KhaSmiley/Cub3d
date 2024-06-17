/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:10:37 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/17 17:12:45 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	mouse_move(int x, int y, t_data *data)
{
	double		diff_x;
	double		diff_y;
	static int	centre_x = S_W / 2;
	static int	centre_y = S_H / 2;

	if (data->player->key_flags->ctrl == 0)
		return (0);
	diff_x = x - centre_x;
	diff_y = y - centre_y;
	if (diff_x > 0 || (diff_x == 0 && x == S_W - 1))
		rotate_left(data, data->player);
	else if (diff_x < 0 || (diff_x == 0 && x == 0))
		rotate_right(data, data->player);
	return (1);
}

void	play_game(t_data *data)
{
	mlx_hook(data->mlx->mlx_win, 2, 1L << 0, &key_press, data->mlx);
	mlx_hook(data->mlx->mlx_win, 3, 1L << 1, &key_release, data->mlx);
	mlx_hook(data->mlx->mlx_win, DestroyNotify, StructureNotifyMask,
		&on_destroy, data);
	mlx_loop_hook(data->mlx->mlx_ptr, &move_rotate, data);
	mlx_hook(data->mlx->mlx_win, MotionNotify, PointerMotionMask,
		&mouse_move, data);
	mlx_loop(data->mlx->mlx_ptr);
}
