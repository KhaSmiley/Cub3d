/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:15:07 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/21 14:16:57 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef double __attribute((ext_vector_type(2)))	t_moha2d;
typedef int __attribute__((ext_vector_type(2)))		t_moha2i;

typedef struct s_textures
{
	void		*img;
	int			*addr;
	int			bpp;
	int			line_l;
	int			endian;
	int			w;
	int			h;
}	t_textures;

typedef struct s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			left;
	int			right;
	int			esc;
	int			ctrl;
}	t_keys;

typedef struct s_ray
{
	double		ray_dir_deg;
	t_moha2d	ray_dir;
	t_moha2d	plane;
	t_moha2d	first_step;
	t_moha2d	next_step;
	double		distance_to_wall;
	t_moha2i	map;
	t_moha2i	step_flag;
	char		texture;
	int			wall_len;
	int			draw_start;
	int			draw_end;
	int			hit;
	double		text_pos;
	double		text_step;
	t_moha2i	text_coord;
	double		wall_x;
}	t_ray;

typedef struct s_player
{
	t_moha2d	pos;
	t_moha2d	dir;
	double		old_dir_x;
	double		old_plane_x;
	float		dir_deg;
	float		fov_rd;
	int			rot;
	t_keys		*key_flags;
}	t_player;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*screen_ptr;
	t_textures	*screen_buffer;
	void		*bckgrd_ptr;
	t_player	*player;
}	t_mlx;

typedef struct s_data
{
	char		**map;
	char		**info;
	char		**texture;
	char		**color;
	int			flag_double;
	int			rgb_floor;
	int			rgb_ceiling;
	char		*path;
	int			map_start;
	int			len_max;
	int			nb_line;
	int			nb_player;
	int			w_map;
	int			h_map;
	t_moha2i	start_pos;
	char		player_dir;
	t_mlx		*mlx;
	t_player	*player;
	t_ray		*ray;
	t_textures	textures[4];
}	t_data;

#endif
