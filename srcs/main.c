/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:42:55 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/14 21:50:16 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	static t_data	data = {0};

	if (argc == 2)
	{
		init_data(&data, argv[1]);
		if (parsing(&data, argv[1]))
			return (0);
		print_arr(data.map);
		get_map_width_height(&data);
		set_player_start_position(&data);
		init_player(&data);
		init_ray(&data);
		init_mlx(&data);
		init_textures(&data);
		play_game(&data);
	}
	else
		ft_printf("Error: One map required\n");
	return (0);
}
