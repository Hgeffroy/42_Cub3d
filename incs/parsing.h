/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:38:26 by xcharra           #+#    #+#             */
/*   Updated: 2023/11/02 18:20:14 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>

# include "structs.h"

/* error messages */
# define E_NARGS	"Please enter a single argument\n"
# define E_NSFD		"No such file or directory\n"
# define E_EMMA		"The map file is empty\n"
# define E_NOMEM	"Malloc error\n"
# define E_WREXT	"Wrong file extension\n"
# define E_WRTXREXT	"Wrong textures extension (%s)\n"
# define E_NOTXR	"Something is wrong with the textures path\n"
# define E_NORGB	"Something is wrong with rgb value\n"
# define E_NOMAP	"There is no map at end of file\n"
# define E_NOENDMAP	"There is a map that is not last in the file\n"
# define E_DUPPATH	"There is more than one path for %s texture\n"
# define E_THAMAP	"There is something after the map: %s\n"
# define E_ILLCHAR	"This line contain illegal character: %s\n"
# define E_MPLAYER	"There is more than one player\n"
# define E_NPLAYER	"There is no player\n"
# define E_MNCLOSED	"Map not closed\n"

/* */
# define M_CHARSET	"01 NSEW\n"
# define B_CHARSET	"01 NSEWD\n"

# ifndef IS_BONUS
#  define BONUS		0
#  define CHARSET	M_CHARSET
#  define FFCHARSET	"NSEW0"
# else
#  define BONUS		1
#  define CHARSET	B_CHARSET
#  define FFCHARSET	"NSEW0D"
# endif

/* parsing */
int		parsing(char *map_path, t_data *cub);
int		get_map(t_data *cub);
int		get_new_map(t_data *cub);
int		check_map(t_data *cub);
int		is_closed_map(t_data *cub);
int		get_map_file(char *map_path, t_data *cub);
int		get_txr_and_rgb(t_data *cub);

void	free_txr(t_textures txr);
void	rgb_converter(t_data *cub);

void	clear_parsing(t_data *cub);
/* bonus parsing */
int		get_doors(t_data *cub);
void	replace_doors(t_data *cub);

void	print_parsing(t_data *cub); //!del
void	print_tab_msg(char **tab, char *msg);
//# define DEBUG(x)	ft_fdprintf(2, RED"return here: %s =>"RESET, x)

#endif
