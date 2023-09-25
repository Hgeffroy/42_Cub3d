/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:03:48 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/25 12:55:48 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Faire un ptr sur fct
*/
void	fill_texture(t_game **g, char *line)
{
	// Il va falloir check les doublons ici aussi.
	if (line[0] == 'C')
		(*g)->colors->rgb_roof = ft_strdup(line); // Protection malloc, passer les whitespaces et enlever le \n.
	else if (line[0] == 'F')
		(*g)->colors->rgb_floor = ft_strdup(line); // Protection malloc, passer les whitespaces.
	else if (line[0] == 'N')
		(*g)->textures->north = ft_strdup(line); // Protection malloc, passer les whitespaces.
	else if (line[0] == 'S')
		(*g)->textures->south = ft_strdup(line); // Protection malloc, passer les whitespaces.
	else if (line[0] == 'W')
		(*g)->textures->west = ft_strdup(line); // Protection malloc, passer les whitespaces.
	else if (line[0] == 'E')
		(*g)->textures->east = ft_strdup(line); // Protection malloc, passer les whitespaces.
}

int	is_textstart(char *line)
{
	if (line[0] == 'C')
		return (YES);
	else if (line[0] == 'F')
		return (YES);
	else if (line[1] && line[0] == 'N' && line[1] == 'O')
		return (YES);
	else if (line[1] && line[0] == 'S' && line[1] == 'O')
		return (YES);
	else if (line[1] && line[0] == 'W' && line[1] == 'E')
		return (YES);
	else if (line[1] && line[0] == 'E' && line[1] == 'A')
		return (YES);
	return (NO);
}


void	check_line(t_game **g, char *line)
{
	int	i;
	int	text_start;

	i = -1;
	text_start = NO;
	while (line[++i])
	{
		text_start = is_textstart(&line[i]);
		if (text_start == YES)
			break ;
	}
	if (text_start == NO)
		return ;
	fill_texture(g, &line[i]);
}

int	get_textures(t_game **g, int fd)
{
	char	*line;

	line = NULL;
	while (is_mapline(line) == NO)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		check_line(g, line);
	}
	free(line);
	// On peut check qu'on a bien toutes les textures ici.
	// La derniere ligne est la premiere ligne de la map, donc soit on la recupere soit on reparcourt le fichier.
	return (0);
}
