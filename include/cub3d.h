#ifndef CUB3D_H
#define CUB3D_H

#include "../libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <math.h>

# define FALSE -1
# define TRUE 0

# define S_W 1900 // screen width
# define S_H 1000 // screen height
# define TILE_SIZE 30 // tile size
# define FOV 60 // field of view
# define ROTATION_SPEED 0.045 // rotation speed
# define PLAYER_SPEED 4 // player speed

typedef struct s_data
{
	char	**map;
	int		nb_line;
	// map width
	// map height
	// player start x poisiton
	// player start y position
}	t_data;

// player structure t_player

// mlx structure t_mlx

// ray structure t_ray


/* parsing .c */

int			invalid_char_in_map(t_data *data);
int			check_map_right_and_size(t_data *data, char *path);
void		push_map_to_struct(t_data *data, char *path);
int			init_data(t_data *data);
int			parsing(t_data *data, char *arg);

/* parsing_utils.c */

int			check_extension(char *argv);
size_t		ft_strlen_until_char(char *str, char c);

/* utils.c */

void		print_arr(char **arr);

#endif
