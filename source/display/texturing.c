/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 09:49:05 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/11 07:45:49 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor_ceiling(t_game *g)
{
	int	i;
	int	j;

	j = 0;
	while (j < 1080 / 2)
	{
		i = 0;
		while (i < 1920)
		{
			my_mlx_pixel_put(&(g->display), i, j, g->colors->hexa_roof);
			i++;
		}
		j++;
	}
	while (j < 1080)
	{
		i = 0;
		while (i < 1920)
		{
			my_mlx_pixel_put(&(g->display), i, j, g->colors->hexa_floor);
			i++;
		}
		j++;
	}
}

int	get_color(t_walltext *w, int x, int y)
{
	char	*addr;

	addr = w->addr + y * w->line_len + x * (w->bits_per_pixel / 8);
	return (*(unsigned int*)addr);
}

void	wallray_init(t_game *g, t_wallray *wallray)
{
	wallray->angle = g->player->angle - M_PI / 6;
	wallray->x = 0;
	wallray->len = raycasting(g, wallray->angle);
}

void	wallray_init_col(t_game *g, t_wallray *wallray)
{
	wallray->angle = atanf((wallray->x + 0.0001 - (1920 / 2)) / \
	(1920 * 6 / (2 * M_PI))) + g->player->angle + 0.0001;
	wallray->len = raycasting(g, wallray->angle) * \
	cosf(wallray->angle - g->player->angle);
	wallray->x_impact = g->ray.impact[0] * g->north_wall->width;
	wallray->y_impact = g->ray.impact[1] * g->north_wall->width;
	wallray->height = SCREEN_DIST * WALL_HEIGHT / wallray->len;
	wallray->y_ratio = g->north_wall->height / wallray->height;
	if (wallray->height > 1080)
		wallray->height = 1080;
	wallray->half_height = wallray->height / 2;
}

int	draw_walls(t_game *g)
{
	t_wallray	wallray;

	wallray_init(g, &wallray);
	while (wallray.x < 1920)
	{
		wallray_init_col(g, &wallray);
		while (wallray.height > 0)
		{
			if (g->ray.wall_found == NORTH || g->ray.wall_found == SOUTH)
				wallray.color = get_color(g->north_wall, wallray.x_impact, \
				(int)(g->north_wall->height / 2 - \
				(wallray.height - wallray.half_height) * wallray.y_ratio));
			else
				wallray.color = get_color(g->north_wall, wallray.y_impact, \
				(int)(g->north_wall->height / 2 - \
				(wallray.height - wallray.half_height) * wallray.y_ratio));
			my_mlx_pixel_put(&(g->display), wallray.x, \
			(1080 / 2) + wallray.height - wallray.half_height, wallray.color);
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

