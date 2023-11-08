/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:38:26 by xcharra           #+#    #+#             */
/*   Updated: 2023/11/08 13:40:09 by xcharra          ###   ########.fr       */
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
