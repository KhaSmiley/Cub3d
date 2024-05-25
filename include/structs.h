/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:15:07 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/25 15:38:25 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef double t_moha2d	__attribute((ext_vector_type(2)));
typedef int t_moha2i	__attribute__((ext_vector_type(2)));

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

typedef struct s_ray //the ray structure
{
	// fixed angle variable
	double		ray_dir; // ray direction in degrees- init to player direction
	t_moha2d	ray_end; // ray end coordinates
	t_moha2d	next_step; // coordinates for next (first closest) intersection with an x or y axis
	t_moha2d	step_size; // size of steps between x and y intersections (based on payer position and direction)
	t_moha2d	distance_to_wall; // coordinates for distance to the wall (hyptheneuse)
	t_moha2d	ray_len; // length of ray
	double		draw_len; // length of ray to draw
	int			side_flag;  // flag for the wall
}	t_ray;

typedef struct s_player //the player structure
{
	t_moha2d	pos; // player position in pixels
	float		direction; // in degrees
	float		fov_rd; // field of view in radians
	int			rot; // rotation flag
	int			l_r; // left right flag
	int			f_b; // fowards backwards flag
	t_keys		key_flags; // array of key flags
}	t_player;

typedef struct s_mlx //the mlx structure
{
	void		*bckgrd_ptr; // the background (for now)
	void		*mlx_ptr; // the mlx pointer
	void		*mlx_win; // the window pointer
	t_player	*player; // the player structure
}	t_mlx;

typedef struct s_data // parsing info
{
	char		**map;
	int			nb_line;
	int			w_map; // map width
	int			h_map; // map height
	t_moha2i	start_pos; // player start position in the map
	char		player_dir;
	int			floor_colour;
	int			ceiling_colour;
	char 		*no_texture; //north texture
	char 		*so_texture; //south texture
	char 		*we_texture; //we get the idea
	char 		*ea_texture;
	t_mlx		*mlx; // the mlx structure
	t_player	*player; // the player structure
	t_ray		*ray; // the ray structure
}	t_data;
