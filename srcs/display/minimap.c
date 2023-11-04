/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:00:47 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/04 14:48:50 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_tile(t_data *cub, float *coord, float a, float b, int *center)
{
	float	tmpa;
	float	tmpb;

	tmpa = a;
	tmpb = b;
	a = tmpa * cosf((-1) * cub->player.angle - M_PI_2) - \
	tmpb * sinf((-1) * cub->player.angle - M_PI_2);
	b = tmpa * sinf((-1) * cub->player.angle - M_PI_2) + \
	tmpb * cosf((-1) * cub->player.angle - M_PI_2);
	if (cub->map[(int)coord[0]][(int)coord[1]] - '0' == FTILE
		&& a + center[0] >= 0 && b + center[1] >= 0)
		my_mlx_pixel_put(&(cub->display), a + center[0], b + center[1],
			H_WHITE);
	else if (cub->map[(int)coord[0]][(int)coord[1]] - '0' == WALL
		&& a + center[0] >= 0 && b + center[1] >= 0)
		my_mlx_pixel_put(&(cub->display), a + center[0], b + center[1], H_GREY);
	else if (cub->map[(int)coord[0]][(int)coord[1]] == 'D'
		&& a + center[0] >= 0 && b + center[1] >= 0)
	{
		if (cub->doors[find_door(cub, coord[1], coord[0])].pos > 0.001)
			my_mlx_pixel_put(&(cub->display), a + center[0], b + center[1], H_BLUE);
		else
			my_mlx_pixel_put(&(cub->display), a + center[0], b + center[1], H_WHITE);
	}
}

void	draw_circle(t_data *cub, int *center, int radius, int color)
{
	int	x;
	int	y;

	x = center[0] - radius;
	while (x < center[0] + radius)
	{
		y = center[1] - radius;
		while (y < center[1] + radius)
		{
			if ((pow(x - center[0], 2)) + (pow(y - center[1], 2)) \
			< pow(radius, 2))
				my_mlx_pixel_put(&(cub->display), x, y, color);
			y++;
		}
		x++;
	}
}

float	minimap_ray(t_data *cub, float angle)
{
	float	x;
	float	y;
	float	ix;
	float	iy;
	int		color;
	int		j = 0;

	x = cub->player.fx;
	y = cub->player.fy;
	ix = 7.f * TILE_SZ;
	iy = 7.f * TILE_SZ;
	while ((cub->map[(int)y][(int)x] == '0' || (cub->map[(int)y][(int)x] == 'D' \
			&& cub->doors[find_door(cub, x, y)].pos < 0.001)) && \
			(pow(ix - 7 * TILE_SZ, 2)) + (pow(iy - 7 * TILE_SZ, 2)) \
			< pow(3 * TILE_SZ, 2))
	{
		if ((H_ORANGE + 3 * j * (1 + 256)) % (256 * 256 * 256) > H_ORANGE)
			color = H_ORANGE + 3 * j * (1 + 256);
		my_mlx_pixel_put(&(cub->display), ix, iy, color);
		x += cosf(angle + cub->player.angle) / TILE_SZ;
		y += sinf(angle + cub->player.angle) / TILE_SZ;
		iy -= cos(angle);
		ix += sin (angle);
		j++;
	}
	return (0);
}

void	draw_fov(t_data *cub)
{
	float	angle;
	int		i;

	angle = M_PI / 6 * (-1);
	i = 0;
	while (angle < M_PI / 6)
	{
		i++;
		angle += 0.01;
		minimap_ray(cub, angle);
	}
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
i et j sont les positions en flottants sur la minimap (Le tableau). Ils sont donc strictement positifs
a et b sont les positions en pixel sur le display dont le repere est au center de la minimap.
Donc quand j'augmente a de x, i augmente de ratio.
*/
void	draw_minimap(t_data *cub)
{
	t_minimap	minimap;

	set_minimap(cub, &minimap);
	while (cub->map[(int)minimap.coord[0]] && minimap.coord[0] < cub->player.fy + 6)
	{
		minimap.coord[1] = minimap.map_y_start;
		minimap.display[1] = minimap.display_y_start;
		while (cub->map[(int)minimap.coord[0]][(int)minimap.coord[1]] && \
		minimap.coord[1] < cub->player.fx + 6)
		{
			if (minimap.display[0] * minimap.display[0] + minimap.display[1] * \
			minimap.display[1] < 6 * 6 * TILE_SZ * TILE_SZ)
				draw_tile(cub, minimap.coord, minimap.display[1], \
				minimap.display[0], minimap.center);
			minimap.coord[1] += minimap.ratio;
			minimap.display[1] += 0.5;
		}
		minimap.coord[0] += minimap.ratio;
		minimap.display[0] += 0.5;
	}
	draw_player(cub);
}


