/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:42:55 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/07 21:17:27 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	static t_data data = {0};

	printf("Khalau World\n");
	data.path = argv[1];
	if (argc == 2)
	{
		if (init_data(&data))
			return (0);
		if (parsing(&data, argv[1]))
			return (0);
		printf("%d\n", data.rgb_c);
		printf("%d\n", data.rgb_f);
		// init_player(&data);
		// print_arr(data.map);
		// init_game(&data);
		free_tab(data.info);
		free_tab(data.map);
	}
	else
		ft_printf("Error number of args\n");
	return (0);
}
