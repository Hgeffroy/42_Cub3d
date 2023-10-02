/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 09:49:05 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/01 14:15:51 by hgeffroy         ###   ########.fr       */
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
	int		bits_per_pixel;
	int		line_len;
	int		endian;

	addr = mlx_get_data_addr(w->img, &bits_per_pixel, &line_len, &endian);
	addr = addr + y * line_len + x * (bits_per_pixel / 8);
	return (*(unsigned int*)addr);
}

int	draw_walls(t_game *g)
{
	float	len;
	float	height;
	int 	half_height;
	int		x;
	int		width;
	int		color;
	float	y_ratio;
	float	x_ratio;
	float	angle;

	angle = g->player->angle - M_PI / 6;
	x = 0;
	while (angle < g->player->angle + M_PI / 6)
	{
		len = raycasting(g, angle) * cosf(angle - g->player->angle);
		height = SCREEN_DIST * WALL_HEIGHT / len;
		y_ratio = g->north_wall->height / height;
		if (height > 1080)
			height = 1080;
		half_height = height / 2;
		while (height > 0)
		{
			color = get_color(g->north_wall, 10, (int)(height * y_ratio));
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

