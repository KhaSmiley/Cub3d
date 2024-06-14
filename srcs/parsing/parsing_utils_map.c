/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:42:25 by kboulkri          #+#    #+#             */
/*   Updated: 2024/06/14 21:44:58 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	stock_map_to_struct(t_data *data, int size)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	data->map = ft_calloc(sizeof(char *), size + 1);
	fd = open(data->path, O_RDONLY);
	skip_info_map(data, fd);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n')
			break ;
		data->map[i] = ft_substr(line, 0, ft_strlen_until_char(line, '\n'));
		free(line);
		i++;
	}
	data->map[i] = NULL;
	free(line);
	if (check_end_map(fd))
		return (ft_printf("Error\nMap not valid\n"), close(fd),
			free_tab(data->map), 1);
	return (close(fd), 0);
}

void	stock_map_4(t_data *data, char *line, int *i)
{
	if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "F	", 3))
	{
		data->map_start++;
		if (!data->color[0])
			data->color[0] = ft_substr(&line[ft_find_i(line)], 0,
					ft_strlen_until_char(line, '\n'));
		else
			data->flag_double = 1;
		(*i)++;
	}
	else if (!ft_strncmp(line, "C ", 2) || !ft_strncmp(line, "C	", 3))
	{
		data->map_start++;
		if (!data->color[1])
			data->color[1] = ft_substr(&line[ft_find_i(line)], 0,
					ft_strlen_until_char(line, '\n'));
		else
			data->flag_double = 1;
		(*i)++;
	}
}

void	stock_map_3(t_data *data, char *line, int *i)
{
	if (!ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "WE	", 3))
	{
		data->map_start++;
		if (!data->texture[2])
			data->texture[2] = ft_substr(&line[ft_find_i(line)], 0,
					ft_strlen_until_char(line, '\n'));
		else
			data->flag_double = 1;
		(*i)++;
	}
	else if (!ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "EA	", 3))
	{
		data->map_start++;
		if (!data->texture[3])
			data->texture[3] = ft_substr(&line[ft_find_i(line)], 0,
					ft_strlen_until_char(line, '\n'));
		else
			data->flag_double = 1;
		(*i)++;
	}
	stock_map_4(data, line, i);
}

void	stock_map_2(t_data *data, char *line, int *i)
{
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "NO			", 3))
	{
		data->map_start++;
		if (!data->texture[0])
			data->texture[0] = ft_substr(&line[ft_find_i(line)], 0,
					ft_strlen_until_char(line, '\n'));
		else
			data->flag_double = 1;
		(*i)++;
	}
	else if (!ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "SO	", 3))
	{
		data->map_start++;
		if (!data->texture[1])
		{
			printf("HERE\n");
			data->texture[1] = ft_substr(&line[ft_find_i(line)], 0,
					ft_strlen_until_char(line, '\n'));
		}
		else
			data->flag_double = 1;
		(*i)++;
	}
	stock_map_3(data, line, i);
}

int	stock_info_map(t_data *data, int fd)
{
	int		i;
	char	*line;

	i = 0;
	data->texture = ft_calloc(sizeof(char *), 5);
	data->color = ft_calloc(sizeof(char *), 3);
	while (i != 6)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n')
		{
			free(line);
			data->map_start++;
			continue ;
		}
		stock_map_2(data, line, &i);
		free(line);
	}
	data->texture[4] = NULL;
	data->color[2] = NULL;
	if (end_stock_info_map(data, i))
		return (close(fd), 1);
	return (0);
}
