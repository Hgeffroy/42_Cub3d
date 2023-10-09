/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:00:47 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/09 08:42:17 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_tile(t_game *g, float x, float y, float a, float b, int *centre)
{
	float	tmpa;
	float	tmpb;

	
	tmpa = a;
	tmpb = b;
	a = tmpa * cosf((-1) * g->player->angle - M_PI_2) - tmpb * sinf((-1) * g->player->angle - M_PI_2);
	b = tmpa * sinf((-1) * g->player->angle - M_PI_2) + tmpb * cosf((-1) * g->player->angle - M_PI_2);
	if (g->smap->map[(int)y][(int)x] - '0' == FTILE && a + centre[0] >= 0 && b + centre[1] >= 0)
		my_mlx_pixel_put(g->display, a + centre[0], b + centre[1], H_WHITE);
	else if (g->smap->map[(int)y][(int)x] - '0' == WALL && a + centre[0] >= 0 && b + centre[1] >= 0)
		my_mlx_pixel_put(g->display, a + centre[0], b + centre[1], H_GREY);
}

void	draw_circle(t_game *g, int *centre, int radius, int color)
{
	int	x;
	int	y;
	
	x = centre[0] - radius;
	while (x < centre[0] + radius)
	{
		y = centre[1] - radius;
		while (y < centre[1] + radius)
		{
			if ((pow(x - centre[0], 2)) + (pow(y - centre[1], 2)) < pow(radius, 2))
				my_mlx_pixel_put(g->display, x, y, color);
			y++;
		}
		x++;
	}
}

float	minimap_ray(t_game *g, float angle, int i)
{
	float	x;
	float	y;
	float	ix;
	float	iy;
	float	ratio;

	int		color = H_ORANGE;
	int		j = 0;
	
	x = g->player->fx;
	y = g->player->fy;
	ix = 7.f * TILE_SZ;
	iy = 7.f * TILE_SZ;
	ratio = 1;
	ratio = 1.f + (i % 5) * 0.01;
	while(g->smap->map[(int)y][(int)x] == '0' && (pow(ix - 7 * TILE_SZ, 2)) + (pow(iy - 7 * TILE_SZ, 2)) < pow(3 * TILE_SZ, 2))
	{
		if ((H_ORANGE + 3 * j * (1 + 256)) % (256 * 256 * 256) > H_ORANGE)
			color = H_ORANGE + 3 * j * (1 + 256);
		my_mlx_pixel_put(g->display, ix, iy, color);
		ratio = pow(ratio, 1.25);
		x += ratio * cosf(angle + g->player->angle) / TILE_SZ;
		y += ratio * sinf(angle + g->player->angle) / TILE_SZ;
		iy -= ratio * cos(angle);
		ix += ratio * sin (angle);
		j++;
	}
	return (0);
}

void	draw_fov(t_game *g)
{
	float	angle;
	int		i;

	angle = M_PI / 6 * (- 1);
	i = 0;
	while (angle < M_PI / 6)
	{
		i++;
		angle += 0.01;
		minimap_ray(g, angle, i);
	}
}

void	draw_player(t_game *g)
{
	int	centre[2];

	centre[0] = 7 * TILE_SZ;
	centre[1] = 7 * TILE_SZ;
	draw_fov(g);
	draw_circle(g, centre, PLAYER_SZ, H_BLUE);
}


void	init_minimap(t_game *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, 1920, 1080, "cub3d");
	g->display->img = mlx_new_image(g->mlx, 1920, 1080);
	g->display->addr = mlx_get_data_addr(g->display->img, &g->display->bits_per_pixel, &g->display->line_len, \
								&g->display->endian);
}


/*
i et j sont les positions en flottants sur la minimap (Le tableau). Ils sont donc strictement positifs
a et b sont les positions en pixel sur le display dont le repere est au centre de la minimap.
Donc quand j'augmente a de x, i augmente de ratio.
*/
// void	draw_minimap(t_game *g)
// {
// 	float	a;
// 	float	b;
// 	int		b_start;
// 	int		centre[2];
// 	float	i;
// 	float	j;
// 	float	j_start;
// 	float	ratio;

// 	ratio = 1.f / TILE_SZ;
// 	centre[0] = TILE_SZ * 7;
// 	centre[1] = TILE_SZ * 7;
// 	i = (g->player->fy - 6);
// 	a = (-1) * 6 * TILE_SZ;
// 	b_start = (-1) * 6 * TILE_SZ;
// 	while (i < 0)
// 	{
// 		a++;
// 		i += ratio;
// 	}
// 	j_start = (g->player->fx - 6);
// 	while (j_start < 0)
// 	{
// 		b_start++;
// 		j_start += ratio;
// 	}
// 	while (g->smap->map[(int)i] && i < g->player->fy + 6)
// 	{
// 		j = j_start;
// 		b = b_start;
// 		while (g->smap->map[(int)i][(int)j] && j < g->player->fx + 6)
// 		{
// 			if (a * a + b * b < 6 * 6 * TILE_SZ * TILE_SZ)
// 				draw_tile(g, j, i, b, a, centre);
// 			j += ratio;
// 			b++;
// 		}
// 		i += ratio;
// 		a++;
// 	}
// 	draw_player(g);
// }

/*
i et j sont les positions en flottants sur la minimap (Le tableau). Ils sont donc strictement positifs
a et b sont les positions en pixel sur le display dont le repere est au centre de la minimap.
Donc quand j'augmente a de x, i augmente de ratio.
*/
void	draw_minimap(t_game *g)
{
	float	a;
	float	b;
	int		b_start;
	int		centre[2];
	float	i;
	float	j;
	float	j_start;
	float	ratio;

	ratio = 1.f / (2 * TILE_SZ);
	centre[0] = TILE_SZ * 7;
	centre[1] = TILE_SZ * 7;
	i = (g->player->fy - 6);
	a = (-1.f) * 6.f * TILE_SZ;
	b_start = (-1.f) * 6.f * TILE_SZ;
	while (i < 0)
	{
		a++;
		i += 2 * ratio;
	}
	j_start = (g->player->fx - 6);
	while (j_start < 0)
	{
		b_start++;
		j_start += 2 * ratio;
	}
	while (g->smap->map[(int)i] && i < g->player->fy + 6)
	{
		j = j_start;
		b = b_start;
		while (g->smap->map[(int)i][(int)j] && j < g->player->fx + 6)
		{
			if (a * a + b * b < 6 * 6 * TILE_SZ * TILE_SZ)
				draw_tile(g, j, i, b, a, centre);
			j += ratio;
			b += 0.5;
		}
		i += ratio;
		a += 0.5;
	}
	draw_player(g);
}


