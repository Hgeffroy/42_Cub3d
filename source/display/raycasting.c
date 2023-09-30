/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:06:56 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/30 13:02:40 by hgeffroy         ###   ########.fr       */
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
			my_mlx_pixel_put(g->minimap, i, j, H_BLACK);
			i++;
		}
		j++;
	}
	while (j < 1080)
	{
		i = 0;
		while (i < 1920)
		{
			my_mlx_pixel_put(g->minimap, i, j, H_BLACK);
			i++;
		}
		j++;
	}
}

float	raycasting(t_game *g, float angle)
{
	t_ray	*ray;

	float	len;
	float	test1;
	float	test2;

	ray = (t_ray *)malloc(sizeof(t_ray));
	ft_bzero(ray->ray_len, 2);
	ft_bzero(ray->step, 2);
	ray->map_check[0] = g->player->fx / TILE_SZ;
	ray->map_check[1] = g->player->fy / TILE_SZ;
	ray->ray_start[0] = g->player->fx - floor(g->player->fx) + (g->player->fx / TILE_SZ);
	ray->ray_start[1] = g->player->fy - floor(g->player->fy) + (g->player->fy / TILE_SZ);
	ray->ray_dir[0] = cosf(angle);
	ray->ray_dir[1] = sinf(angle);
	ray->step_size[0] = sqrt(1 + (ray->ray_dir[1] / ray->ray_dir[0]) * (ray->ray_dir[1] / ray->ray_dir[0]));
	ray->step_size[1] = sqrt(1 + (ray->ray_dir[0] / ray->ray_dir[1]) * (ray->ray_dir[0] / ray->ray_dir[1]));


	if (ray->ray_dir[0] < 0)
	{
		ray->step[0] = -1;
		ray->ray_len[0] = (ray->ray_start[0] - (float)(ray->map_check[0])) * ray->step_size[0];
	}
	else
	{
		ray->step[0] = 1;
		ray->ray_len[0] = ((float)(ray->map_check[0] + 1) - ray->ray_start[0]) * ray->step_size[0];
	}
	if (ray->ray_dir[1] < 0)
	{
		ray->step[1] = -1;
		ray->ray_len[1] = (ray->ray_start[1] - (float)(ray->map_check[1])) * ray->step_size[1];
	}
	else
	{
		ray->step[1] = 1;
		ray->ray_len[1] = ((float)(ray->map_check[1] + 1) - ray->ray_start[1]) * ray->step_size[1];
	}

	ray->tile_found = false;
	len = 0.0;

	printf("ray len premiere case en x: %f\n", ray->ray_len[0]);
	printf("ray len premiere case en y: %f\n", ray->ray_len[1]);

	while (!ray->tile_found) // Mettre un max ?
	{
		if (ray->ray_len[0] < ray->ray_len[1])
		{
			ray->map_check[0] += ray->step[0];
			ray->ray_len[0] += ray->step_size[0];
		}
		else
		{
			ray->map_check[1] += ray->step[1];
			ray->ray_len[1] += ray->step_size[1];
		}
		if (g->smap->map[ray->map_check[1]][ray->map_check[0]] != '0')
			ray->tile_found = true;
	}
	puts("lala");

	if (ray->ray_len[0] < ray->ray_len[1])
		len = ray->ray_len[0];
	else
		len = ray->ray_len[1];

	// printf("point de collision: %d, %d\n", map_check[0], map_check[1]);
	// printf("lenx = %f, leny = %f\n", ray_len[0], ray_len[1]);
	printf("len = %f\n", len);
	
	return (fabs(len) * (float)TILE_SZ);
}

int	draw_walls(t_game *g)
{
	float	len;
	float	height;
	int 	half_height;
	int		width;
	float	angle;

	angle = g->player->angle - M_PI / 6;
	width = 0;
	len = raycasting(g, g->player->angle);
	
	// while (angle < g->player->angle + M_PI / 6)
	// {
	// 	len = raycasting(g, angle);
	// 	height = SCREEN_DIST * WALL_HEIGHT / len;
	// 	if (height > 1080)
	// 		height = 1080;
	// 	half_height = height / 2;
	// 	while (height > 0)
	// 	{
	// 		my_mlx_pixel_put(g->minimap, width, (1080 / 2) + height - half_height, H_WHITE);
	// 		height -= 1;
	// 	}
	// 	width++;
	// 	angle += (M_PI / 3) / 1920;
	// }
	return (0);
}

int	draw_display(t_game *g)
{
	// printf("angle = %f\n", g->player->angle);
	draw_floor_ceiling(g);
	// printf("len = %f\n", raycasting(g, g->player->angle));
	draw_walls(g);
	return (0);
}