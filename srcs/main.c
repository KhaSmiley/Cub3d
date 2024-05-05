/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:42:55 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/06 00:38:00 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	static t_data data = {0};

	printf("Khalau World\n");
	if (argc == 2)
	{
		if (init_data(&data))
			return (0);
		if (parsing(&data, argv[1]))
			return (0);
		print_arr(data.map);
		free_tab(data.map);
	}
	else
		ft_printf("Error number of args\n");
	return (0);
}
