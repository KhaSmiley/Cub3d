/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:43:07 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/06 17:42:46 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_ray(t_data *data)
{
	static t_ray	ray = {0};

	ray.ray_dir_deg = data->player->dir_deg;
	ray.next_step.x = 0; //cos(deg_to_rad(ray.ray_dir));
	ray.next_step.y = 0; //sin(deg_to_rad(ray.ray_dir));

	// check this
	ray.plane.x = 0.66;
	ray.plane.y = 0;

	// step size
	// draw len
	ray.distance_to_wall = 0;
	data->ray = &ray;
}
 void	init_player(t_data *data)
{
	static t_player	player = {0};

	player.fov_rd = (FOV * M_PI) / 180;
	player.rot = 0;
	player.l_r = 0;
	player.f_b = 0;
	player.pos.x = data->start_pos.x + 0.5;
	player.pos.y = data->start_pos.y + 0.5;
	data->player = &player;
	set_start_direction(data->player, data->player_dir);
	ft_memset(&data->player->key_flags, 0, sizeof(t_keys));
}

void	init_data(t_data *data)
{
	get_map_width_height(data);
	set_player_start_position(data);
	ft_printf("%sPlayer start position: x = %d, y = %d, direction = %c%s\n", IBLUE, data->start_pos.x, data->start_pos.y, data->player_dir, RESET);
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
	put_player(mlx_struct->mlx_ptr, mlx_struct->mlx_win, data->player->pos.x, data->player->pos.y);
}
