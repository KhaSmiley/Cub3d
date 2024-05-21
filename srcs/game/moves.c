/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:42:29 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/21 00:38:30 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// field of vision rotate right (left arrow)
// field of vision rotate left (right arrow)

// move right / left (D or A key)
// move forwards / backwards (W or S key)

void	move_forwards(t_mlx *mlx_struct, t_data *data, t_player *player)
{
	if (data->map[(int)(player->player_y - PLAYER_SPEED) / TILE_SIZE][(int)player->player_x / TILE_SIZE] == '1')
		return ;
	if (player->player_y - PLAYER_SPEED < 0)
		return ;
	player->player_y -= PLAYER_SPEED;
	put_player(mlx_struct->mlx_ptr, mlx_struct->mlx_win, player->player_x, player->player_y);
	printf("%splayer_y = %f%s\n", BRED, player->player_y, RESET);
}

void	move_backwards(t_mlx *mlx_struct, t_data *data, t_player *player)
{
	if (data->map[(int)(player->player_y + 7 + PLAYER_SPEED) / TILE_SIZE][(int)player->player_x / TILE_SIZE] == '1')
		return ;
	if (player->player_y + PLAYER_SPEED > S_H)
		return ;
	player->player_y += PLAYER_SPEED;
	put_player(mlx_struct->mlx_ptr, mlx_struct->mlx_win, player->player_x, player->player_y);
	printf("%splayer_y = %f%s\n", BBLUE, player->player_y, RESET);
}

void	move_left(t_mlx *mlx_struct, t_data *data, t_player *player)
{
	if (data->map[(int)player->player_y / TILE_SIZE][(int)(player->player_x - PLAYER_SPEED) / TILE_SIZE] == '1')
		return ;
	if (player->player_x - PLAYER_SPEED < 0)
		return ;
	player->player_x -= PLAYER_SPEED;
	put_player(mlx_struct->mlx_ptr, mlx_struct->mlx_win, player->player_x, player->player_y);
	printf("%splayer_x = %f%s\n", BGREEN, player->player_x, RESET);
}

void	move_right(t_mlx *mlx_struct, t_data *data, t_player *player)
{
	if (data->map[(int)player->player_y / TILE_SIZE][(int)(player->player_x + 7 + PLAYER_SPEED) / TILE_SIZE] == '1')
		return ;
	if (player->player_x + PLAYER_SPEED > S_W)
		return ;
	player->player_x += PLAYER_SPEED;
	put_player(mlx_struct->mlx_ptr, mlx_struct->mlx_win, player->player_x, player->player_y);
	printf("%splayer_x = %f%s\n", BYELLOW, player->player_x, RESET);
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
