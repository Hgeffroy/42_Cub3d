/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:59:10 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/15 11:42:16 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include "cub3D.h"

# define H_WHITE			0xffffff
# define H_BLACK			0x000000
# define H_RED				0xff0000
# define H_GREEN			0x00ff00
# define H_DARKGREEN		0x01452c
# define H_BLUE				0x0000ff
# define H_YELLOW			0xffff00
# define H_ORANGE			0xffa500
# define H_PINK				0xffc0cb
# define H_PURPLE			0x800080
# define H_GREY				0x808080

# define TILE_SZ			16
# define PLAYER_SZ			4
# define SCREEN_DIST		10
# define WALL_HEIGHT		160
# define SPEED				0.04
# define SCREEN_HEIGHT		960
# define SCREEN_WIDTH		1707
# define DOORTXR			"./assets/textures/magic_wall_x2048.xpm"

/* error messages */
# define E_NARGS			"Please enter a single argument\n"
# define E_NSFD				"No such file or directory\n"
# define E_EMMA				"The map file is empty\n"
# define E_NOMEM			"Malloc error\n"
# define E_WREXT			"Wrong file extension\n"
# define E_WRTXREXT			"Wrong textures extension (%s)\n"
# define E_NOTXR			"Something is wrong with the textures path\n"
# define E_NORGB			"Something is wrong with rgb value\n"
# define E_NOMAP			"There is no map at end of file\n"
# define E_NOENDMAP			"There is a map that is not last in the file\n"
# define E_DUPPATH			"There is more than one path for %s texture\n"
# define E_THAMAP			"There is something after the map: %s\n"
# define E_ILLCHAR			"This line contain illegal character: %s\n"
# define E_MPLAYER			"There is more than one player\n"
# define E_NPLAYER			"There is no player\n"
# define E_MNCLOSED			"Map not closed\n"
# define E_OPNTXR			"Can't open texture: %s\n"
# define E_MAPLARGE			"Map too large (x: %d * y: %d) Max 200 * 200\n"
/* legal charset */
# define M_CHARSET			"01 NSEW\n"
# define B_CHARSET			"01 NSEWD\n"

#endif