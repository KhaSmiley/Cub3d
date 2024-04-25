#ifndef CUB3D_H
#define CUB3D_H

# define FALSE -1
# define TRUE 0

typedef struct s_data
{
    char **map;
    int    nb_line;

}       t_data;


#include "../libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

/* parsing .c */

int invalid_char_in_map(t_data *data);
int check_map_right_and_size(t_data *data, char *path);
void    push_map_to_struct(t_data *data, char *path);
int init_data(t_data *data, char **argv);

/* parsing_utils.c */

int check_extension(char *argv);
size_t ft_strlen_until_char(char *str, char c);


#endif