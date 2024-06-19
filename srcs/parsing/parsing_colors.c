/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:55:18 by kboulkri          #+#    #+#             */
/*   Updated: 2024/06/15 19:16:19 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_digit_space_two(t_data *data, int *i, int *j, int *flag)
{
	while (data->color[*i][*j])
	{
		if (ft_isdigit(data->color[*i][*j]))
		{
			if (*flag == 1)
				return (1);
			while (data->color[*i][*j] && ft_isdigit(data->color[*i][*j]))
				(*j)++;
			*flag = 1;
		}
		if (data->color[*i][*j] == ',')
		{
			if (*flag == 0)
				return (1);
			*flag = 0;
		}
		(*j)++;
	}
	if (*flag == 0)
		return (1);
	return (0);
}

int	ft_check_digit_space(t_data *data)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (data->color[i])
	{
		flag = 0;
		j = find_first_digit(data->color[i]);
		if (j == -1)
			return (free_tab(data->map), free_tab(data->texture),
				free_tab(data->color), ft_printf("Error\n5Color not valid\n"),
				1);
		if (j == -2)
			return (1);
		while (data->color[i][j])
		{
			if (check_digit_space_two(data, &i, &j, &flag))
				return (1);
		}
		flag = 0;
		i++;
	}
	return (0);
}

int	stock_color(t_data *data, int *i, int *j, int *x)
{
	int	stock[3];

	while (data->color[*i][*j])
	{
		if (data->color[*i][*j] == ' ' || data->color[*i][*j] == '\t')
			while (data->color[*i][*j] == ' ' || data->color[*i][*j] == '\t')
				(*j)++;
		else if (ft_isdigit(data->color[*i][*j]))
		{
			stock[(*x)] = ft_atoi(&data->color[*i][*j]);
			if (stock[(*x)] < 0 || stock[(*x)] > 255)
				return (1);
			(*x)++;
			while (data->color[*i][*j] && ft_isdigit(data->color[*i][*j]))
				(*j)++;
		}
		else if (data->color[*i][*j] == ',')
			(*j)++;
		else
			return (1);
	}
	stock_floor_ceiling(data, *i, &stock[0]);
	return (0);
}

int	check_colors_ok(t_data *data)
{
	int	i;
	int	x;
	int	j;

	i = 0;
	x = 0;
	while (data->color[i])
	{
		x = 0;
		j = find_first_digit(data->color[i]);
		if (j == -1)
			return (free_tab(data->map), free_tab(data->texture),
				free_tab(data->color), ft_printf("Error\nColor not valid\n"),
				1);
		if (stock_color(data, &i, &j, &x))
			return (free_tab(data->map), free_tab(data->texture),
				free_tab(data->color), ft_printf("Error\nColor not valid\n"),
				1);
		i++;
	}
	return (0);
}

int	convert_color(t_data *data)
{
	if (ft_count_comma(data) != 2)
		return (free_tab(data->map), free_tab(data->texture),
			free_tab(data->color), ft_printf("Error\nColor not valid\n"), 1);
	if (ft_check_digit_space(data))
		return (free_tab(data->map), free_tab(data->color),
			free_tab(data->texture), ft_printf("Error\nColor not valid\n", 1));
	if (check_colors_ok(data))
		return (1);
	return (0);
}
