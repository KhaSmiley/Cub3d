/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:22:09 by kboulkri          #+#    #+#             */
/*   Updated: 2024/04/25 23:25:28 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

size_t	ft_strlen_until_char(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	check_extension(char *argv)
{
	int i;

	i = 0;
	while (argv[i] != '\0')
	{
		i++;
	}
	i--;
	if (argv[i] == 'b')
	{
		i--;
		if (argv[i] == 'u')
		{
			i--;
			if (argv[i] == 'c')
			{
				i--;
				if (argv[i] == '.')
					return (TRUE);
			}
		}
	}
	ft_printf("Error\nWrong extension\n");
	return (FALSE);
}