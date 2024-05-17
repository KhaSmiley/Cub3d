/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:15:07 by lbarry            #+#    #+#             */
/*   Updated: 2024/05/17 20:29:03 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_ray //the ray structure
{
	float		ray_dir; // ray direction in degrees- init to player direction
	float		distance_to_wall; // distance to the wall
	int			flag;  // flag for the wall
}	t_ray;

typedef struct s_player //the player structure
{
	float		player_x; // player x position in pixels
	float		player_y; // player y position in pixels
	float		direction; // in degrees
	float		fov_rd; // field of view in radians
	int			rot; // rotation flag
	int			l_r; // left right flag
	int			f_b; // fowards backwards flag
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
	int			start_x; // player start x poisiton in the map
	int			start_y; // player start y position in the map
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
