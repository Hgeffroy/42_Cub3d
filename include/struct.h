/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:05:29 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/26 13:51:29 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "cub3d.h"

typedef struct s_player
{
	int	x;
	int	y;
	int	dir[2]; // Coordonnees du vecteur
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
	char	*hexa_floor;
	char	*hexa_roof;
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

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_img			*minimap;
	t_img			*display;
	t_map			*smap;
	t_textures		*textures;
	t_colors		*colors;
	t_player		*player;
}	t_game;

#endif