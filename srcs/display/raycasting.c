/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:06:56 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/03 13:38:49 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ray_init(t_data *cub, float angle)
{
	ft_bzero(cub->ray.ray_len, 2);
	ft_bzero(cub->ray.step, 2);
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

float	raycasting(t_data *cub, float angle, int optn)
{
	float	len;
	int		doornb;
	float	dx;
	float	dy;

	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	if (angle < 0)
		angle += 2 * M_PI;
	ray_init(cub, angle);
	ray_start(cub);
	while (1)
	{
		len = ray_step(cub);
		if (cub->map[cub->ray.map_check[1]][cub->ray.map_check[0]] != '0') // Cas de la porte ?
		{
			if(cub->map[cub->ray.map_check[1]][cub->ray.map_check[0]] == 'D')
			{
				if (optn)
				{
					cub->ray.wall_found = DOOR;
					break ;
				}
				doornb = find_door(cub, cub->ray.map_check[0], cub->ray.map_check[1]);
				
				if (cub->ray.wall_found == NORTH || cub->ray.wall_found == SOUTH)
				{
					cub->ray.door_type = cub->ray.wall_found;
					cub->ray.wall_found = DOOR;
					
					// Nord
					if (cub->player.fx + len * cosf(angle) - (int)(cub->player.fx + len * cosf(angle)) < cub->doors[doornb].pos)
						break ;
					if (!(angle > M_PI && angle <= 3 * M_PI_2))
						continue ;
					dx = cub->player.fx + len * cosf(angle) - (int)(cub->player.fx + len * cosf(angle));
					dx = dx - cub->doors[doornb].pos;
					dy = dx * tanf(M_PI_2 - (3 * M_PI_2 - angle));
					printf ("%f\n", dy);
					if (dy < 1)
					{
						len += sqrtf(dx * dx + dy * dy);
						break ;
					}
				}
				
				else if (cub->ray.wall_found == EAST || cub->ray.wall_found == WEST)
				{
					cub->ray.door_type = cub->ray.wall_found;
					cub->ray.wall_found = DOOR;
					
					//Est
					if (cub->player.fy + len * sinf(angle) - (int)(cub->player.fy + len * sinf(angle)) < cub->doors[doornb].pos)
						break ;
					if (!(angle > 3 * M_PI_2 && angle <= 2 * M_PI))
						continue ;
					dx = cub->player.fy + len * sinf(angle) - (int)(cub->player.fy + len * sinf(angle));
					dx = /* 1 -  */dx - cub->doors[doornb].pos;
					dy = dx * tanf(M_PI_2 - (2 * M_PI - angle));
					printf ("%f\n", dy);
					if (dy < 1)
					{
						len += sqrtf(dx * dx + dy * dy);
						break ;
					}
				}
			}
			else
				break ;
		}
	}
	cub->ray.impact[0] = cub->player.fx + len * cosf(angle)
		- (int)(cub->player.fx + len * cosf(angle));
	cub->ray.impact[1] = cub->player.fy + len * sinf(angle)
		- (int)(cub->player.fy + len * sinf(angle));
	return (len);
}
