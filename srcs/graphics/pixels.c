/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:12:14 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/14 18:45:48 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
void	put_line(t_data *data, int x, int y1, int y2, int colour)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(data->mlx->mlx_ptr, data->mlx->mlx_win, x, y, colour);
		y++;
	}
}
*/

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

void	put_player(void *mlx_ptr, void *win_ptr, double x, double y)
{
	double	i;
	double	j;

	i = x;
	while (i < x + 8)
	{
		j = y;
		while (j < y + 8)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0x00FF6600);
			j++;
		}
		i++;
	}
}

void	img_background(t_mlx *mlx_struct)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_struct->bckgrd_ptr = mlx_xpm_file_to_image(mlx_struct->mlx_ptr,
			"./textures/khalidou.xpm", &i, &j);
	if (!mlx_struct->bckgrd_ptr)
	{
		ft_printf("failed to load image\n");
		return ;
	}
}

// imagining a unit circle (radius = 1 unit) with the player in the center
// we use pythag to repeatedly calculate the x and
// y coordinates of the edge of the circle
// applying cos to the angle gives us the x coordinate for the pixel
// applying sin to the angle gives us the y coordinate for the pixel
void	display_circle(t_mlx *mlx)
{
	int		angle;
	int		distance;
	float	x;
	float	y;

	angle = 0;
	distance = 50;
	x = mlx->player->pos.x + cos(angle) * 10;
	y = mlx->player->pos.y + sin(angle) * 10;
	while (angle < 360)
	{
		x = mlx->player->pos.x + cos(angle) * distance;
		y = mlx->player->pos.y + sin(angle) * distance;
		mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, x, y, 0x00FF0000);
		angle++;
	}
}
