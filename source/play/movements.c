/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:03:02 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/11 07:47:35 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_game *g, int ratio)
{
	g->player->angle -= ratio * M_PI / 600;
}

void	rotate_right(t_game *g, int ratio)
{
	g->player->angle += ratio * M_PI / 600;
}

void	move_forward(t_game *g)
{
	float	nextx;
	float	nexty;
	
	nextx = g->player->fx + cos (g->player->angle) * SPEED;
	nexty = g->player->fy + sin (g->player->angle) * SPEED;
	if (g->smap.map[(int)(g->player->fy)][(int)(nextx)] == '0')
		g->player->fx += cos(g->player->angle) * SPEED;
	if (g->smap.map[(int)(nexty)][(int)(g->player->fx)] == '0')
		g->player->fy += sin(g->player->angle) * SPEED;
}

void	move_backward(t_game *g)
{
	float	nextx;
	float	nexty;
	
	nextx = g->player->fx + cos (g->player->angle + M_PI) * SPEED;
	nexty = g->player->fy + sin (g->player->angle + M_PI) * SPEED;
	if (g->smap.map[(int)(g->player->fy)][(int)(nextx)] == '0')
		g->player->fx += cos(g->player->angle + M_PI) * SPEED;
	if (g->smap.map[(int)(nexty)][(int)(g->player->fx)] == '0')
		g->player->fy += sin(g->player->angle + M_PI) * SPEED;
}

void	move_left(t_game *g)
{
	float	nextx;
	float	nexty;
	
	nextx = g->player->fx + cos (g->player->angle - M_PI_2) * SPEED;
	nexty = g->player->fy + sin (g->player->angle - M_PI_2) * SPEED;
	if (g->smap.map[(int)(g->player->fy)][(int)(nextx)] == '0')
		g->player->fx += cos(g->player->angle - M_PI_2) * SPEED;
	if (g->smap.map[(int)(nexty)][(int)(g->player->fx)] == '0')
		g->player->fy += sin(g->player->angle - M_PI_2) * SPEED;
}

void	move_right(t_game *g)
{
	float	nextx;
	float	nexty;
	
	nextx = g->player->fx + cos (g->player->angle + M_PI_2) * SPEED;
	nexty = g->player->fy + sin (g->player->angle + M_PI_2) * SPEED;
	if (g->smap.map[(int)(g->player->fy)][(int)(nextx)] == '0')
		g->player->fx += cos(g->player->angle + M_PI_2) * SPEED;
	if (g->smap.map[(int)(nexty)][(int)(g->player->fx)] == '0')
		g->player->fy += sin(g->player->angle + M_PI_2) * SPEED;
}
