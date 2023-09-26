/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:00:47 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/26 15:54:48 by hgeffroy         ###   ########.fr       */
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
	ord = 0;
	while (abs < TILE_SZ)
	{
		while (ord < TILE_SZ)
		{
			my_mlx_pixel_put(img, x * TILE_SZ + abs, y * TILE_SZ + ord, color);
			ord++;
		}
		abs++;
	}
}

void	draw_tile(t_game *g, int x, int y)
{
	if ()
}

int	draw_minimap(t_game *g)
{
	int	i;
	int	j;
	
	g->minimap->img = mlx_new_image(g->mlx, 1920, 1080);
	g->minimap->addr = mlx_get_data_addr(g->minimap->img, &g->minimap->bits_per_pixel, &g->minimap->line_len, \
								&g->minimap->endian);
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
}

int	init_minimap(t_game *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, 1920, 1080, "cub3d");
	mlx_loop(g->mlx);
}

int	play(t_game *g)
{
	init_minimap(g);
}