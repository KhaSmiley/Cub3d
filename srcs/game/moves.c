/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:42:29 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/19 00:32:45 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// field of vision rotate right (left arrow)
// field of vision rotate left (right arrow)

// move right / left (D or A key)
// move forwards / backwards (W or S key)

void	move_forwards(t_mlx *mlx_struct, t_player *player)
{
		player->player_y -= PLAYER_SPEED;
		put_player(mlx_struct->mlx_ptr, mlx_struct->mlx_win, player->player_x, player->player_y);
}

void	move_backwards(t_mlx *mlx_struct, t_player *player)
{
		player->player_y += PLAYER_SPEED;
		put_player(mlx_struct->mlx_ptr, mlx_struct->mlx_win, player->player_x, player->player_y);
}

void	move_left(t_mlx *mlx_struct, t_player *player)
{
		player->player_x -= PLAYER_SPEED;
		put_player(mlx_struct->mlx_ptr, mlx_struct->mlx_win, player->player_x, player->player_y);
}

void	move_right(t_mlx *mlx_struct, t_player *player)
{
		player->player_x += PLAYER_SPEED;
		put_player(mlx_struct->mlx_ptr, mlx_struct->mlx_win, player->player_x, player->player_y);
}

// calculating in degrees
void	rotate_player(t_player *player)
{
	if (player->rot == 1) // right
	{
		player->direction += ROTATION_SPEED;
		if (player->direction > 359)
			player->direction -= 359;
		ft_printf("%srotating right%s\n", RED, RESET);
	}
	else if (player->rot == -1) // left
	{
		player->direction -= ROTATION_SPEED;
		if (player->direction < 0)
			player->direction += 359;
		ft_printf("%srotating left%s\n", BLUE, RESET);
	}
	printf("%splayer direction = %f%s\n",BGREEN,  player->direction, RESET);
}

