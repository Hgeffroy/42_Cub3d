/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:05:29 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/01 10:38:57 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "cub3d.h"

typedef struct s_player
{
	int		x;
	int		y;
	float	fx;
	float	fy;
	float	angle;
}	t_player;

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_textures;

typedef struct s_colors
{
	char	*rgb_floor;
	char	*rgb_roof;
	int		hexa_floor;
	int		hexa_roof;
}	t_colors;

typedef struct s_map
{
	char	**map;
	char	**map_cpy;
	int		*mapsize;
}	t_map;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_walltext
{
	void	*img;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_walltext;

typedef struct	s_movement
{
	bool	move_up;
	bool	move_down;
	bool	move_right;
	bool	move_left;
	bool	rotate_right;
	bool	rotate_left;
}	t_movement;

typedef struct s_ray
{
	float	ray_len[2];
	float	ray_start[2];
	float	ray_dir[2];
	float	step_size[2];
	bool	tile_found;
	int		map_check[2];
	int		step[2];
}	t_ray;


typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_ray			*ray;
	t_img			*display;
	t_walltext		*north_wall;
	t_walltext		*south_wall;
	t_walltext		*east_wall;
	t_walltext		*west_wall;
	t_map			*smap;
	t_textures		*textures;
	t_colors		*colors;
	t_player		*player;
	t_movement		*movement;
}	t_game;

#endif