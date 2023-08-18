/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 08:07:26 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/18 13:13:37 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

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

typedef struct s_game
{
	char			**map;
	t_textures		*textures;
	t_colors		*colors;
	t_player		*player;
}	t_game;

t_game	*parsing(char *file);
void	print_textures(t_game *g);

#endif

