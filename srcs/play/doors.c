/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:53:17 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/04 11:00:43 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	find_door(t_data *cub, int x, int y)
{
	int	i;

	i = 0;
	while (cub->doors + i)
	{
		if (cub->doors[i].x == x && cub->doors[i].y == y)
			break ;
		i++;
	}
	return (i);
}

int	set_door(t_data *cub)
{
	int	doornb;

	if (raycasting(cub, cub->player.angle, 1) < 3
		&& cub->ray.wall_found == DOOR)
	{
		doornb = find_door(cub, cub->ray.map_check[0], cub->ray.map_check[1]);
		if (cub->doors[doornb].pos > 0.5 && cub->doors[doornb].state == NEUTRAL)
			cub->doors[doornb].state = OPENING;
		else if (cub->doors[doornb].pos < 0.5
			&& cub->doors[doornb].state == NEUTRAL)
			cub->doors[doornb].state = CLOSING;
	}
	return (0);
}

int	move_doors(t_data *cub)
{
	int	i;

	i = -1;
	while (cub->doors && cub->doors[++i].pos > -0.5)
	{
		if (cub->doors[i].state == OPENING)
		{
			cub->doors[i].pos -= 0.01;
			if (cub->doors[i].pos < 0.001)
			{
				cub->doors[i].pos = 0.f;
				cub->doors[i].state = NEUTRAL;
			}
		}
		else if (cub->doors[i].state == CLOSING)
		{
			cub->doors[i].pos += 0.01;
			if (cub->doors[i].pos > 0.999)
			{
				cub->doors[i].pos = 1.f;
				cub->doors[i].state = NEUTRAL;
			}
		}
	}
	return (0);
}
