/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:03:02 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/27 13:54:36 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_game *g)
{
	g->player->angle -= M_PI / 180;
}

void	rotate_right(t_game *g)
{
	g->player->angle += M_PI / 180;
}

void	move_forward(t_game *g)
{
	float	nextx;
	float	nexty;
	
	nextx = g->player->fx + cos (g->player->angle);
	nexty = g->player->fy + sin (g->player->angle);
	if (g->smap->map[(int)(g->player->fy / TILE_SZ)][(int)(nextx / TILE_SZ)] == '0')
		g->player->fx += cos(g->player->angle);
	if (g->smap->map[(int)(nexty / TILE_SZ)][(int)(g->player->fx / TILE_SZ)] == '0')
		g->player->fy += sin(g->player->angle);
}

void	move_backward(t_game *g)
{
	float	nextx;
	float	nexty;
	
	nextx = g->player->fx + cos (g->player->angle + M_PI);
	nexty = g->player->fy + sin (g->player->angle + M_PI);
	if (g->smap->map[(int)(g->player->fy / TILE_SZ)][(int)(nextx / TILE_SZ)] == '0')
		g->player->fx += cos(g->player->angle + M_PI);
	if (g->smap->map[(int)(nexty / TILE_SZ)][(int)(g->player->fx / TILE_SZ)] == '0')
		g->player->fy += sin(g->player->angle + M_PI);
}

void	move_left(t_game *g)
{
	float	nextx;
	float	nexty;
	
	nextx = g->player->fx + cos (g->player->angle - M_PI_2);
	nexty = g->player->fy + sin (g->player->angle - M_PI_2);
	if (g->smap->map[(int)(g->player->fy / TILE_SZ)][(int)(nextx / TILE_SZ)] == '0')
		g->player->fx += cos(g->player->angle - M_PI_2);
	if (g->smap->map[(int)(nexty / TILE_SZ)][(int)(g->player->fx / TILE_SZ)] == '0')
		g->player->fy += sin(g->player->angle - M_PI_2);
}

void	move_right(t_game *g)
{
	float	nextx;
	float	nexty;
	
	nextx = g->player->fx + cos (g->player->angle + M_PI_2);
	nexty = g->player->fy + sin (g->player->angle + M_PI_2);
	if (g->smap->map[(int)(g->player->fy / TILE_SZ)][(int)(nextx / TILE_SZ)] == '0')
		g->player->fx += cos(g->player->angle + M_PI_2);
	if (g->smap->map[(int)(nexty / TILE_SZ)][(int)(g->player->fx / TILE_SZ)] == '0')
		g->player->fy += sin(g->player->angle + M_PI_2);
}
