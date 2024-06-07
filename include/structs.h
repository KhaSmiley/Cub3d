/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:15:07 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/06 04:15:18 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_ray //the ray structure
{
 double		ray_ngl; // ray angle
 double		distance; // distance to the wall
 int		flag;  // flag for the wall
} t_ray;

typedef struct s_player //the player structure
{
 float		player_x; // player x position in pixels
 float		player_y; // player y position in pixels
 double		angle; // player angle
 float		fov_rd; // field of view in radians
 int		rot; // rotation flag
 int		l_r; // left right flag
 int		f_b; // fowards backwards flag
} t_player;

typedef struct s_mlx //the mlx structure
{
 void		*bckgrd_ptr; // the background (for now)
 void		*mlx_ptr; // the mlx pointer
 void		*mlx_win; // the window pointer
 t_player	*player; // the player structure
} t_mlx;

typedef struct s_data // parsing info
{
	char		**map; // the map
	char		**info; // the info
	char		**texture;
	char		**color;
	int			rgb_f;
	int			rgb_c;
	char		*path; // path to the .cub file
	int			map_start; // map start line (after parsing info)
	int 		len_max; // max length of the map
	int			nb_line; // number of lines in the map
	int			nb_player; // number of players
	int			w_map; // map width
	int			h_map; // map height
	int			start_x; // player start x poisiton in the map
	int			start_y; // player start y position in the map
	char		player_dir; // player direction
	t_mlx		*mlx; // the mlx structure
	t_player	*player; // the player structure
	t_ray		*ray; // the ray structure
}	t_data;
