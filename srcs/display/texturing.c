/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 09:49:05 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/01 12:35:39 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_floor_ceiling(t_data *cub)
{
	int	i;
	int	j;

	j = 0;
	while (j < SCREEN_HEIGHT / 2)
	{
		i = 0;
		while (i < SCREEN_WIDTH)
		{
			my_mlx_pixel_put(&(cub->display), i, j, cub->rgb_c);
			i++;
		}
		j++;
	}
	while (j < SCREEN_HEIGHT)
	{
		i = 0;
		while (i < SCREEN_WIDTH)
		{
			my_mlx_pixel_put(&(cub->display), i, j, cub->rgb_f);
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

void	wallray_init(t_data *cub, t_wallray *wallray)
{
	wallray->angle = cub->player.angle - M_PI / 6;
	wallray->x = 0;
	wallray->len = raycasting(cub, wallray->angle);
}

void	wallray_init_col(t_data *cub, t_wallray *wallray)
{
	wallray->angle = atanf((wallray->x + 0.0001 - (SCREEN_WIDTH / 2)) / \
	(SCREEN_WIDTH * 6 / (2 * M_PI))) + cub->player.angle + 0.0001;
	wallray->len = raycasting(cub, wallray->angle) * \
	cosf(wallray->angle - cub->player.angle);
	wallray->height = SCREEN_DIST * WALL_HEIGHT / wallray->len;
	init_col(cub, wallray);
	if (wallray->height > SCREEN_HEIGHT)
		wallray->height = SCREEN_HEIGHT;
	wallray->half_height = wallray->height / 2;
}

int	draw_walls(t_data *cub)
{
	t_wallray	wallray;

	wallray_init(cub, &wallray);
	while (wallray.x < SCREEN_WIDTH)
	{
		wallray_init_col(cub, &wallray);
		while (wallray.height > 0)
		{
			get_wall_color(cub, &wallray);
			my_mlx_pixel_put(&(cub->display), wallray.x - 1, \
			(SCREEN_HEIGHT / 2) + wallray.height - wallray.half_height, \
			wallray.color);
			wallray.height -= 1;
		}
		wallray.x++;
	}
	return (0);
}

int	draw_display(t_data *cub)
{
	draw_floor_ceiling(cub);
	draw_walls(cub);
	return (0);
}

