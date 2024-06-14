/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:43:07 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/14 00:25:20 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_ray(t_data *data)
{
	static t_ray	ray = {0};

	ray.ray_dir_deg = data->player->dir_deg;
	// check this
	ray.ray_dir.x = 0;
	ray.ray_dir.y = 0;
	// check this
	ray.plane.x = 0.66 * (data->player->dir.y);
	ray.plane.y = 0.66 * (-1 * data->player->dir.x);
	ray.next_step.x = 0; // cos(deg_to_rad(ray.ray_dir));
	ray.next_step.y = 0; // sin(deg_to_rad(ray.ray_dir));
	ray.distance_to_wall = 0;
	ray.map.x = (int)data->player->pos.x;
	ray.map.y = (int)data->player->pos.y;
	ray.step_flag.x = 0;
	ray.step_flag.y = 0;
	ray.texture = 0;
	ray.wall_len = 0;
	ray.draw_start = 0;
	ray.draw_end = 0;
	ray.text_pos = 0;
	ray.text_step = 0;
	ray.text_coord.x = 0;
	ray.text_coord.y = 0;
	ray.wall_x = 0;
	data->ray = &ray;
}

void	init_player(t_data *data)
{
	static t_player	player = {0};
	static t_keys	keys = {0};

	player.pos.x = data->start_pos.x + 0.5;
	player.pos.y = data->start_pos.y + 0.5;
	player.fov_rd = (FOV * M_PI) / 180;
	player.rot = 0;
	player.l_r = 0;
	player.f_b = 0;
	player.key_flags = &keys;
	data->player = &player;
	set_start_direction(data->player, data->player_dir);
}

void	init_data(t_data *data)
{
	get_map_width_height(data);
	set_player_start_position(data);
	ft_printf("%sPlayer start position: y = %d, x = %d direction = %c%s\n",
		BLUE, data->start_pos.x, data->start_pos.y, data->player_dir, RESET);
	ft_printf("%sMap width = %d, height = %d%s\n", MAGENTA, data->w_map,
		data->h_map, RESET);
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
	setup_screen_buffer(data);
}
