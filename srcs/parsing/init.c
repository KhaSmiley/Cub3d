/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:43:07 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/19 01:27:21 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_ray(t_data *data)
{
	static t_ray	ray = {0};

	ray.ray_dir = data->player->direction;
	ray.distance_to_wall = 0;
	ray.flag = 0;
	data->ray = &ray;
}

// (lines 25/26) By adding half of the tile size to the calculated positions, the player is placed at the center of the tile,
// which is a common convention in tile-based games. This positioning ensures smoother movement and collision detection.
void	init_player(t_data *data)
{
	static t_player	player = {0};

	player.player_x = data->start_x * TILE_SIZE + TILE_SIZE / 2;
	player.player_y = data->start_y * TILE_SIZE + TILE_SIZE / 2;
	player.fov_rd = (FOV * M_PI) / 180;
	player.rot = 0;
	player.l_r = 0;
	player.f_b = 0;
	data->player = &player;
	set_start_direction(data->player, data->player_dir);
}

void	set_start_direction(t_player *player, char dir)
{
	if (dir == 'N')
		player->direction = 90;
	else if (dir == 'S')
		player->direction = 270;
	else if (dir == 'W')
		player->direction = 180;
	else if (dir == 'E')
		player->direction = 0;
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
void	display_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				put_tiles(data->mlx->mlx_ptr, data->mlx->mlx_win, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	init_data(t_data *data)
{
	get_map_width_height(data);
	set_player_start_position(data);
	ft_printf("%sPlayer start position: x = %d, y = %d, direction = %c%s\n", IBLUE, data->start_x, data->start_y, data->player_dir, RESET);
	ft_printf("%sMap width = %d, height = %d%s\n", IMAGENTA, data->w_map, data->h_map, RESET);
	// floor_colour;
	// ceiling_colour;
	// north texture
	// south texture
	// west texture
	// east texture;
}

void	init_mlx(t_data *data)
{
	static t_mlx	mlx_struct = {0};

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
	data->mlx = &mlx_struct;
}

void	init_game(t_data *data, t_mlx *mlx_struct)
{
	mlx_put_image_to_window(mlx_struct->mlx_ptr, mlx_struct->mlx_win, mlx_struct->bckgrd_ptr, (0 + S_W / 2) - (835 / 2), (0 + S_H / 2) - (626 / 2));
	display_map(data);
	put_player(mlx_struct->mlx_ptr, mlx_struct->mlx_win, data->player->player_x, data->player->player_y);
}
