/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:16:24 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/13 23:49:39 by lbarry           ###   ########.fr       */
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
#include "colors.h"

# define FALSE -1
# define TRUE 0

# define S_W 1280 // screen width
# define S_H 800 // screen height
# define TILE_SIZE 30 // tile size
# define FOV 60 // field of view
# define ROTATION_SPEED .05 // rotation speed
# define PLAYER_SPEED 0.05 // player speed

/* KEYCODES */
# define KEY_ESC		65307 // exit
# define KEY_W			122 // move forwards
# define KEY_A			113 // move left
# define KEY_S			115 // move backwards
# define KEY_D			100 // move right
# define KEY_LEFT		65361 // look left
# define KEY_RIGHT		65363 // look right
// add key press and release even no and masks as macros (press, press_mask, release, release_mask)

/* parsing_colors */

int		check_digit_space_two(t_data *data, int *i, int *j, int *flag);
int		ft_check_digit_space(t_data *data);
int		stock_color(t_data *data, int *i, int *j, int *x);
int		check_colors_ok(t_data *data);
int		convert_color(t_data *data);

/* parsing_info */

int		ft_find_i(char *str);
void	skip_info_map(t_data *data, int fd);
int		find_start_map(t_data *data, int fd);
int		find_size_malloc_map(t_data *data, int fd);
int		check_info_map(t_data *data);

/* parsing_map_spaces */

char	**ft_add_space_to_map(t_data *data);
void	find_size_to_malloc_add_spaces(t_data *data);
char	*ft_strcpy_cube(char *dest, char *src);

/* parsing_utils_colors */

int		convert_to_rgb(int r, int g, int b);
int		find_first_digit(char *str);
int		ft_count_comma(t_data *data);

/* parsing_utils_map */

int     check_end_map(int fd);
int     stock_map_to_struct(t_data *data, int size);
void    stock_map_2(t_data *data, char *line, int *i);
int     stock_info_map(t_data *data, int fd);

/* parsing_utils.c */

size_t	ft_strlen_until_char(char *str, char c);
int		check_extension(char *argv);
int		invalid_char_in_map(t_data *data);
int		invalid_nb_player(t_data *data);
void	ft_del_newline(t_data *data);

/* parsing.c */

int		map_is_flooded(t_data *data);
int		parsing(t_data *data, char *arg);
char	**push_map_to_struct(t_data *data);

/* utils.c */

void		print_arr(char **arr);
void		*ft_memset(void *s, int c, size_t n);

/* clean.c */

int			on_destroy(t_data *data);

/* init.c */

void		init_data(t_data *data, char *arg);
void		init_player(t_data *data);
void		init_ray(t_data *data);
void		init_mlx(t_data *data);
void		init_textures(t_data *data);

/* init_utils.c */

void		set_player_start_position(t_data *data);
void		set_start_direction(t_player *player, char dir);
void		get_map_width_height(t_data *data);
void		display_map(t_data *data);

/* pixels.c */ // playing around at the start

void		put_tiles(void *mlx_ptr, void *win_ptr, int x, int y);
void		put_background(t_mlx *mlx_struct);
void		put_player(void *mlx_ptr, void *win_ptr, double x, double y);
void		img_background(t_mlx *mlx_struct);
void		display_circle(t_mlx *mlx);
void		put_line(t_data *data, int x, int y1, int y2, int color);

/* maths.c */

float		deg_to_rad(int deg);
int			rad_to_deg(float rad);
int			calculations(t_data *data);
void		init_camera_position(t_data *data, int x);

/* raycasting.c */

void		draw_walls_colors(t_data *data, int x);
void		draw_walls_textures(t_data *data, int x);
void		calculate_wall_len(t_data *data);
void		find_next_wall(t_data *data);
void		calculate_steps(t_data *data);

/* textures.c */

void		setup_textures(t_data *data);
void		setup_screen_buffer(t_data *data);

/* keys.c */

int			key_press(int keycode, t_mlx *mlx_struct);
int			key_release(int keycode, t_mlx *mlx_struct);
int			move_rotate(t_data *data);

/* moves.c */

void		move_forwards(t_mlx *mlx_struct, t_data *data, t_player *player);
void		move_backwards(t_mlx *mlx_struct, t_data *data, t_player *player);
void		move_left(t_mlx *mlx_struct, t_data *data, t_player *player);
void		move_right(t_mlx *mlx_struct, t_data *data, t_player *player);
void		rotate_player(t_player *player, t_data *data);

/* game.c */

void		play_game(t_data *data);

#endif
