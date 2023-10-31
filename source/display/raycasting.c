/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:06:56 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/23 15:07:49 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_init(t_game *g, float angle)
{
	ft_bzero(g->ray.ray_len, 2);
	ft_bzero(g->ray.step, 2);
	g->ray.map_check[0] = (int)g->player.fx;
	g->ray.map_check[1] = (int)g->player.fy;
	g->ray.ray_start[0] = g->player.fx;
	g->ray.ray_start[1] = g->player.fy;
	g->ray.ray_dir[0] = cosf(angle);
	g->ray.ray_dir[1] = sinf(angle);
	g->ray.step_size[0] = sqrt(1 + (g->ray.ray_dir[1] / g->ray.ray_dir[0]) \
	* (g->ray.ray_dir[1] / g->ray.ray_dir[0]));
	g->ray.step_size[1] = sqrt(1 + (g->ray.ray_dir[0] / g->ray.ray_dir[1]) \
	* (g->ray.ray_dir[0] / g->ray.ray_dir[1]));
}

void	ray_start(t_game *g)
{
	if (g->ray.ray_dir[0] < 0)
	{
		g->ray.step[0] = -1;
		g->ray.ray_len[0] = (g->ray.ray_start[0] - \
		(float)(g->ray.map_check[0])) * g->ray.step_size[0];
	}
	else
	{
		g->ray.step[0] = 1;
		g->ray.ray_len[0] = ((float)(g->ray.map_check[0] + 1) - \
		g->ray.ray_start[0]) * g->ray.step_size[0];
	}
	if (g->ray.ray_dir[1] < 0)
	{
		g->ray.step[1] = -1;
		g->ray.ray_len[1] = (g->ray.ray_start[1] - \
		(float)(g->ray.map_check[1])) * g->ray.step_size[1];
	}
	else
	{
		g->ray.step[1] = 1;
		g->ray.ray_len[1] = ((float)(g->ray.map_check[1] + 1) - \
		g->ray.ray_start[1]) * g->ray.step_size[1];
	}
}

float	ray_step(t_game *g)
{
	float	len;

	if (g->ray.ray_len[0] < g->ray.ray_len[1])
	{
		g->ray.map_check[0] += g->ray.step[0];
		len = g->ray.ray_len[0];
		g->ray.ray_len[0] += g->ray.step_size[0];
		if (g->ray.step[0] > 0)
			g->ray.wall_found = EAST;
		else
			g->ray.wall_found = WEST;
	}
	else
	{
		g->ray.map_check[1] += g->ray.step[1];
		len = g->ray.ray_len[1];
		g->ray.ray_len[1] += g->ray.step_size[1];
		if (g->ray.step[1] > 0)
			g->ray.wall_found = SOUTH;
		else
			g->ray.wall_found = NORTH;
	}
	return (len);
}

float	raycasting(t_game *g, float angle)
{
	float	len;

	ray_init(g, angle);
	ray_start(g);
	while (1)
	{
		len = ray_step(g);
		if (g->smap.map[g->ray.map_check[1]][g->ray.map_check[0]] != '0') // Cas de la porte ?
		{
			if(g->smap.map[g->ray.map_check[1]][g->ray.map_check[0]] == /*Porte*/ 0)
				g->ray.wall_found = DOOR;
			break;
		}
	}
	g->ray.impact[0] = g->player.fx + len * cosf(angle) - \
	(int)(g->player.fx + len * cosf(angle));
	g->ray.impact[1] = g->player.fy + len * sinf(angle) - \
	(int)(g->player.fy + len * sinf(angle));
	return (len);
}
