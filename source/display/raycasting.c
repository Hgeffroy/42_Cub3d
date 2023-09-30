/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:06:56 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/30 12:10:15 by hgeffroy         ###   ########.fr       */
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
	float	ray_len[2];
	float	ray_start[2];
	float	ray_dir[2];
	float	step_size[2];
	float	len;
	bool	tile_found;
	int		map_check[2];
	int		step[2];

	float	test1;
	float	test2;

	ft_bzero(ray_len, 2);
	ft_bzero(step, 2);
	map_check[0] = g->player->fx / TILE_SZ;
	map_check[1] = g->player->fy / TILE_SZ;
	ray_start[0] = g->player->fx - floor(g->player->fx) + (g->player->fx / TILE_SZ);
	ray_start[1] = g->player->fy - floor(g->player->fy) + (g->player->fy / TILE_SZ);
	ray_dir[0] = cosf(angle);
	ray_dir[1] = sinf(angle);
	step_size[0] = sqrt(1 + (ray_dir[1] / ray_dir[0]) * (ray_dir[1] / ray_dir[0]));
	step_size[1] = sqrt(1 + (ray_dir[0] / ray_dir[1]) * (ray_dir[0] / ray_dir[1]));


	if (ray_dir[0] < 0)
	{
		step[0] = -1;
		ray_len[0] = (ray_start[0] - (float)(map_check[0])) * step_size[0];
	}
	else
	{
		step[0] = 1;
		ray_len[0] = ((float)(map_check[0] + 1) - ray_start[0]) * step_size[0];
	}
	if (ray_dir[1] < 0)
	{
		step[1] = -1;
		ray_len[1] = (ray_start[1] - (float)(map_check[1])) * step_size[1];
	}
	else
	{
		step[1] = 1;
		ray_len[1] = ((float)(map_check[1] + 1) - ray_start[1]) * step_size[1];
	}

	// printf("Putain d'angle de merde : %f et %f\n", ray_dir[0], ray_dir[1]);

	tile_found = false;
	len = 0.0;

	printf("ptdrlol1 %f\n", step_size[0]);
	printf("ptdrlol2 %f\n", step_size[1]);
	
	test1 = step_size[0] * (float)cosf(angle); //* (float)step[1];
	test2 = step_size[1] * (float)sinf(angle); //* (float)step[0];
	
	printf("avant boucle test1: %f\n", test1);
	printf("avant boucle test2: %f\n", test2);

	while (!tile_found) // Mettre un max ?
	{
		printf("len: %f\n", len);
		printf("test1: %f\n", test1);
		printf("test2: %f\n", test2);
		if (ray_len[0] < ray_len[1])
		{
			map_check[0] += step[0];
			ray_len[0] += step_size[0];
			len += test2;
		}
		else
		{
			map_check[1] += step[1];
			ray_len[1] += step_size[1];
			len += test1;
		}
		if (g->smap->map[map_check[1]][map_check[0]] != '0')
			tile_found = true;
	}
	puts("lala");

	// printf("point de collision: %d, %d\n", map_check[0], map_check[1]);
	// printf("lenx = %f, leny = %f\n", ray_len[0], ray_len[1]);

	// printf("len = %f\n", len);
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