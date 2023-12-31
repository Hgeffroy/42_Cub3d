/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:06:56 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/08 13:52:47 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ray_init(t_data *cub, float angle)
{
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	if (angle < 0)
		angle += 2 * M_PI;
	ft_bzero(&cub->ray, sizeof(cub->ray));
	cub->ray.map_check[0] = (int)cub->player.fx;
	cub->ray.map_check[1] = (int)cub->player.fy;
	cub->ray.ray_start[0] = cub->player.fx;
	cub->ray.ray_start[1] = cub->player.fy;
	cub->ray.ray_dir[0] = cosf(angle);
	cub->ray.ray_dir[1] = sinf(angle);
	cub->ray.step_size[0] = sqrt(1 + (cub->ray.ray_dir[1] / cub->ray.ray_dir[0])
			* (cub->ray.ray_dir[1] / cub->ray.ray_dir[0]));
	cub->ray.step_size[1] = sqrt(1 + (cub->ray.ray_dir[0] / cub->ray.ray_dir[1])
			* (cub->ray.ray_dir[0] / cub->ray.ray_dir[1]));
}

void	ray_start(t_data *cub)
{
	if (cub->ray.ray_dir[0] < 0)
	{
		cub->ray.step[0] = -1;
		cub->ray.ray_len[0] = (cub->ray.ray_start[0] - \
		(float)(cub->ray.map_check[0])) * cub->ray.step_size[0];
	}
	else
	{
		cub->ray.step[0] = 1;
		cub->ray.ray_len[0] = ((float)(cub->ray.map_check[0] + 1) - \
		cub->ray.ray_start[0]) * cub->ray.step_size[0];
	}
	if (cub->ray.ray_dir[1] < 0)
	{
		cub->ray.step[1] = -1;
		cub->ray.ray_len[1] = (cub->ray.ray_start[1] - \
		(float)(cub->ray.map_check[1])) * cub->ray.step_size[1];
	}
	else
	{
		cub->ray.step[1] = 1;
		cub->ray.ray_len[1] = ((float)(cub->ray.map_check[1] + 1) - \
		cub->ray.ray_start[1]) * cub->ray.step_size[1];
	}
}

float	ray_step(t_data *cub)
{
	float	len;

	if (cub->ray.ray_len[0] < cub->ray.ray_len[1])
	{
		cub->ray.map_check[0] += cub->ray.step[0];
		len = cub->ray.ray_len[0];
		cub->ray.ray_len[0] += cub->ray.step_size[0];
		if (cub->ray.step[0] > 0)
			cub->ray.wall_found = EAST;
		else
			cub->ray.wall_found = WEST;
	}
	else
	{
		cub->ray.map_check[1] += cub->ray.step[1];
		len = cub->ray.ray_len[1];
		cub->ray.ray_len[1] += cub->ray.step_size[1];
		if (cub->ray.step[1] > 0)
			cub->ray.wall_found = SOUTH;
		else
			cub->ray.wall_found = NORTH;
	}
	return (len);
}

void	set_impact(t_data *cub, float angle, float len)
{
	int	doornb;

	if (cub->ray.wall_found == DOOR)
	{
		doornb = find_door(cub, cub->ray.map_check[0], cub->ray.map_check[1]);
		if (cub->ray.door_type == NORTH || cub->ray.door_type == SOUTH)
		{
			cub->ray.impact[0] = cub->doors[doornb].pos - (cub->player.fx + len
					* cosf(angle) - (int)(cub->player.fx + len * cosf(angle)));
			cub->ray.impact[1] = cub->player.fy + len * sinf(angle)
				- (int)(cub->player.fy + len * sinf(angle));
		}
		else
		{
			cub->ray.impact[0] = cub->player.fx + len * cosf(angle)
				- (int)(cub->player.fx + len * cosf(angle));
			cub->ray.impact[1] = cub->doors[doornb].pos - (cub->player.fy + len
					* sinf(angle) - (int)(cub->player.fy + len * sinf(angle)));
		}
		return ;
	}
	cub->ray.impact[0] = cub->player.fx + len * cosf(angle)
		- (int)(cub->player.fx + len * cosf(angle));
	cub->ray.impact[1] = cub->player.fy + len * sinf(angle)
		- (int)(cub->player.fy + len * sinf(angle));
}

float	raycasting(t_data *cub, float angle, int optn)
{
	float	len;

	ray_init(cub, angle);
	ray_start(cub);
	while (1)
	{
		len = ray_step(cub);
		if (cub->map[cub->ray.map_check[1]][cub->ray.map_check[0]] != '0')
		{
			if (BONUS
				&& cub->map[cub->ray.map_check[1]][cub->ray.map_check[0]]
				== 'D')
			{
				if (ray_door(cub, angle, &len, optn))
					break ;
			}
			else
				break ;
		}
	}
	set_impact(cub, angle, len);
	return (len);
}
