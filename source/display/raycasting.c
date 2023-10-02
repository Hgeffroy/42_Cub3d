/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:06:56 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/01 10:57:53 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	raycasting(t_game *g, float angle)
{
	float	len;
	float	test1;
	float	test2;

	ft_bzero(g->ray->ray_len, 2);
	ft_bzero(g->ray->step, 2);
	g->ray->map_check[0] = (int)g->player->fx;
	g->ray->map_check[1] = (int)g->player->fy;
	g->ray->ray_start[0] = g->player->fx;
	g->ray->ray_start[1] = g->player->fy;
	g->ray->ray_dir[0] = cosf(angle);
	g->ray->ray_dir[1] = sinf(angle);
	g->ray->step_size[0] = sqrt(1 + (g->ray->ray_dir[1] / g->ray->ray_dir[0]) * (g->ray->ray_dir[1] / g->ray->ray_dir[0]));
	g->ray->step_size[1] = sqrt(1 + (g->ray->ray_dir[0] / g->ray->ray_dir[1]) * (g->ray->ray_dir[0] / g->ray->ray_dir[1]));


	if (g->ray->ray_dir[0] < 0)
	{
		g->ray->step[0] = -1;
		g->ray->ray_len[0] = (g->ray->ray_start[0] - (float)(g->ray->map_check[0])) * g->ray->step_size[0];
	}
	else
	{
		g->ray->step[0] = 1;
		g->ray->ray_len[0] = ((float)(g->ray->map_check[0] + 1) - g->ray->ray_start[0]) * g->ray->step_size[0];
	}
	if (g->ray->ray_dir[1] < 0)
	{
		g->ray->step[1] = -1;
		g->ray->ray_len[1] = (g->ray->ray_start[1] - (float)(g->ray->map_check[1])) * g->ray->step_size[1];
	}
	else
	{
		g->ray->step[1] = 1;
		g->ray->ray_len[1] = ((float)(g->ray->map_check[1] + 1) - g->ray->ray_start[1]) * g->ray->step_size[1];
	}

	g->ray->tile_found = false;
	len = 0.0;
	while (!g->ray->tile_found)
	{
		if (g->ray->ray_len[0] < g->ray->ray_len[1])
		{
			g->ray->map_check[0] += g->ray->step[0];
			len = g->ray->ray_len[0];
			g->ray->ray_len[0] += g->ray->step_size[0];
		}
		else
		{
			g->ray->map_check[1] += g->ray->step[1];
			len = g->ray->ray_len[1];
			g->ray->ray_len[1] += g->ray->step_size[1];
		}
		if (g->smap->map[g->ray->map_check[1]][g->ray->map_check[0]] != '0')
			g->ray->tile_found = true;
	}
	return (len);
}