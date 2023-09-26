/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:00:47 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/26 17:50:27 by hgeffroy         ###   ########.fr       */
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
		draw_square(g->minimap, x, y, H_WHITE);
	else if (g->smap->map[y][x] - '0' == WALL)
		draw_square(g->minimap, x, y, H_GREY);
	else if (g->smap->map[y][x] == ' ' || g->smap->map[y][x] == '\n')
		draw_square(g->minimap, x, y, H_BLACK);
	else
		draw_square(g->minimap, x, y, H_BLUE);
}

void	draw_minimap(t_game *g)
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
	mlx_put_image_to_window(g->mlx, g->win, g->minimap->img, 0, 0);
}

void	init_minimap(t_game *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, 1920, 1080, "cub3d");
}

void	play(t_game *g)
{
	init_minimap(g);	
	draw_minimap(g);
	mlx_loop(g->mlx);
}