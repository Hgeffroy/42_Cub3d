/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:26:26 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/06 09:27:55 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_circle(t_data *cub, int *center, int radius, int color)
{
	int	x;
	int	y;

	x = center[0] - radius;
	while (x < center[0] + radius)
	{
		y = center[1] - radius;
		while (y < center[1] + radius)
		{
			if ((pow(x - center[0], 2)) + (pow(y - center[1], 2))
				< pow(radius, 2))
				pixel_put(&(cub->display), x, y, color);
			y++;
		}
		x++;
	}
}

void	draw_fov(t_data *cub)
{
	float	angle;
	int		i;

	angle = M_PI / 6 * (-1);
	i = 0;
	while (angle < M_PI / 6)
	{
		i++;
		angle += 0.01;
		minimap_ray(cub, angle);
	}
}

void	draw_tile(t_data *cub, float a, float b, t_minimap m)
{
	float	tmpa;
	float	tmpb;

	tmpa = a;
	tmpb = b;
	a = tmpa * cosf((-1) * cub->player.angle - M_PI_2) - \
	tmpb * sinf((-1) * cub->player.angle - M_PI_2);
	b = tmpa * sinf((-1) * cub->player.angle - M_PI_2) + \
	tmpb * cosf((-1) * cub->player.angle - M_PI_2);
	if (cub->map[(int)m.coord[0]][(int)m.coord[1]] - '0' == FTILE
		&& a + m.center[0] >= 0 && b + m.center[1] >= 0)
		pixel_put(&(cub->display), a + m.center[0], b + m.center[1], H_WHITE);
	else if (cub->map[(int)m.coord[0]][(int)m.coord[1]] - '0' == WALL
		&& a + m.center[0] >= 0 && b + m.center[1] >= 0)
		pixel_put(&(cub->display), a + m.center[0], b + m.center[1], H_GREY);
	else if (cub->map[(int)m.coord[0]][(int)m.coord[1]] == 'D'
		&& a + m.center[0] >= 0 && b + m.center[1] >= 0)
	{
		if (cub->doors[find_door(cub, m.coord[1], m.coord[0])].pos > 0.001)
			pixel_put(&(cub->display), a + m.center[0], b + m.center[1], \
																	H_BLUE);
		else
			pixel_put(&(cub->display), a + m.center[0], b + m.center[1], \
																	H_WHITE);
	}
}
