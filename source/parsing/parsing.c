/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 08:35:37 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/18 13:28:35 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file(char *file)
{
	int	fd;
	
	if (ft_strncmp(&file[ft_strlen(file) - 4], ".ber", 4))
		return (ft_dprintf(2, "Wrong map extension"), -1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_dprintf(2, "Couldn't open file, check path, name and rights please");
	return (fd);
}

int	is_mapline(char *line)
{
	int	i;
	int	player;
	
	if (!line)
		return (NO);
	i = -1;
	player = 0;
	while (line[++i])
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
		{
			player++;
			if (player > 1)
				return (NO);
		}
		else if (line[i] != '0' && line[i] != '1' && line[i] != ' ' && line[i] != '\t')
			return (NO);
	}
	return (YES);
}

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
		line = get_next_line(fd);
		check_line(g, line);
	}
	// On peut check qu'on a bien toutes les textures ici.
	// La derniere ligne est la premiere ligne de la map, donc soit on la recupere soit on reparcourt le fichier.
	return (0);
}
int	init_game(t_game **g)
{
	*g = (t_game *)malloc(sizeof(t_game));
	if (!(*g))
		return (-1);
	(*g)->colors = (t_colors *)malloc(sizeof(t_colors));
	if (!((*g)->colors))
		return (free(*g), -1);
	(*g)->textures = (t_textures *)malloc(sizeof(t_textures));
	if (!((*g)->textures))
		return (free((*g)->colors), free(*g), -1);
	(*g)->player = (t_player *)malloc(sizeof(t_player));
	if (!(*g)->player)
		return (free((*g)->textures), free((*g)->colors), free(*g), -1);
	return (0);
}

t_game	*parsing(char *file)
{
	t_game	*g;
	int		fd;

	if (init_game(&g) < 0) // Initialise ptdrlol
		return (NULL);
	fd = check_file(file);
	if (fd < 0)
		return (NULL);
	if (get_textures(&g, fd) < 0)
		return (close (fd), NULL);
	// Open le file, tant que c'est pas une ligne de la map on recupere les textures, si doublon erreur, si ligne inutile pas d'erreur ? Si on met de la merde avant l'identifieur, on recupere l'identifieur.
	// Il va falloir check les textures ensuite !! Verifier qu'on peut open etc...
	// Recuperer la map
	// On sort des qu'on est plus sur un ligne de la map
	close (fd);
	return (g);
}

void	print_textures(t_game *g)
{
	printf("Texture Nord : %s\n", g->textures->north);
	printf("Texture Sud : %s\n", g->textures->south);
	printf("Texture Est : %s\n", g->textures->east);
	printf("Texture Ouest : %s\n", g->textures->west);
	printf("Texture Plafond : %s\n", g->colors->rgb_roof);
	printf("Texture Sol : %s\n", g->colors->rgb_floor);
}
