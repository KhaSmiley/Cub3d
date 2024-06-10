/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:42:55 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/10 17:54:43 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	printf("Khalau World\n");

	static t_data data = {0};
	data.path = argv[1];
	data.nb_line = 0;
	if (argc == 2)
	{
		data.map_start = 0;
		data.nb_line = 0;
		data.len_max = 0;
		data.nb_player = 0;
		if (parsing(&data, argv[1]))
			return (0);
		print_arr(data.map);
		init_data(&data);
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
