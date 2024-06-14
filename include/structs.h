/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:15:07 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/13 23:04:34 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include "cub3d.h"

typedef double t_moha2d	__attribute((ext_vector_type(2)));
typedef int t_moha2i	__attribute__((ext_vector_type(2)));

typedef struct s_textures
{
	void		*img; // img pointer, identifier
	int			*addr; // memory address of the img, used to directly read from and write to the pixel data of the image
	int			bpp; // bits used to represent 1 pixel of the img, used calculate pixel locations
	int			line_l; // no of bytes used in single row of img, used to iterate through img correctly
	int			endian; // big (1) or little endian (0), determines byte order in which pixel data is stored
	int			w; // height of img in pixels
	int			h; // width of img in pixels
}	t_textures;

typedef struct s_keys // key flags for movement
{
	int			w; // key W
	int			a; // key A
	int			s; // key S
	int			d; // key D
	int			left; // left arrow
	int			right; // right arrow
	int			esc; // escape
}	t_keys;

typedef struct s_ray // ray casting
{
	double		ray_dir_deg; // ray direction in degrees- init to player direction
	t_moha2d	ray_dir; // ray direction vector
	t_moha2d	plane; // player plane vector
	t_moha2d	first_step; // coordinates for first closest intersection with an x or y axis
	t_moha2d	next_step; // coordinates for next intersections with an x or y axis
	double		distance_to_wall; // distance to the closest wall (shortest hyptheneuse)
	t_moha2i	map; // map position of the wall
	t_moha2i	step_flag; // which direction to step in for x and y
	char		texture; // texture of next closest wall
	int			wall_len; // wall height - length of ray to draw (used to calc ceiling + floor too)
	int			draw_start; // top of wall
	int			draw_end; // bottom of wall
	double		text_pos; // current texture position
	double		text_step; // step to increase text_pos on y axis of texture
	t_moha2i	text_coord; // texture coordinates
	double		wall_x; // exact x coordinate of the wall hit
}	t_ray;

typedef struct s_player
{
	t_moha2d	pos; // player position in pixels
	t_moha2d	dir; // player direction vector
	float		dir_deg; // player direction in degrees
	float		fov_rd; // field of view in radians
	int			rot; // rotation flag
	int			l_r; // left right flag
	int			f_b; // fowards backwards flag
	t_keys		*key_flags; // array of key flags
}	t_player;

typedef struct s_mlx
{
	void		*mlx_ptr; // the mlx pointer
	void		*mlx_win; // the window pointer
	void		*screen_ptr; // the screen buffer pointer
	t_textures	*screen_buffer; // the screen buffer structure
	void		*bckgrd_ptr; // the background image pointer (tmp)
	t_player	*player; // the player structure
}	t_mlx;

typedef struct s_data // parsing info
{
	char			**map; // the map
	char			**info; // ?
	char			**texture; // ?
	char			**color; // ?
	int				rgb_floor; // floor color rgb format
	int				rgb_ceiling; // ceiling color rgb format
	char			*path; // path to the .cub file
	int				map_start; // map start line (after parsing info)
	int 			len_max; // max length of the map
	int				nb_line; // number of lines in the map
	int				nb_player; // number of players
	int				w_map; // map width
	int				h_map; // map height
	t_moha2i		start_pos; // player start position in the map
	char			player_dir; // player start direction N, S, E, or W
	t_mlx			*mlx; // the mlx structure
	t_player		*player; // the player structure
	t_ray			*ray; // the ray structure
	t_textures		textures[4]; // structure with img info for every texture
}	t_data;

#endif
