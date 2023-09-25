/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 08:35:37 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/25 15:27:45 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

	if (init_game(&g) < 0)
		return (NULL);
	fd = check_file(file);
	if (fd < 0)
		return (NULL);
	if (get_textures(&g, fd) < 0)
		return (close (fd), NULL);
	close (fd);
	g->smap = get_map(file);
	if (!(g->smap))
		return (NULL);
	return (g);
}

void	print_parsing(t_game *g)
{
	printf("Texture Nord : %s", g->textures->north);
	printf("Texture Sud : %s", g->textures->south);
	printf("Texture Est : %s", g->textures->east);
	printf("Texture Ouest : %s", g->textures->west);
	printf("Texture Plafond : %s", g->colors->rgb_roof);
	printf("Texture Sol : %s\n", g->colors->rgb_floor);
	print_tab(g->smap->map);
}
