/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:03:02 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/02 15:04:01 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_game *g)
{
	g->player->angle -= M_PI / 45;
}

void	rotate_right(t_game *g)
{
	g->player->angle += M_PI / 45;
}

void	move_forward(t_game *g)
{
	float	nextx;
	float	nexty;
	
	nextx = g->player->fx + cos (g->player->angle) * 0.1;
	nexty = g->player->fy + sin (g->player->angle) * 0.1;
	if (g->smap->map[(int)(g->player->fy)][(int)(nextx)] == '0')
		g->player->fx += cos(g->player->angle) * 0.1;
	if (g->smap->map[(int)(nexty)][(int)(g->player->fx)] == '0')
		g->player->fy += sin(g->player->angle) * 0.1;
}

void	move_backward(t_game *g)
{
	float	nextx;
	float	nexty;
	
	nextx = g->player->fx + cos (g->player->angle + M_PI) * 0.1;
	nexty = g->player->fy + sin (g->player->angle + M_PI) * 0.1;
	if (g->smap->map[(int)(g->player->fy)][(int)(nextx)] == '0')
		g->player->fx += cos(g->player->angle + M_PI) * 0.1;
	if (g->smap->map[(int)(nexty)][(int)(g->player->fx)] == '0')
		g->player->fy += sin(g->player->angle + M_PI) * 0.1;
}

void	move_left(t_game *g)
{
	float	nextx;
	float	nexty;
	
	nextx = g->player->fx + cos (g->player->angle - M_PI_2) * 0.1;
	nexty = g->player->fy + sin (g->player->angle - M_PI_2) * 0.1;
	if (g->smap->map[(int)(g->player->fy)][(int)(nextx)] == '0')
		g->player->fx += cos(g->player->angle - M_PI_2) * 0.1;
	if (g->smap->map[(int)(nexty)][(int)(g->player->fx)] == '0')
		g->player->fy += sin(g->player->angle - M_PI_2) * 0.1;
}

void	move_right(t_game *g)
{
	float	nextx;
	float	nexty;
	
	nextx = g->player->fx + cos (g->player->angle + M_PI_2) * 0.1;
	nexty = g->player->fy + sin (g->player->angle + M_PI_2) * 0.1;
	if (g->smap->map[(int)(g->player->fy)][(int)(nextx)] == '0')
		g->player->fx += cos(g->player->angle + M_PI_2) * 0.1;
	if (g->smap->map[(int)(nexty)][(int)(g->player->fx)] == '0')
		g->player->fy += sin(g->player->angle + M_PI_2) * 0.1;
}
