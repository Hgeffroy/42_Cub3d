/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:00:47 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/02 11:02:28 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_img *img, int	x, int y, int color)
{
	int	abs;
	int	ord;

	abs = 0;
	while (abs < TILE_SZ)
	{
		ord = 0;
		while (ord < TILE_SZ)
		{
			my_mlx_pixel_put(img, (x * TILE_SZ) + abs, (y * TILE_SZ) + ord, color);
			ord++;
		}
		abs++;
	}
}

/*Ptr sur fct*/
void	draw_tile(t_game *g, int x, int y)
{
	if (g->smap->map[y][x] - '0' == FTILE)
		draw_square(g->display, x, y, H_WHITE);
	else if (g->smap->map[y][x] - '0' == WALL)
		draw_square(g->display, x, y, H_GREY);
	else if (g->smap->map[y][x] == ' ' || g->smap->map[y][x] == '\n')
	{
		if (y < 1080 / 2)
			draw_square(g->display, x, y, g->colors->hexa_roof);
		else
			draw_square(g->display, x, y, g->colors->hexa_floor);
	}
	else
		draw_square(g->display, x, y, H_WHITE);
}

void	draw_player(t_game *g)
{
	float	x;
	float	y;

	x = g->player->fx * TILE_SZ - PLAYER_SZ;
	while (x < g->player->fx * TILE_SZ + PLAYER_SZ)
	{
		y = g->player->fy - PLAYER_SZ;
		while (y < g->player->fy * TILE_SZ + PLAYER_SZ)
		{
			if ((pow(x - g->player->fx * TILE_SZ, 2)) + (pow(y - g->player->fy * TILE_SZ, 2)) < pow(PLAYER_SZ, 2))
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

	x = g->player->fx * TILE_SZ;
	y = g->player->fy * TILE_SZ;
	ix = (int)g->player->fx;
	iy = (int)g->player->fy;
	while(g->smap->map[iy][ix] == '0')
	{
		my_mlx_pixel_put(g->display, x, y, H_ORANGE);
		x = x + cos(angle);
		y = y + sin(angle);
		ix = (int)(x / TILE_SZ);
		iy = (int)(y / TILE_SZ);
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
	minimap_ray(g, g->player->angle);
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
	int	i;
	int	j;
	
	i = 0;
	while (g->smap->map[i])
	{
		j = 0;
		while (g->smap->map[i][j])
		{
			draw_tile(g, j, i);
			j++;
		}
		i++;
	}
	draw_fov(g); // Voir pour opti, sinon faire 2 fonctions dont une qui ne dessine pas ?
	draw_player(g);
}

