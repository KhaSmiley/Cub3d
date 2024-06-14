/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:55:24 by kboulkri          #+#    #+#             */
/*   Updated: 2024/06/13 21:47:49 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void check_all_info_two(char *line, int *i)
{
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "NO		 ", 3))
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
}

int check_all_info(t_data *data)
{
	int fd;
	int i;
	char *line;

	i = 0;
	fd = open(data->path, O_RDONLY);
	printf("JE SUIS FD DANS CHECK%d\n", fd);
	while (i != 6)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n')
		{
			free(line);
			continue ;
		}
		check_all_info_two(line, &i);
		free(line);
	}
	close(fd);
	if (i != 6)
		return (ft_printf("Error\nMissing infohere\n"), 1);
	return(0);
}

int	map_is_flooded(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
			{
				if (data->map[i][j + 1] == '2')
					return (ft_printf("Error\nMap is not flooded\n",
							data->map[i]), 1);
				else if (data->map[i][j - 1] == '2')
					return (ft_printf("Error\nMap is not flooded\n",
							data->map[i]), 1);
				else if (data->map[i + 1][j] == '2')
					return (ft_printf("Error\nMap is not flooded\n",
							data->map[i]), 1);
				else if (data->map[i - 1][j] == '2')
					return (ft_printf("Error\nMap is not flooded\n",
							data->map[i], i, j), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
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
		return (1);
	return (0);
}

char	**push_map_to_struct(t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	data->map = ft_calloc(sizeof(char *), ((data->nb_line) + 1));
	fd = open(data->path, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nFile doesn't exist"), NULL);
	while (i < data->map_start)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		i++;
	}
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->map[i] = ft_substr(line, 0, ft_strlen_until_char(line, '\n'));
		free(line);
		i++;
	}
	data->map[i] = NULL;
	free(line);
	close(fd);
	return (data->map);
}
