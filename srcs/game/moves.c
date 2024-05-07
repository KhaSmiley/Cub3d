/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:42:29 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/08 00:53:49 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// field of vision rotate right (left arrow)
// field of vision rotate left (right arrow)

// move right / left (D or A key)
// move forwards / backwards (W or S key)

void	move_forwards(t_mlx *mlx_struct, t_player *player)
{
	player->f_b = 1;
	ft_printf("moving forwards\n");
	if (player->f_b == 1)
	{
		player->player_y -= 10;
		mlx_rectangle_put(mlx_struct->mlx_ptr, mlx_struct->mlx_win, player->player_x, player->player_y);
	}
}

void	move_backwards(t_mlx *mlx_struct, t_player *player)
{
	player->f_b = 1;
	if (player->f_b == 1)
	ft_printf("moving backwards\n");
	{
		player->player_y += 10;
		mlx_rectangle_put(mlx_struct->mlx_ptr, mlx_struct->mlx_win, player->player_x, player->player_y);
	}
}

void	move_left(t_mlx *mlx_struct, t_player *player)
{
	player->l_r = 1;
	ft_printf("moving left\n");
	if (player->l_r == 1)
	{
		player->player_x -= 10;
		mlx_rectangle_put(mlx_struct->mlx_ptr, mlx_struct->mlx_win, player->player_x, player->player_y);
	}
}

void	move_right(t_mlx *mlx_struct, t_player *player)
{
	player->l_r = 1;
	ft_printf("moving right\n");
	if (player->l_r == 1)
	{
		player->player_x += 10;
		mlx_rectangle_put(mlx_struct->mlx_ptr, mlx_struct->mlx_win, player->player_x, player->player_y);
	}
}

