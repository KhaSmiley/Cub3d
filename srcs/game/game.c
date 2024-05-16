/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:10:37 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/16 19:54:27 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	play_game(t_data *data)
{
	mlx_loop_hook(data->mlx->mlx_ptr, &cast_rays, data); // game loop continuously call a specified function to update the game state and render the frames.
	mlx_hook(data->mlx->mlx_win, 2, 1L << 0, &key_press, data); // key press
	mlx_hook(data->mlx->mlx_win, 3, 1L << 1, &key_release, data->mlx); // key release
	mlx_loop(data->mlx->mlx_ptr);
}
