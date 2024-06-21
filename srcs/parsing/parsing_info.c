/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:23:23 by kboulkri          #+#    #+#             */
/*   Updated: 2024/06/21 15:15:33 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_find_i(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (ft_isalnum(str[i]))
			i++;
		while (str[i] == ' ')
			i++;
		if (str[i])
			return (i);
		else
			return (-1);
	}
	return (-1);
}

void	skip_info_map(t_data *data, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (data->map_start)
	{
		line = get_next_line(fd);
		data->map_start--;
		free(line);
	}
}

int	find_start_map(t_data *data, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			ft_printf("Error\nInvalid map\n");
			free(line);
			close(fd);
			return (1);
		}
		if (line[0] == '\n')
		{
			data->map_start++;
			free(line);
			continue ;
		}
		else
		{
			free(line);
			break ;
		}
	}
	return (0);
}

int	find_size_malloc_map(t_data *data, int fd)
{
	int		i;
	int		size;
	char	*line;

	line = NULL;
	i = 0;
	size = 1;
	(void)data;
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
		free(line);
		size += 1;
	}
	free(line);
	data->nb_line = size;
	return (size);
}

int	check_info_map(t_data *data)
{
	char	*line;
	int		size;
	int		fd;
	int		i;

	i = 0;
	line = NULL;
	fd = open(data->path, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nFile doesn't exist", -1));
	if (stock_info_map(data, fd))
		return (1);
	if (find_start_map(data, fd))
		return (close(fd), free_tab(data->color), free_tab(data->texture), 1);
	size = find_size_malloc_map(data, fd);
	if (stock_map_to_struct(data, size))
		return (close(fd), free_tab(data->color), free_tab(data->texture), 1);
	close(fd);
	ft_del_newline(data);
	if (check_xpm_extension(data))
		return (free_tab(data->map), free_tab(data->color),
			free_tab(data->texture), 1);
	if (convert_color(data))
		return (1);
	return (0);
}
