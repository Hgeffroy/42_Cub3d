/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_doors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:03:00 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/06 11:46:50 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	test_north(t_data *cub, float angle, float *len, int doornb);
int	test_south(t_data *cub, float angle, float *len, int doornb);
int	test_west(t_data *cub, float angle, float *len, int doornb);
int	test_east(t_data *cub, float angle, float *len, int doornb);

int	test(t_data *cub, float angle, float *len, int optn)
{
	static t_ray_wall	tab[] = {&test_north, &test_south,
		&test_west, &test_east};
	int					doornb;

	if (optn)
	{
		cub->ray.wall_found = DOOR;
		return (1);
	}
	doornb = find_door(cub, cub->ray.map_check[0], cub->ray.map_check[1]);
	return ((*tab[cub->ray.wall_found])(cub, angle, len, doornb));
}

int	test_north(t_data *cub, float angle, float *len, int doornb)
{
	float	dx;
	float	dy;

	dx = 0;
	dy = 0;
	cub->ray.door_type = cub->ray.wall_found;
	cub->ray.wall_found = DOOR;
	if (cub->player.fx + *len * cosf(angle)
		- (int)(cub->player.fx + *len * cosf(angle)) < cub->doors[doornb].pos)
		return (1);
	if (!(angle > M_PI && angle <= 3 * M_PI_2))
		return (0);
	dx = cub->player.fx + *len * cosf(angle)
		- (int)(cub->player.fx + *len * cosf(angle));
	dx = dx - cub->doors[doornb].pos;
	dy = dx * tanf(M_PI_2 - (3 * M_PI_2 - angle));
	if (dy < 1)
	{
		*len += sqrtf(dx * dx + dy * dy);
		cub->ray.wall_found = WEST;
		return (1);
	}
	return (0);
}

int	test_south(t_data *cub, float angle, float *len, int doornb)
{
	float	dx;
	float	dy;

	dx = 0;
	dy = 0;
	cub->ray.door_type = cub->ray.wall_found;
	cub->ray.wall_found = DOOR;
	if (cub->player.fx + *len * cosf(angle)
		- (int)(cub->player.fx + *len * cosf(angle)) < cub->doors[doornb].pos)
		return (1);
	if (!(angle > M_PI_2 && angle <= M_PI))
		return (0);
	dx = cub->player.fx + *len * cosf(angle)
		- (int)(cub->player.fx + *len * cosf(angle));
	dx = dx - cub->doors[doornb].pos;
	dy = dx * tanf(M_PI_2 - fabs(M_PI_2 - angle));
	if (dy < 1)
	{
		*len += sqrtf(dx * dx + dy * dy);
		cub->ray.wall_found = WEST;
		return (1);
	}
	return (0);
}

int	test_west(t_data *cub, float angle, float *len, int doornb)
{
	float	dx;
	float	dy;

	dx = 0;
	dy = 0;
	cub->ray.door_type = cub->ray.wall_found;
	cub->ray.wall_found = DOOR;
	if (cub->player.fy + *len * sinf(angle)
		- (int)(cub->player.fy + *len * sinf(angle)) < cub->doors[doornb].pos)
		return (1);
	if (!(angle > M_PI && angle <= 3 * M_PI_2))
		return (0);
	dx = cub->player.fy + *len * sinf(angle)
		- (int)(cub->player.fy + *len * sinf(angle));
	dx = dx - cub->doors[doornb].pos;
	dy = dx * tanf(M_PI_2 - fabs(M_PI - angle));
	if (dy < 1)
	{
		*len += sqrtf(dx * dx + dy * dy);
		cub->ray.wall_found = NORTH;
		return (1);
	}
	return (0);
}

int	test_east(t_data *cub, float angle, float *len, int doornb)
{
	float	dx;
	float	dy;

	dx = 0;
	dy = 0;
	cub->ray.door_type = cub->ray.wall_found;
	cub->ray.wall_found = DOOR;
	if (cub->player.fy + *len * sinf(angle)
		- (int)(cub->player.fy + *len * sinf(angle)) < cub->doors[doornb].pos)
		return (1);
	if (!(angle > 3 * M_PI_2 && angle <= 2 * M_PI))
		return (0);
	dx = cub->player.fy + *len * sinf(angle)
		- (int)(cub->player.fy + *len * sinf(angle));
	dx = dx - cub->doors[doornb].pos;
	dy = dx * tanf(M_PI_2 - (2 * M_PI - angle));
	if (dy < 1)
	{
		*len += sqrtf(dx * dx + dy * dy);
		cub->ray.wall_found = NORTH;
		return (1);
	}
	return (0);
}
