/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_spaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:23:15 by kboulkri          #+#    #+#             */
/*   Updated: 2024/06/07 21:11:43 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char **ft_add_space_to_map(t_data *data)
{
    int i;
    // int x = 1;
    char **tab = NULL;

    i = 0;
    int x = 1;
    find_size_to_malloc_add_spaces(data);
    tab = ft_calloc(sizeof(char *), (data->nb_line + 3));
    tab[0] = malloc(sizeof(char) * (data->len_max + 1));
    ft_memset(tab[0], '2', data->len_max);
    tab[0][data->len_max] = '\0';
    while(data->map[i])
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
    tab[x] = NULL;
    free_tab(data->map);
    return (tab);
}
void find_size_to_malloc_add_spaces(t_data *data)
{
	int len;
	int i;
    
	i = data->map_start;
    data->len_max = 0;
	while(data->map[i])
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
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	find_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}