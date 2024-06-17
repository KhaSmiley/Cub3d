/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_spaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:23:15 by kboulkri          #+#    #+#             */
/*   Updated: 2024/06/14 21:47:22 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**ft_add_space_to_map(t_data *data)
{
	int		i;
	int		x;
	char	**tab;

	i = 0;
	x = 1;
	find_size_to_malloc_add_spaces(data);
	tab = ft_calloc(sizeof(char *), (data->nb_line + 3));
	tab[0] = malloc(sizeof(char) * (data->len_max + 1));
	ft_memset(tab[0], '2', data->len_max);
	tab[0][data->len_max] = '\0';
	while (data->map[i])
	{
		tab[x] = malloc(sizeof(char) * (data->len_max + 1));
		ft_memset(tab[x], '2', data->len_max);
		tab[x][data->len_max] = '\0';
		ft_strcpy_cube(&tab[x][1], data->map[i]);
		i++;
		x++;
	}
	tab[x] = malloc(sizeof(char) * (data->len_max + 1));
	ft_memset(tab[x], '2', data->len_max);
	tab[x][data->len_max] = '\0';
	x++;
	return (tab[x] = NULL, free_tab(data->map), tab);
}

void	find_size_to_malloc_add_spaces(t_data *data)
{
	int	len;
	int	i;

	i = data->map_start;
	data->len_max = 0;
	while (data->map[i])
	{
		len = ft_strlen(data->map[i]);
		if (len > data->len_max)
			data->len_max = len;
		i++;
	}
	data->len_max += 2;
}

char	*ft_strcpy_cube(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	ft_del_newline(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->texture[++i])
	{
		j = 0;
		while (data->texture[i][j])
		{
			if (data->texture[i][j] == '\n')
				data->texture[i][j] = '\0';
			j++;
		}
	}
	i = -1;
	while (data->color[++i])
	{
		j = 0;
		while (data->color[i][j])
		{
			if (data->color[i][j] == '\n')
				data->color[i][j] = '\0';
			j++;
		}
	}
}

int	check_end_map(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n')
		{
			free(line);
			continue ;
		}
		else
			return (free(line), 1);
	}
	free(line);
	return (0);
}
