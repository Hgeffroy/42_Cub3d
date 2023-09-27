/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:00:47 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/27 09:20:21 by hgeffroy         ###   ########.fr       */
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
		draw_square(g->minimap, x, y, H_WHITE);
}

void	draw_player(t_game *g)
{
	double	x;
	double	y;

	x = g->player->fx - PLAYER_SZ;
	y = g->player->fy - PLAYER_SZ;
	while (x < g->player->fx + PLAYER_SZ)
	{
		y = g->player->fy - PLAYER_SZ;
		while (y < g->player->fx + PLAYER_SZ)
		{
			if ((pow(x - g->player->fx, 2)) + (pow(y - g->player->fy, 2)) < pow(PLAYER_SZ, 2))
				my_mlx_pixel_put(g->minimap, x, y, H_BLUE);
			y++;
		}
		x++;
	}
}

void	draw_line(t_game *g, float angle)
{
	float	x;
	float	y;
	int		count;

	count = 0;
	x = (float)g->player->fx;
	y = (float)g->player->fy;
	while(count < 100)
	{
		my_mlx_pixel_put(g->minimap, x, y, H_ORANGE);
		x = x + cos(angle);
		y = y + sin(angle);
		count++;
	}
}

void	draw_fov(t_game *g)
{
	float	angle;

	angle = g->player->angle - M_PI / 6;
	while (angle < g->player->angle + M_PI / 6)
	{
		angle += 0.001;
		draw_line(g, angle);
	}
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
	draw_player(g);
}

void	init_minimap(t_game *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, 1920, 1080, "cub3d");
}

int	mlx_close(t_game *g)
{
	(void)g;
	exit (0);
}

int	mlx_play(int keycode, t_game *g)
{
	
	if (keycode == esc_key)
		mlx_close(g);
	return (0);
}

int	init_game(t_game *g)
{
	g->player->fx = g->player->x * TILE_SZ + 0.5 * TILE_SZ;
	g->player->fy = g->player->y * TILE_SZ + 0.5 * TILE_SZ;
	return (0);
}

void	play(t_game *g)
{
	init_game(g);
	init_minimap(g);	
	draw_minimap(g);
	draw_fov(g);
	mlx_put_image_to_window(g->mlx, g->win, g->minimap->img, 0, 0);
	mlx_key_hook(g->win, &mlx_play, g);
	mlx_hook(g->win, 17, 1L << 17, &mlx_close, g);
	mlx_loop(g->mlx);
}