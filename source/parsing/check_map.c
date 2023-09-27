/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:18:26 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/27 11:18:42 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	player_here(t_game *g, int y, int x)
{
	if (g->smap->map[y][x] == 'N')
	{
		g->player->x = x;
		g->player->y = y;
		g->player->angle = M_PI_2 * (-1);
		return (YES);
	}
	else if (g->smap->map[y][x] == 'S')
	{
		g->player->x = x;
		g->player->y = y;
		g->player->angle = M_PI_2;
		return (YES);
	}
	else if (g->smap->map[y][x] == 'E')
	{
		g->player->x = x;
		g->player->y = y;
		g->player->angle = 0;
		return (YES);
	}
	else if (g->smap->map[y][x] == 'W')
	{
		g->player->x = x;
		g->player->y = y;
		g->player->angle = M_PI;
		return (YES);
	}
	return (NO);
}

int	get_player(t_game *g)
{
	int	y;
	int	x;
	
	y = 0;
	while(g->smap->map[y])
	{
		x = 0;
		while(g->smap->map[y][x])
		{
			if (player_here(g, y, x) == YES)
			{
				g->smap->map[y][x] = '0';
				return (0);
			}
			x++;	
		}
		y++;
	}
	return (1);
}

int	backtracking(t_game *g, int y, int x)
{
	g->smap->map_cpy[y][x] = '1';
	if (check_around(g, x, y) == OPEN)
		return (OPEN);
	if (check_up(g->smap, x, y) == 0)
		backtracking(g, y - 1, x);
	if (check_down(g->smap, x, y) == 0)
		backtracking(g, y + 1, x);
	if (check_right(g->smap, x, y) == 0)
		backtracking(g, y, x + 1);
	if (check_left(g->smap, x, y) == 0)
		backtracking(g, y, x - 1);
	return (0);
}

int	check_map(t_game *g)
{
	if (get_player(g))
		return (1);
	if (backtracking(g, g->player->y, g->player->x))
		return (1);
	return (0);
}