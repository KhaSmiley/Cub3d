/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:12:14 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/06 20:25:46 by lbarry           ###   ########.fr       */
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
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
}
