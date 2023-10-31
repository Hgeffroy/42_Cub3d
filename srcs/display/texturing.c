/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 09:49:05 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/31 15:49:03 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

void	draw_floor_ceiling(t_game *g)
{
	int	i;
	int	j;

	j = 0;
	while (j < SCREEN_HEIGHT / 2)
	{
		i = 0;
		while (i < SCREEN_WIDTH)
		{
			my_mlx_pixel_put(&(g->display), i, j, g->colors.hexa_roof);
			i++;
		}
		j++;
	}
	while (j < SCREEN_HEIGHT)
	{
		i = 0;
		while (i < SCREEN_WIDTH)
		{
			my_mlx_pixel_put(&(g->display), i, j, g->colors.hexa_floor);
			i++;
		}
		j++;
	}
}

int	get_color(t_walltext w, int x, int y)
{
	char	*addr;

	addr = w.addr + y * w.line_len + x * (w.bits_per_pixel / 8);
	return (*(unsigned int*)addr);
}

void	wallray_init(t_game *g, t_wallray *wallray)
{
	wallray->angle = g->player.angle - M_PI / 6;
	wallray->x = 0;
	wallray->len = raycasting(g, wallray->angle);
}

void	wallray_init_col(t_game *g, t_wallray *wallray)
{
	wallray->angle = atanf((wallray->x + 0.0001 - (SCREEN_WIDTH / 2)) / \
	(SCREEN_WIDTH * 6 / (2 * M_PI))) + g->player.angle + 0.0001;
	wallray->len = raycasting(g, wallray->angle) * \
	cosf(wallray->angle - g->player.angle);
	wallray->height = SCREEN_DIST * WALL_HEIGHT / wallray->len;
	init_col(g, wallray);
	if (wallray->height > SCREEN_HEIGHT)
		wallray->height = SCREEN_HEIGHT;
	wallray->half_height = wallray->height / 2;
}

int	draw_walls(t_game *g)
{
	t_wallray	wallray;

	wallray_init(g, &wallray);
	while (wallray.x < SCREEN_WIDTH)
	{
		wallray_init_col(g, &wallray);
		while (wallray.height > 0)
		{
			get_wall_color(g, &wallray);
			my_mlx_pixel_put(&(g->display), wallray.x, \
			(SCREEN_HEIGHT / 2) + wallray.height - wallray.half_height, wallray.color);
			wallray.height -= 1;
		}
		wallray.x++;
	}
	return (0);
}

int	draw_display(t_game *g)
{
	draw_floor_ceiling(g);
	draw_walls(g);
	return (0);
}

