/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:16:24 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/21 21:05:15 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#include "structs.h"

# define FALSE -1
# define TRUE 0

# define S_W 1280 // screen width
# define S_H 800 // screen height
# define TILE_SIZE 30 // tile size
# define FOV 60 // field of view
# define ROTATION_SPEED 0.045 // rotation speed
# define PLAYER_SPEED 4 // player speed

/* KEYCODES */
# define KEY_ESC		65307
# define KEY_W			119 // move forwards
# define KEY_A			97 // move left
# define KEY_S			115 // move backwards
# define KEY_D			100 // move right
# define KEY_LEFT		65361 // look left
# define KEY_RIGHT		65363 // look right
// add key press and release even no and masks as macros (press, press_mask, release, release_mask)

/* parsing .c */

int parsing(t_data *data, char *arg);
int init_data(t_data *data);
char **push_map_to_struct(t_data *data);
int map_is_flooded(t_data *data);

/* parsing_map_spaces.c */

char **ft_add_space_to_map(t_data *data);
void find_size_to_malloc_add_spaces(t_data *data);
char *ft_strcpy_cube(char *dest, char *src);

/* parsing_utils.c */

size_t ft_strlen_until_char(char *str, char c);
int check_extension(char *argv);
int invalid_char_in_map(t_data *data);
int invalid_nb_player(t_data *data);

/* parsing_info.c */

int check_info_map(t_data *data);

/* utils.c */

void		print_arr(char **arr);

/* init.c */

void		set_player_start_position(t_data *data);
int			init_data(t_data *data);
void		init_player(t_data *data);
void		get_map_width_height(t_data *data);
void		init_game(t_data *data);

/* pixels.c */
void		mlx_rectangle_put(void *mlx_ptr, void *win_ptr, int x, int y);
void		mlx_put_background(t_mlx *mlx_struct);
void		img_background(t_mlx *mlx_struct);

/* keys.c */

int			key_press(int keycode, t_mlx *mlx_struct);
int			key_release(int keycode, t_mlx *mlx_struct);

/* moves.c */

void		move_forwards(t_mlx *mlx_struct, t_player *player);
void		move_backwards(t_mlx *mlx_struct, t_player *player);
void		move_left(t_mlx *mlx_struct, t_player *player);
void		move_right(t_mlx *mlx_struct, t_player *player);

#endif
