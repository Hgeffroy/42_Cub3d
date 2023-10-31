/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:00:47 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/31 16:55:24 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_tile(t_data *cub, float x, float y, float a, float b, int *centre)
{
	float	tmpa;
	float	tmpb;

	tmpa = a;
	tmpb = b;
	a = tmpa * cosf((-1) * cub->player.angle - M_PI_2) - \
	tmpb * sinf((-1) * cub->player.angle - M_PI_2);
	b = tmpa * sinf((-1) * cub->player.angle - M_PI_2) + \
	tmpb * cosf((-1) * cub->player.angle - M_PI_2);
	if (cub->map[(int)y][(int)x] - '0' == FTILE
		&& a + centre[0] >= 0 && b + centre[1] >= 0)
		my_mlx_pixel_put(&(cub->display), a + centre[0], b + centre[1],
			H_WHITE);
	else if (cub->map[(int)y][(int)x] - '0' == WALL
		&& a + centre[0] >= 0 && b + centre[1] >= 0)
		my_mlx_pixel_put(&(cub->display), a + centre[0], b + centre[1], H_GREY);
}

void	draw_circle(t_data *cub, int *centre, int radius, int color)
{
	int	x;
	int	y;

	x = centre[0] - radius;
	while (x < centre[0] + radius)
	{
		y = centre[1] - radius;
		while (y < centre[1] + radius)
		{
			if ((pow(x - centre[0], 2)) + (pow(y - centre[1], 2)) \
			< pow(radius, 2))
				my_mlx_pixel_put(&(cub->display), x, y, color);
			y++;
		}
		x++;
	}
}

float	minimap_ray(t_data *cub, float angle)
{
	float	x;
	float	y;
	float	ix;
	float	iy;

	int		color = H_ORANGE;
	int		j = 0;

	x = cub->player.fx;
	y = cub->player.fy;
	ix = 7.f * TILE_SZ;
	iy = 7.f * TILE_SZ;
	while (cub->map[(int)y][(int)x] == '0' && (pow(ix - 7 * TILE_SZ, 2))
		+ (pow(iy - 7 * TILE_SZ, 2)) < pow(3 * TILE_SZ, 2))
	{
		if ((H_ORANGE + 3 * j * (1 + 256)) % (256 * 256 * 256) > H_ORANGE)
			color = H_ORANGE + 3 * j * (1 + 256);
		my_mlx_pixel_put(&(cub->display), ix, iy, color);
		x += cosf(angle + cub->player.angle) / TILE_SZ;
		y += sinf(angle + cub->player.angle) / TILE_SZ;
		iy -= cos(angle);
		ix += sin (angle);
		j++;
	}
	return (0);
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

void	draw_player(t_data *cub)
{
	int	centre[2];

	centre[0] = 7 * TILE_SZ;
	centre[1] = 7 * TILE_SZ;
	draw_fov(cub);
	draw_circle(cub, centre, PLAYER_SZ, H_BLUE);
}


void	init_minimap(t_data *cub)
{
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	cub->display.img = mlx_new_image(cub->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	cub->display.addr = mlx_get_data_addr(cub->display.img,
			&cub->display.bits_per_pixel, &cub->display.line_len,
			&cub->display.endian);
}

void	set_minimap(t_data *cub, t_minimap *minimap)
{
	minimap->ratio = 1.f / (2 * TILE_SZ);
	minimap->center[0] = TILE_SZ * 7;
	minimap->center[1] = TILE_SZ * 7;
	minimap->map_x = (cub->player.fy - 6);
	minimap->display_x = (-1.f) * 6.f * TILE_SZ;
	minimap->display_y_start = (-1.f) * 6.f * TILE_SZ;
	while (minimap->map_x < 0)
	{
		minimap->display_x++;
		minimap->map_x += 2 * minimap->ratio;
	}
	minimap->map_y_start = (cub->player.fx - 6);
	while (minimap->map_y_start < 0)
	{
		minimap->display_y_start++;
		minimap->map_y_start += 2 * minimap->ratio;
	}
}

/*
i et j sont les positions en flottants sur la minimap (Le tableau). Ils sont donc strictement positifs
a et b sont les positions en pixel sur le display dont le repere est au centre de la minimap.
Donc quand j'augmente a de x, i augmente de ratio.
*/
void	draw_minimap(t_data *cub)
{
	t_minimap	minimap;

	set_minimap(cub, &minimap);
	while (cub->map[(int)minimap.map_x] && minimap.map_x < cub->player.fy + 6)
	{
		minimap.map_y = minimap.map_y_start;
		minimap.display_y = minimap.display_y_start;
		while (cub->map[(int)minimap.map_x][(int)minimap.map_y] && \
		minimap.map_y < cub->player.fx + 6)
		{
			if (minimap.display_x * minimap.display_x + minimap.display_y * \
			minimap.display_y < 6 * 6 * TILE_SZ * TILE_SZ)
				draw_tile(cub, minimap.map_y, minimap.map_x, minimap.display_y, \
				minimap.display_x, minimap.center);
			minimap.map_y += minimap.ratio;
			minimap.display_y += 0.5;
		}
		minimap.map_x += minimap.ratio;
		minimap.display_x += 0.5;
	}
	draw_player(cub);
}


