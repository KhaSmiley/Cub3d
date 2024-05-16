/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:42:55 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/16 17:10:24 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	static t_data data = {0};

	printf("Khalau World\n");
	if (argc == 2)
	{
		printf("maths :) %2.6f\n", deg_to_rad(96));
		printf("maths :) %d\n", rad_to_deg(1.67552));
		if (init_data(&data))
			return (0);
		if (parsing(&data, argv[1]))
			return (0);
		init_player(&data);
		print_arr(data.map);
		init_game(&data);
		play_game(&data);
		free_tab(data.map);
	}
	else
		ft_printf("Error number of args\n");
	return (0);
}
