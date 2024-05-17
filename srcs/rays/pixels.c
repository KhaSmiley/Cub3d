/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:12:14 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/17 20:50:11 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_tiles(void *mlx_ptr, void *win_ptr, int x, int y)
{
	int	i;
	int	j;

	i = x;
	while (i < x + TILE_SIZE)
	{
		j = y;
		while (j < y + TILE_SIZE)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0x00CCFFCC);
			j++;
		}
		i++;
	}
}

void	put_player(void *mlx_ptr, void *win_ptr, int x, int y)
{
	int	i;
	int	j;

	i = x;
	while (i < x + 8)
	{
		j = y;
		while (j < y + 8)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0x00CCFF00);
			j++;
		}
		i++;
	}
}
// lol this is a homemade function which is satisfying but completely useless
void	put_background(t_mlx *mlx_struct)
{
	int	i;
	int	j;

	i = 0;
	while (i < S_W)
	{
		j = 0;
		while (j < S_W)
		{
			mlx_pixel_put(mlx_struct->mlx_ptr, mlx_struct->mlx_win, i, j, 0x000FCCFF);
			j++;
		}
		i++;
	}
}

void	img_background(t_mlx *mlx_struct)
{
	int i = 0;
	int j = 0;
	mlx_struct->bckgrd_ptr = mlx_xpm_file_to_image(mlx_struct->mlx_ptr, "./textures/khalidou.xpm", &i, &j);
}

// imagining a unit circle (radius = 1 unit) with the player in the center
// we use pythag to repeatedly calculate the x and y coordinates of the edge of the circle
// applying cos to the angle gives us the x coordinate for the pixel
// applying sin to the angle gives us the y coordinate for the pixel
void	display_circle(t_mlx *mlx)
{
	int	angle = 0;
	int	distance = 50;
	float x;
	float y;

	x = mlx->player->player_x + cos(angle) * 10;
	y = mlx->player->player_y + sin(angle) * 10;

	while (angle < 360)
	{
		x = mlx->player->player_x + cos(angle) * distance;
		y = mlx->player->player_y + sin(angle) * distance;
		mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, x, y, 0x00FF0000);
		angle++;
	}
}
