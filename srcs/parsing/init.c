/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:43:07 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/14 17:51:58 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_ray(t_data *data)
{
	static t_ray	ray = {0};

	ray.ray_dir_deg = data->player->dir_deg;
	ray.plane.x = 0.66 * (data->player->dir.y);
	ray.plane.y = 0.66 * (-1 * data->player->dir.x);
	ray.map.x = (int)data->player->pos.x;
	ray.map.y = (int)data->player->pos.y;
	data->ray = &ray;
}

void	init_player(t_data *data)
{
	static t_player	player = {0};
	static t_keys	keys = {0};

	player.pos.x = data->start_pos.x + 0.5;
	player.pos.y = data->start_pos.y + 0.5;
	player.fov_rd = (FOV * M_PI) / 180;
	player.key_flags = &keys;
	data->player = &player;
	set_start_direction(data->player, data->player_dir);
}

void	init_data(t_data *data, char *arg)
{
	data->path = arg;
	data->nb_line = 0;
	data->map_start = 0;
	data->nb_line = 0;
	data->len_max = 0;
	data->nb_player = 0;
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
	mlx_struct.mlx_win = mlx_new_window(mlx_struct.mlx_ptr, S_W, S_H,
			"Khalau World");
	if (!mlx_struct.mlx_win)
	{
		ft_printf("mlx window creation failed\n");
		return ;
	}
	data->mlx = &mlx_struct;
}

void	init_textures(t_data *data)
{
	setup_textures(data);
	setup_screen_buffer(data->mlx);
}
