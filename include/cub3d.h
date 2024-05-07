/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:16:24 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/08 00:51:05 by lbarry           ###   ########.fr       */
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
# define KEY_W			122 // move forwards
# define KEY_A			113 // move left
# define KEY_S			115 // move backwards
# define KEY_D			100 // move right
# define KEY_LEFT		65361 // look left
# define KEY_RIGHT		65363 // look right

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

/* init.c */

void		set_player_start_position(t_data *data);
int			init_data(t_data *data);
void		init_player(t_data *data);
void		get_map_width_height(t_data *data);
void		init_game(t_data *data);

/* tests.c */
void		mlx_rectangle_put(void *mlx_ptr, void *win_ptr, int x, int y);
void		mlx_background(t_mlx *mlx_struct);

/* keys.c */

int			key_press(int keycode, t_mlx *mlx_struct);
int			key_release(int keycode, t_mlx *mlx_struct);

/* moves.c */

void		move_forwards(t_mlx *mlx_struct, t_player *player);
void		move_backwards(t_mlx *mlx_struct, t_player *player);
void		move_left(t_mlx *mlx_struct, t_player *player);
void		move_right(t_mlx *mlx_struct, t_player *player);

#endif
