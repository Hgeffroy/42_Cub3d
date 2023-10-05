/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:00:47 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/05 15:04:03 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// void	draw_square(t_img *img, int	x, int y, int color)
// {
// 	int	abs;
// 	int	ord;

// 	abs = 0;
// 	while (abs < TILE_SZ)
// 	{
// 		ord = 0;
// 		while (ord < TILE_SZ)
// 		{
// 			my_mlx_pixel_put(img, (x * TILE_SZ) + abs, (y * TILE_SZ) + ord, color);
// 			ord++;
// 		}
// 		abs++;
// 	}
// }

/*Ptr sur fct*/
// void	draw_tile(t_game *g, float x, float y, int a, int b)
// {
// 	if (g->smap->map[(int)y][(int)x] - '0' == FTILE)
// 		my_mlx_pixel_put(g->display, x * TILE_SZ, y * TILE_SZ, H_WHITE);
// 	else if (g->smap->map[(int)y][(int)x] - '0' == WALL)
// 		my_mlx_pixel_put(g->display, x * TILE_SZ, y * TILE_SZ, H_GREY);
// 	else if (g->smap->map[(int)y][(int)x] == ' ' || g->smap->map[(int)y][(int)x] == '\n')
// 	{
// 		if (y < 1080 / 2)
// 			my_mlx_pixel_put(g->display, x * TILE_SZ, y * TILE_SZ, g->colors->hexa_roof);
// 		else
// 			my_mlx_pixel_put(g->display, x * TILE_SZ, y * TILE_SZ, g->colors->hexa_floor);
// 	}
// 	else
// 		my_mlx_pixel_put(g->display, x * TILE_SZ, y * TILE_SZ, H_WHITE);
// }

void	draw_tile(t_game *g, float x, float y, float a, float b, int centre)
{
	float	tmpa;
	float	tmpb;

	
	tmpa = a;
	tmpb = b;
	a = tmpa * cosf((-1) * g->player->angle - M_PI_2) - tmpb * sinf((-1) * g->player->angle - M_PI_2);
	b = tmpa * sinf((-1) * g->player->angle - M_PI_2) + tmpb * cosf((-1) * g->player->angle - M_PI_2);
	if (g->smap->map[(int)y][(int)x] - '0' == FTILE && a + centre >= 0 && b + centre >= 0)
		my_mlx_pixel_put(g->display, a + centre, b + centre, H_WHITE);
	else if (g->smap->map[(int)y][(int)x] - '0' == WALL && a + centre >= 0 && b + centre >= 0)
		my_mlx_pixel_put(g->display, a + centre, b + centre, H_GREY);
}

// void	draw_player(t_game *g)
// {
// 	float	x;
// 	float	y;

// 	x = g->player->fx * TILE_SZ - PLAYER_SZ;
// 	while (x < g->player->fx * TILE_SZ + PLAYER_SZ)
// 	{
// 		y = g->player->fy - PLAYER_SZ;
// 		while (y < g->player->fy * TILE_SZ + PLAYER_SZ)
// 		{
// 			if ((pow(x - g->player->fx * TILE_SZ, 2)) + (pow(y - g->player->fy * TILE_SZ, 2)) < pow(PLAYER_SZ, 2))
// 				my_mlx_pixel_put(g->display, x, y, H_BLUE);
// 			y++;
// 		}
// 		x++;
// 	}
// }

void	draw_player(t_game *g)
{
	float	x;
	float	y;

	x = 7 * TILE_SZ - PLAYER_SZ;
	while (x < 7 * TILE_SZ + PLAYER_SZ)
	{
		y = 7 * TILE_SZ - PLAYER_SZ;
		while (y < 7 * TILE_SZ + PLAYER_SZ)
		{
			if ((pow(x - 7 * TILE_SZ, 2)) + (pow(y - 7 * TILE_SZ, 2)) < pow(PLAYER_SZ, 2))
				my_mlx_pixel_put(g->display, x, y, H_BLUE);
			y++;
		}
		x++;
	}
}

float	minimap_ray(t_game *g, float angle)
{
	float	x;
	float	y;
	int		ix;
	int		iy;

	x = g->player->fx;
	y = g->player->fy;
	ix = 7 * TILE_SZ;
	iy = 7 * TILE_SZ;
	while(g->smap->map[(int)y][(int)x] == '0' && (pow(ix - 7 * TILE_SZ, 2)) + (pow(iy - 7 * TILE_SZ, 2)) < pow(6 * TILE_SZ, 2))
	{
		my_mlx_pixel_put(g->display, ix, iy, H_ORANGE);
		x = x + cosf(angle) / TILE_SZ;
		y = y + sinf(angle) / TILE_SZ;
		iy -= 1;
		printf("x = %f\n", x);
		printf("y = %f\n", y);
	}
	return (0);
}

void	draw_fov(t_game *g)
{
	float	angle;

	// angle = g->player->angle - M_PI / 6;
	// while (angle < g->player->angle + M_PI / 6)
	// {
	// 	angle += 0.003;
	// 	minimap_ray(g, angle);
	// }
	minimap_ray(g, M_PI_2);
}
void	init_minimap(t_game *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, 1920, 1080, "cub3d");
	g->display->img = mlx_new_image(g->mlx, 1920, 1080);
	g->display->addr = mlx_get_data_addr(g->display->img, &g->display->bits_per_pixel, &g->display->line_len, \
								&g->display->endian);
}

void	draw_minimap(t_game *g)
{
	float	a;
	float	b;
	int		b_start;
	int		centre;
	float	i;
	float	j;
	float	j_start;
	float	ratio;

	ratio = 1.f / TILE_SZ;
	i = (g->player->fy - 6);
	centre = TILE_SZ * 7;
	a = (-1) * 6 * TILE_SZ;
	b_start = (-1) * 6 * TILE_SZ;
	while (i < 0)
	{
		a++;
		i += ratio;
	}
	j_start = (g->player->fx - 6);
	while (j_start < 0)
	{
		b_start++;
		j_start += ratio;
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
			b++;
		}
		i += ratio;
		a++;
	}
	// draw_fov(g); // Voir pour opti, sinon faire 2 fonctions dont une qui ne dessine pas ?
	draw_player(g);
}


