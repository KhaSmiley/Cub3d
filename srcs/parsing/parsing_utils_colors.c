/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_colors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:56:12 by kboulkri          #+#    #+#             */
/*   Updated: 2024/06/21 14:31:33 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	convert_to_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	find_first_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			return (-2);
		if (ft_isdigit(str[i]))
			return (i);
		i++;
	}
	return (-1);
}

int	ft_count_comma(t_data *data)
{
	int	i;
	int	count_comma;
	int	j;

	i = 0;
	while (data->color[i])
	{
		j = 0;
		count_comma = 0;
		while (data->color[i][j])
		{
			if (data->color[i][j] == ',')
				count_comma++;
			j++;
		}
		if (count_comma != 2)
			return (1);
		i++;
	}
	return (count_comma);
}

int	stock_floor_ceiling(t_data *data, int i, int *stock)
{
	if (i == 0)
	{
		data->rgb_floor = convert_to_rgb(stock[0], stock[1], stock[2]);
		return (0);
	}
	else
	{
		data->rgb_ceiling = convert_to_rgb(stock[0], stock[1], stock[2]);
		return (0);
	}
}

int	end_stock_info_map(t_data *data, int i)
{
	if (data->flag_double)
		return (ft_printf("Error\nDouble info\n"), free_texture(data),
			free_tab(data->color), 1);
	if (i != 6)
		return (ft_printf("Error\nMissing info\n"),
			free_tab(data->texture), 1);
	else
		ft_del_newline(data);
	return (0);
}
