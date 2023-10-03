/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 08:07:26 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/02 15:01:12 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

t_game	*parsing(char *file);
int		get_textures(t_game **g, int fd);
int		is_mapline(char *line);
int		check_file(char *file);
t_map	*get_map(char *file);
void	print_parsing(t_game *g);

int		check_around(t_game *g, int x, int y);
int		check_up(t_map *smap, int x, int y);
int		check_down(t_map *smap, int x, int y);
int		check_right(t_map *smap, int x, int y);
int		check_left(t_map *smap, int x, int y);
int		check_map(t_game *g);

int		init_walls(t_game *g);
int		is_whitespace(char c);


#endif

