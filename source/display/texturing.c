/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 09:49:05 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/09 16:17:08 by hgeffroy         ###   ########.fr       */
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
			my_mlx_pixel_put(g->display, i, j, g->colors->hexa_roof);
			i++;
		}
		j++;
	}
	while (j < 1080)
	{
		i = 0;
		while (i < 1920)
		{
			my_mlx_pixel_put(g->display, i, j, g->colors->hexa_floor);
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

int	draw_walls(t_game *g)
{
	float	len;
	float	height;
	float 	half_height;
	int		x;
	int		color;
	float	y_ratio;
	float	angle;
	float	x_impact;
	float	y_impact;

	angle = g->player->angle - M_PI / 6;
	x = 0;
	len = raycasting(g, angle);
	while (x < 1920)
	{
		angle = atanf((x + 0.0001 - (1920 / 2)) / (1920 * 6 / (2 * M_PI))) + g->player->angle + 0.0001;
		len = raycasting(g, angle) * cosf(angle - g->player->angle);
		x_impact = g->ray->impact[0] * g->north_wall->width;
		y_impact = g->ray->impact[1] * g->north_wall->width;
		height = SCREEN_DIST * WALL_HEIGHT / len;
		y_ratio = g->north_wall->height / height;
		if (height > 1080)
			height = 1080;
		half_height = height / 2;
		while (height > 0)
		{
			if (g->ray->wall_found == NORTH || g->ray->wall_found == SOUTH)
				color = get_color(g->north_wall, x_impact, (int)(g->north_wall->height / 2 - (height - half_height) * y_ratio));
			else
				color = get_color(g->north_wall, y_impact, (int)(g->north_wall->height / 2 - (height - half_height) * y_ratio));
			my_mlx_pixel_put(g->display, x, (1080 / 2) + height - half_height, color);
			height -= 1;
		}
		x++;
	}
	return (0);
}

int	draw_display(t_game *g)
{
	draw_floor_ceiling(g);
	draw_walls(g);
	return (0);
}

