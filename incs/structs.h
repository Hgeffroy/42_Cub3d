/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:05:29 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/06 07:54:11 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3D.h"

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
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

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_wallray
{
	float	len;
	float	height;
	float	half_height;
	int		x;
	int		color;
	float	y_ratio;
	float	angle;
	float	x_impact;
	float	y_impact;
}	t_wallray;

typedef struct s_walltext
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_walltext;

typedef struct s_movement
{
	bool	move_up;
	bool	move_down;
	bool	move_right;
	bool	move_left;
	bool	rotate_right;
	bool	rotate_left;
	bool	mouse;
	int		last_x;
}	t_movement;

typedef struct s_ray
{
	float	ray_len[2];
	float	ray_start[2];
	float	ray_dir[2];
	float	step_size[2];
	float	impact[2];
	int		map_check[2];
	int		step[2];
	int		wall_found;
	int		door_type;
}	t_ray;

typedef struct s_minimap
{
	float	display[2];
	float	display_y_start;
	float	coord[2];
	float	map_y_start;
	float	ratio;
	int		center[2];

}	t_minimap;
typedef struct s_door
{
	int		x;
	int		y;
	float	pos;
	int		state;
}	t_door;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	char		**map_file;
	int			c_rgb[3];
	int			rgb_c;
	int			f_rgb[3];
	int			rgb_f;
	int			end_desc;
	t_textures	txr;
	t_player	player;
	t_door		*doors;
	size_t		start;
	size_t		max_y;
	size_t		max_x;
	t_ray		ray;
	t_img		display;
	t_walltext	walls[5];
	t_movement	movement;
}	t_data;

#endif