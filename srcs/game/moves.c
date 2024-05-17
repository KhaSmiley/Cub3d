/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:42:29 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/17 20:48:37 by lbarry           ###   ########.fr       */
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
		player->player_y -= 2.5;
		put_player(mlx_struct->mlx_ptr, mlx_struct->mlx_win, player->player_x, player->player_y);
	}
}

void	move_backwards(t_mlx *mlx_struct, t_player *player)
{
	player->f_b = 1;
	if (player->f_b == 1)
	ft_printf("moving backwards\n");
	{
		player->player_y += 2.5;
		put_player(mlx_struct->mlx_ptr, mlx_struct->mlx_win, player->player_x, player->player_y);
	}
}

void	move_left(t_mlx *mlx_struct, t_player *player)
{
	player->l_r = 1;
	ft_printf("moving left\n");
	if (player->l_r == 1)
	{
		player->player_x -= 2.5;
		put_player(mlx_struct->mlx_ptr, mlx_struct->mlx_win, player->player_x, player->player_y);
	}
}

void	move_right(t_mlx *mlx_struct, t_player *player)
{
	player->l_r = 1;
	ft_printf("moving right\n");
	if (player->l_r == 1)
	{
		player->player_x += 2.5;
		put_player(mlx_struct->mlx_ptr, mlx_struct->mlx_win, player->player_x, player->player_y);
	}
}

// calculating in degrees
void	rotate_player(t_player *player)
{
	if (player->rot == 1) // right
	{
		player->direction += ROTATION_SPEED;
		if (player->direction > 359)
			player->direction -= 359;
		ft_printf("rotating right\n");
		printf("player direction = %f\n", player->direction);
	}
	else if (player->rot == -1) // left
	{
		player->direction -= ROTATION_SPEED;
		if (player->direction < 0)
			player->direction += 359;
		ft_printf("rotating left\n");
		printf("player direction = %f\n", player->direction);
	}
}

