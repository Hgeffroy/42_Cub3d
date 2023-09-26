/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 08:19:09 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/26 10:47:53 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_left(t_map *smap, int x, int y)
{
	if (x <= 0)
		return (OPEN);
	if (smap->map_cpy[y][x - 1] == '1')
		return (WALL);
	if (smap->map_cpy[y][x - 1] != '0')
		return (OPEN);
	return (0);
}

int	check_right(t_map *smap, int x, int y)
{
	if (x >= smap->mapsize[y] - 1)
		return (OPEN);
	if (smap->map_cpy[y][x + 1] == '1')
		return (WALL);
	if (smap->map_cpy[y][x + 1] != '0')
		return (OPEN);
	return (0);
}

int	check_up(t_map *smap, int x, int y)
{
	if (y <= 0)
		return (OPEN);
	if (x >= smap->mapsize[y - 1] - 1)
		return (OPEN);
	if (smap->map_cpy[y - 1][x] == '1')
		return (WALL);
	if (smap->map_cpy[y - 1][x] != '0')
		return (OPEN);
	return (0);
}

int	check_down(t_map *smap, int x, int y)
{
	if (y >= tab_len(smap->map_cpy))
		return (OPEN);
	if (x >= smap->mapsize[y + 1] - 1)
		return (OPEN);
	if (smap->map_cpy[y + 1][x] == '1')
		return (WALL);
	if (smap->map_cpy[y + 1][x] != '0')
		return (OPEN);
	return (0);
}

int	check_around(t_game *g, int x, int y)
{
	if (check_right(g->smap, x, y) == OPEN)
		return (OPEN);
	if (check_left(g->smap, x, y) == OPEN)
		return (OPEN);
	if (check_up(g->smap, x, y) == OPEN)
		return (OPEN);
	if (check_down(g->smap, x, y) == OPEN)
		return (OPEN);
	return (0);
}