/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:42:55 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/13 22:01:01 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	printf("Khalau World\n");

	static t_data data = {0};
	if (argc == 2)
	{
		init_data(&data, argv[1]);
		if (parsing(&data, argv[1]))
			return (0);
		print_arr(data.map);
		get_map_width_height(&data);
		set_player_start_position(&data);
		ft_printf("%sPlayer start position: y = %d, x = %d direction = %c%s\n", BLUE, data.start_pos.x, data.start_pos.y, data.player_dir, RESET);
		ft_printf("%sMap width = %d, height = %d%s\n", MAGENTA, data.w_map, data.h_map, RESET);
		init_player(&data);
		init_ray(&data);
		init_mlx(&data);
		init_textures(&data);
		play_game(&data);
	}
	else
		ft_printf("Error number of args\n");
	return (0);
}
