/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:12:14 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/08 00:52:51 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	mlx_rectangle_put(void *mlx_ptr, void *win_ptr, int x, int y)
{
	int	i;
	int	j;

	i = x;
	while (i < x + 8)
	{
		j = y;
		while (j < y + 8)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0x00CCFFCC);
			j++;
		}
		i++;
	}
}
// lol this is a homemade function which is satisfying but completely useless
void	mlx_background(t_mlx *mlx_struct)
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
