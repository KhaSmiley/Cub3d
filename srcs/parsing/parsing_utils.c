/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:22:09 by kboulkri          #+#    #+#             */
/*   Updated: 2024/06/13 23:49:26 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

size_t	ft_strlen_until_char(char *str, char c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	check_extension(char *argv)
{
	int	i;

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

int	invalid_char_in_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (ft_strchr("0NEWS1 ", data->map[i][j]) == NULL)
			{
				ft_printf("Error\nWrong char in map\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
int	invalid_nb_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (ft_strchr("NEWS", data->map[i][j]))
				data->nb_player++;
			j++;
		}
		i++;
	}
	if (data->nb_player != 1)
	{
		ft_printf("Error\nWrong number of player\n");
		return (1);
	}
	return (0);
}

void ft_del_newline(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->texture[i])
    {
        j = 0;
        while (data->texture[i][j])
        {
            if (data->texture[i][j] == '\n')
                data->texture[i][j] = '\0';
            j++;
        }
        i++;
    }
    i = 0;
    while (data->color[i])
    {
        j = 0;
        while (data->color[i][j])
        {
            if (data->color[i][j] == '\n')
                data->color[i][j] = '\0';
            j++;
        }
        i++;
    }
}
