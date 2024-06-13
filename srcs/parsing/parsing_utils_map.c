/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:42:25 by kboulkri          #+#    #+#             */
/*   Updated: 2024/06/13 21:41:21 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	close(fd);
	return (0);
}

void	stock_map_2(t_data *data, char *line, int *i)
{
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "NO		 ", 3))
	{
		data->map_start++;
		(*i)++;
		data->texture[0] = ft_substr(&line[ft_find_i(line)], 0,
				ft_strlen_until_char(line, '\n'));
	}
	else if (!ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "SO	", 3))
	{
		data->map_start++;
		(*i)++;
		data->texture[1] = ft_substr(&line[ft_find_i(line)], 0,
				ft_strlen_until_char(line, '\n'));
	}
	else if (!ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "WE	", 3))
	{
		data->map_start++;
		(*i)++;
		data->texture[2] = ft_substr(&line[ft_find_i(line)], 0,
				ft_strlen_until_char(line, '\n'));
	}
	else if (!ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "EA	", 3))
	{
		data->map_start++;
		(*i)++;
		data->texture[3] = ft_substr(&line[ft_find_i(line)], 0,
				ft_strlen_until_char(line, '\n'));
	}
	else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "F	", 3))
	{
		data->map_start++;
		(*i)++;
		data->color[0] = ft_substr(&line[ft_find_i(line)], 0,
				ft_strlen_until_char(line, '\n'));
	}
	else if (!ft_strncmp(line, "C ", 2) || !ft_strncmp(line, "C	", 3))
	{
		data->map_start++;
		(*i)++;
		data->color[1] = ft_substr(&line[ft_find_i(line)], 0,
				ft_strlen_until_char(line, '\n'));
	}
}

int	stock_info_map(t_data *data, int fd)
{
	int i;
	char *line;

	i = 0;
	line = NULL;
	printf(">>>%d\n", fd);
	data->texture = ft_calloc(sizeof(char *), 5);
	data->color = ft_calloc(sizeof(char *), 3);
	free(line);
	while (i != 6)
	{
		line = get_next_line(fd);
		printf(">>>>>>>>1st%s\n", line);
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
	if (i != 6)
		return (close(fd), ft_printf("Error\nMissing infohere2\n"),
			free_tab(data->texture), 1);
	return (0);
}