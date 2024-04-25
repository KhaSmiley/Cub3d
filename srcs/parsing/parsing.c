/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:29:55 by kboulkri          #+#    #+#             */
/*   Updated: 2024/04/25 23:25:30 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_data(t_data *data, char **argv)
{
	(void)argv;
	data->nb_line = 0;
	return (0);
}
void	push_map_to_struct(t_data *data, char *path)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return ;
	data->map = ft_calloc((data->nb_line + 1), sizeof(char *));
	if (!data->map)
		return ;
	while (i < data->nb_line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->map[i] = ft_substr(line, 0, ft_strlen_until_char(line, '\n'));
		i++;
		free(line);
	}
	data->map[i] = NULL;
}

int	check_map_right_and_size(t_data *data, char *path)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nFile doesn't exist", -1));
	line = get_next_line(fd);
	if (!line)
		exit(ft_printf("Error\nFile is empty\n"));
	while (line)
	{
		if (!line)
			break ;
		free(line);
		line = get_next_line(fd);
		data->nb_line++;
	}
	fd = close(fd);
	free(line);
	return (0);
}

int	invalid_char_in_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '0' && data->map[i][j] != '1'
				&& data->map[i][j] != 'N' && data->map[i][j] != 'S'
				&& data->map[i][j] != 'E' && data->map[i][j] != 'W')
			{
				ft_printf("Error\nWrong char in map\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	static t_data data;

	if (argc == 2)
	{
		if (init_data(&data, argv))
			return (0);
		if (check_extension(argv[1]))
			return (0);
		if (check_map_right_and_size(&data, argv[1]))
			return (0);
		push_map_to_struct(&data, argv[1]);
		if (invalid_char_in_map(&data))
			return (0);
	}
	else
		ft_printf("Error number of args\n");
	free_tab(data.map);
	return (0);
}