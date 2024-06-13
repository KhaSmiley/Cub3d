/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_colors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:56:12 by kboulkri          #+#    #+#             */
/*   Updated: 2024/06/13 22:16:13 by kboulkri         ###   ########.fr       */
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
		if (ft_isdigit(str[i]))
			return (i);
		i++;
	}
	return (-1);
}

int	ft_count_comma(t_data *data)
{
	int i;
	int count_comma;
	int j;

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
		i++;
	}
	return (count_comma);
}
int	stock_floor_ceiling(t_data *data, int i, int stock_0, int stock_1, int stock_2)
{
	if (i == 0)
	{
		data->rgb_floor = convert_to_rgb(stock_0, stock_1, stock_2);
		return (0);
	}
	else
	{
		data->rgb_ceiling = convert_to_rgb(stock_0, stock_1, stock_2);
		return (0);
	}
}