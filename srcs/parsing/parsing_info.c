/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:23:23 by kboulkri          #+#    #+#             */
/*   Updated: 2024/06/08 00:57:10 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int    ft_find_i(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        while(ft_isalnum(str[i]))
            i++;
        while(str[i] == ' ')
            i++;
        if (str[i])
            return (i);
        else
            return(-1);
    }
    return (-1);
}

void skip_info_map(t_data *data, int fd)
{
    char *line;
    int i;

    i = 0;
    while(data->map_start)
    {
        line = get_next_line(fd);
        data->map_start--;
        free(line);
    }
}

void stock_map_to_struct(t_data *data, int size)
{
    int i;
    char *line;
    int fd;

    i = 0;
    data->map = ft_calloc(sizeof(char *), size + 1);
    fd = open(data->path, O_RDONLY);
    skip_info_map(data, fd);
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        if (line[0] == '\n')
            break;
        data->map[i] = ft_substr(line, 0, ft_strlen_until_char(line, '\n'));
        free(line);
        i++;
    }
    free(line);
    close(fd);
    data->map[i] = NULL;
    return ;
}

void stock_map_2(t_data *data, char *line, int *i)
{
    if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "NO	    ", 3))
        {
            data->map_start++;
            (*i)++;
            data->texture[0] = ft_substr(&line[ft_find_i(line)], 0, ft_strlen_until_char(line, '\n'));
        }
        else if (!ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "SO	", 3))
        {
            data->map_start++;
            (*i)++;
            data->texture[1] = ft_substr(&line[ft_find_i(line)], 0, ft_strlen_until_char(line, '\n'));
        }
        else if (!ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "WE	", 3))
        {
            data->map_start++;
            (*i)++;
            data->texture[2] = ft_substr(&line[ft_find_i(line)], 0, ft_strlen_until_char(line, '\n'));
        }
        else if (!ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "EA	", 3))
        {
            data->map_start++;
            (*i)++;
            data->texture[3] = ft_substr(&line[ft_find_i(line)], 0, ft_strlen_until_char(line, '\n'));
        }
        else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "F	", 3))
        {
            data->map_start++;
            (*i)++;
            data->color[0] = ft_substr(&line[ft_find_i(line)], 0, ft_strlen_until_char(line, '\n'));
        }
        else if (!ft_strncmp(line, "C ", 2) || !ft_strncmp(line, "C	", 3))
        {
            data->map_start++;
            (*i)++;
            data->color[1] = ft_substr(&line[ft_find_i(line)], 0, ft_strlen_until_char(line, '\n'));
        }
}

int    stock_info_map(t_data *data, int fd)
{
    int i;
    char *line;

    i = 0;
    data->texture = ft_calloc(sizeof(char *), 5);
    data->color = ft_calloc(sizeof(char *), 3);
    while(i != 6)
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
        // if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "NO	    ", 3))
        // {
        //     data->map_start++;
        //     i++;
        //     data->texture[0] = ft_substr(&line[ft_find_i(line)], 0, ft_strlen_until_char(line, '\n'));
        // }
        // else if (!ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "SO	", 3))
        // {
        //     data->map_start++;
        //     i++;
        //     data->texture[1] = ft_substr(&line[ft_find_i(line)], 0, ft_strlen_until_char(line, '\n'));
        // }
        // else if (!ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "WE	", 3))
        // {
        //     data->map_start++;
        //     i++;
        //     data->texture[2] = ft_substr(&line[ft_find_i(line)], 0, ft_strlen_until_char(line, '\n'));
        // }
        // else if (!ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "EA	", 3))
        // {
        //     data->map_start++;
        //     i++;
        //     data->texture[3] = ft_substr(&line[ft_find_i(line)], 0, ft_strlen_until_char(line, '\n'));
        // }
        // else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "F	", 3))
        // {
        //     data->map_start++;
        //     i++;
        //     data->color[0] = ft_substr(&line[ft_find_i(line)], 0, ft_strlen_until_char(line, '\n'));
        // }
        // else if (!ft_strncmp(line, "C ", 2) || !ft_strncmp(line, "C	", 3))
        // {
        //     data->map_start++;
        //     i++;
        //     data->color[1] = ft_substr(&line[ft_find_i(line)], 0, ft_strlen_until_char(line, '\n'));
        // }
        free(line);
    }
    data->texture[4] = NULL;
    data->color[2] = NULL;
    // free(line);
    if (i != 6)
        return(ft_printf("Error\nMissing info\n"), free_tab(data->color), free_tab(data->texture), 1);
    return (0);
}

int find_start_map(t_data *data, int fd)
{
    char *line;

    while(1)
    {
        line = get_next_line(fd);
        if (!line)
        {
            ft_printf("Error\nNo map\n");
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

int find_size_malloc_map(t_data *data, int fd)
{
    int i;
    int size;
    char *line;

    line = NULL;
    i = 0;
    size = 1;
    (void) data;
    while(1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        if (line[0] == '\n')
        {
            free(line);
            continue;
        }
        free(line);
        size += 1;
    }
    free(line);
    data->nb_line = size;
    return (size);
}

int	convert_to_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int convert_color(t_data *data)
{
    int i;
    char **tab_colors;
    char **tab_texture;
    int gb_f[3];
    int gb_c[3];

	i = 0;
    tab_colors = ft_split(data->color[0], ',');
    while(tab_colors[i])
    {
        gb_f[i] = ft_atoi(tab_colors[i]);
        if (gb_f[i] > 255 || gb_f[i] < 0)
            return (ft_printf("Error\nColor is not valid\n"), 1);
        i++;
    }
    i = 0;
    tab_texture = ft_split(data->color[1], ',');
    while(tab_texture[i])
    {
        gb_c[i] = ft_atoi(tab_texture[i]);
        if (gb_c[i] > 255 || gb_c[i] < 0)
            return (ft_printf("Error\nColor is not valid\n"), 1);
        i++;
    }
    data->rgb_f = convert_to_rgb(gb_f[0], gb_f[1], gb_f[2]);
    data->rgb_c = convert_to_rgb(gb_c[0], gb_c[1], gb_c[2]);
    free_tab(tab_colors);
    free_tab(tab_texture);
    free_tab(data->color);
	printf("F = %d\n", data->rgb_f);
	printf("C = %d\n", data->rgb_c);
    return (0);
}

int check_info_map(t_data *data)
{
    char *line;
    int size;
    int fd;
    int i;

    i = 0;
    line = NULL;
    fd = open(data->path, O_RDONLY);
    if (fd < 0)
		return (ft_printf("Error\nFile doesn't exist", -1));
	if (stock_info_map(data, fd))
        return (1);
    if(find_start_map(data, fd))
        return (1);
    // check_extension_info(data);
    size = find_size_malloc_map(data, fd);
    stock_map_to_struct(data, size);
    for(int m = 0; data->texture[m]; m++)
        printf("%s\n", data->texture[m]);
    for(int s = 0; data->color[s]; s++)
        printf("%s\n", data->color[s]);
    close(fd);
    if (convert_color(data))
        return(1);
    return (0);
}
