/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 09:49:05 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/02 15:02:26 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_whitespace(char c)
{
	if (c == ' ' || (c > 8 && c < 13))
		return (YES);
	return (NO);
}

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
	int 	half_height;
	int		x;
	int		color;
	float	y_ratio;
	float	angle;
	float	x_impact;
	float	y_impact;

	angle = g->player->angle - M_PI / 6;
	x = 0;
	// len = raycasting(g, angle);// * cosf(angle - g->player->angle);
	// x_impact = g->player->fx + len * cosf(angle);
	// x_impact = (x_impact - (int)x_impact) * g->north_wall->width;
	// x_impact *= cosf(angle - g->player->angle);
	// y_impact = g->player->fy + len * sinf(angle);
	// y_impact = (y_impact - (int)y_impact) * g->north_wall->width;
	// y_impact *= cosf(angle - g->player->angle);
	// printf("x_impact = %f, y_impact = %f\n", x_impact, y_impact);
	// printf("x_impact_cos = %f, y_impact_cos = %f\n", x_impact * cosf(angle - g->player->angle), y_impact * cosf(angle - g->player->angle));
	// len *= cosf(angle - g->player->angle);
	while (angle < g->player->angle + M_PI / 6)
	{
		len = raycasting(g, angle);// * cosf(angle - g->player->angle);
		x_impact = g->player->fx + len * cosf(angle);
		x_impact = (x_impact - (int)x_impact) * g->north_wall->width;// * fabs(cosf(angle - g->player->angle));
		y_impact = g->player->fy + len * sinf(angle);
		y_impact = (y_impact - (int)y_impact) * g->north_wall->width;// * fabs(cos(angle - g->player->angle));
		len *= cosf(angle - g->player->angle);
		height = SCREEN_DIST * WALL_HEIGHT / len;
		y_ratio = g->north_wall->height / height;
		if (height > 1080)
			height = 1080;
		half_height = height / 2;
		while (height > 0)
		{
			if (g->ray->wall_found == NORTH || g->ray->wall_found == SOUTH)
				color = get_color(g->north_wall, x_impact, (int)(height * y_ratio + g->north_wall->height / 2 - half_height * y_ratio));
			else
				color = get_color(g->north_wall, y_impact, (int)(height * y_ratio + g->north_wall->height / 2 - half_height * y_ratio));
			my_mlx_pixel_put(g->display, x, (1080 / 2) + height - half_height, color);
			height -= 1;
		}
		x++;
		angle += (M_PI / 3) / 1920;
	}
	return (0);
}

int	draw_display(t_game *g)
{
	draw_floor_ceiling(g);
	draw_walls(g);
	return (0);
}

