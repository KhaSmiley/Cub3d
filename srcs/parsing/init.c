/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:43:07 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/06 21:55:33 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_player(t_data *data)
{
	set_player_start_position(data);
	ft_printf("Player start position: x = %d, y = %d, direction = %c\n", data->start_x, data->start_y, data->player_dir);
	get_map_width_height(data);
	ft_printf("Map width = %d, height = %d\n", data->w_map, data->h_map);
}

void	set_player_start_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->nb_line)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				data->start_x = j;
				data->start_y = i;
				data->player_dir = data->map[i][j];
				return ;
			}
			j++;
		}
		i++;
	}
}

void	get_map_width_height(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->w_map = 0;
	data->h_map = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
			j++;
		if (j > data->w_map)
			data->w_map = j;
		i++;
	}
	data->h_map = i;
}

int	init_data(t_data *data)
{
	data->nb_line = 0;
	return (0);
}

void	init_window(t_data *data)
{
	static t_mlx	mlx_struct = {0};

	mlx_struct.data = data;
	mlx_struct.mlx_ptr = mlx_init();
	if (!mlx_struct.mlx_ptr)
	{
		ft_printf("mlx ptr creation failed\n");
		return ;
	}
	mlx_struct.mlx_win = mlx_new_window(mlx_struct.mlx_ptr, S_W, S_H, "Cub3D");
	if (!mlx_struct.mlx_win)
	{
		ft_printf("mlx window creation failed\n");
		return ;
	}
}

// void	init_mlx(t_data *data)
// {
// 	static t_mlx	mlx_struct = {0};

// 	mlx->struct.mlx_ptr = mlx_init();
// 	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, S_W, S_H);
// 	mlx.dt = data;
// 	mlx.ply = malloc(sizeof(t_player));
// 	mlx.ray = malloc(sizeof(t_ray));
// 	mlx.ply->player_x = data->start_x * TILE_SIZE + TILE_SIZE / 2;
// 	mlx.ply->player_y = data->start_y * TILE_SIZE + TILE_SIZE / 2;
// 	mlx.ply->angle = 0;
// 	// mlx.ply->fov_rd = FOV * M_PI / 180;
// 	mlx.ply->rot = 0;
// 	mlx.ply->l_r = 0;
// 	mlx.ply->u_d = 0;
// 	mlx.ray->ray_ngl = 0;
// 	mlx.ray->distance = 0;
// 	mlx.ray->flag = 0;
// 	// mlx_hook(mlx.win, 2, 1L << 0, key_hook, &mlx);
// 	// mlx_hook(mlx.win, 17, 1L << 17, close_win, &mlx);
// 	// mlx_loop_hook(mlx.mlx_ptr, draw, &mlx);
// 	mlx_loop(mlx.mlx_ptr);
// }
