/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:43:07 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/08 17:34:26 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// (lines 25/26) By adding half of the tile size to the calculated positions, the player is placed at the center of the tile,
// which is a common convention in tile-based games. This positioning ensures smoother movement and collision detection.
void	init_player(t_data *data)
{
	static t_player	player = {0};

	set_player_start_position(data);
	ft_printf("Player start position: x = %d, y = %d, direction = %c\n", data->start_x, data->start_y, data->player_dir);
	get_map_width_height(data);
	ft_printf("Map width = %d, height = %d\n", data->w_map, data->h_map);
	player.player_x = data->start_x * TILE_SIZE + TILE_SIZE / 2;
	player.player_y = data->start_y * TILE_SIZE + TILE_SIZE / 2;
	data->player = &player;
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

void	init_game(t_data *data)
{
	static t_mlx	mlx_struct = {0};

	data->mlx = &mlx_struct;
	mlx_struct.player = data->player;
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
	img_background(&mlx_struct);
	mlx_rectangle_put(mlx_struct.mlx_ptr, mlx_struct.mlx_win, data->player->player_x, data->player->player_y);
	// mlx_loop_hook(mlx.mlx_p, &game_loop, &mlx); // game loop continuously call a specified function to update the game state and render the frames.
 	mlx_hook(mlx_struct.mlx_win, 2, 1L << 0, &key_press, &mlx_struct); // key press
	mlx_hook(data->mlx->mlx_win, 3, 1L << 1, &key_release, &mlx_struct); // key release
	mlx_loop(mlx_struct.mlx_ptr);

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
