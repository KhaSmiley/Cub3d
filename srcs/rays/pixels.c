/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:12:14 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/08 17:47:43 by lbarry           ###   ########.fr       */
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
void	mlx_put_background(t_mlx *mlx_struct)
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
	//mlx_background(&mlx_struct);
	mlx_struct->bckgrd_ptr = mlx_xpm_file_to_image(mlx_struct->mlx_ptr, "./textures/khalidou.xpm", &i, &j);
	mlx_put_image_to_window(mlx_struct->mlx_ptr, mlx_struct->mlx_win, mlx_struct->bckgrd_ptr, (0 + S_W / 2) - (835 / 2), (0 + S_H / 2) - (626 / 2));
}
