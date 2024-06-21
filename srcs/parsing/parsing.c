/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:55:24 by kboulkri          #+#    #+#             */
/*   Updated: 2024/06/21 16:14:25 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_all_info_two(char *line, int *i)
{
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "NO			", 3))
		(*i)++;
	else if (!ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "SO	", 3))
		(*i)++;
	else if (!ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "WE	", 3))
		(*i)++;
	else if (!ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "EA	", 3))
		(*i)++;
	else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "F	", 3))
		(*i)++;
	else if (!ft_strncmp(line, "C ", 2) || !ft_strncmp(line, "C	", 3))
		(*i)++;
	else
		return (1);
	return (0);
}

int	check_all_info(t_data *data)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(data->path, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nMap File\n"), 1);
	while (i != 6)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		else if (line[0] == '\n')
		{
			free(line);
			continue ;
		}
		else if (check_all_info_two(line, &i))
			return (free(line), close(fd), ft_printf("Error\nInvalid info\n"), 1);
		free(line);
	}
	if (i != 6)
		return (close(fd), ft_printf("Error\nMap File\n"), 1);
	return (close(fd), 0);
}

int	map_is_flooded(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[++i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0' || data->map[i][j] == 'N'
				|| data->map[i][j] == 'S' || data->map[i][j] == 'W'
				|| data->map[i][j] == 'E')
			{
				if (check_char(data, i, j))
					return (1);
			}
			j++;
		}
	}
	return (0);
}

void	free_texture(t_data *data)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		free(data->texture[i]);
		i++;
	}
	free(data->texture);
}

int	parsing(t_data *data, char *arg)
{
	if (check_extension(arg))
		return (1);
	if (check_all_info(data))
		return (1);
	if (check_info_map(data))
		return (1);
	else if (invalid_char_in_map(data))
		return (1);
	data->map = ft_add_space_to_map(data);
	if (map_is_flooded(data))
		return (free_tab(data->map), free_tab(data->texture),
			free_tab(data->color), 1);
	return (0);
}
