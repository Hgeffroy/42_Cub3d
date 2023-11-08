/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:00:47 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/06 11:17:17 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	minimap_ray(t_data *cub, float angle)
{
	float	coord[2];
	float	pixel[2];
	int		color;
	int		j;

	coord[0] = cub->player.fx;
	coord[1] = cub->player.fy;
	pixel[0] = 7.f * TILE_SZ;
	pixel[1] = 7.f * TILE_SZ;
	color = H_ORANGE;
	j = -1;
	while ((cub->map[(int)coord[1]][(int)coord[0]] == '0'
		|| (cub->map[(int)coord[1]][(int)coord[0]] == 'D'
		&& cub->doors[find_door(cub, coord[0], coord[1])].pos < 0.001))
		&& (pow(pixel[0] - 7 * TILE_SZ, 2)) + (pow(pixel[1] - 7 * TILE_SZ, 2))
		< pow(3 * TILE_SZ, 2))
	{
		if ((H_ORANGE + 3 * ++j * (1 + 256)) % (256 * 256 * 256) > H_ORANGE)
			color = H_ORANGE + 3 * j * (1 + 256);
		pixel_put(&(cub->display), pixel[0], pixel[1], color);
		coord[0] += cosf(angle + cub->player.angle) / TILE_SZ;
		coord[1] += sinf(angle + cub->player.angle) / TILE_SZ;
		pixel[1] -= cos(angle);
		pixel[0] += sin (angle);
	}
	return (0);
}

void	draw_player(t_data *cub)
{
	int	center[2];

	center[0] = 7 * TILE_SZ;
	center[1] = 7 * TILE_SZ;
	draw_fov(cub);
	draw_circle(cub, center, PLAYER_SZ, H_BLUE);
}

void	set_minimap(t_data *cub, t_minimap *minimap)
{
	minimap->ratio = 1.f / (2 * TILE_SZ);
	minimap->center[0] = TILE_SZ * 7;
	minimap->center[1] = TILE_SZ * 7;
	minimap->coord[0] = (cub->player.fy - 6);
	minimap->display[0] = (-1.f) * 6.f * TILE_SZ;
	minimap->display_y_start = (-1.f) * 6.f * TILE_SZ;
	while (minimap->coord[0] < 0)
	{
		minimap->display[0]++;
		minimap->coord[0] += 2 * minimap->ratio;
	}
	minimap->map_y_start = (cub->player.fx - 6);
	while (minimap->map_y_start < 0)
	{
		minimap->display_y_start++;
		minimap->map_y_start += 2 * minimap->ratio;
	}
}

/*
i et j sont les positions en flottants sur la minimap (Le tableau). 
Ils sont donc strictement positifs.
a et b sont les positions en pixel sur le display dont le repere est au center 
de la minimap.
Donc quand j'augmente a de x, i augmente de ratio.
*/
void	draw_minimap(t_data *cub)
{
	t_minimap	m;

	set_minimap(cub, &m);
	while (cub->map[(int)m.coord[0]] && m.coord[0] < cub->player.fy + 6)
	{
		m.coord[1] = m.map_y_start;
		m.display[1] = m.display_y_start;
		while (cub->map[(int)m.coord[0]][(int)m.coord[1]]
			&& m.coord[1] < cub->player.fx + 6)
		{
			if (m.display[0] * m.display[0] + m.display[1]
				* m.display[1] < 6 * 6 * TILE_SZ * TILE_SZ)
				draw_tile(cub, m.display[1], m.display[0], m);
			m.coord[1] += m.ratio;
			m.display[1] += 0.5;
		}
		m.coord[0] += m.ratio;
		m.display[0] += 0.5;
	}
	draw_player(cub);
}
