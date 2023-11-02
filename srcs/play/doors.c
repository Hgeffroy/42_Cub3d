/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:53:17 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/02 14:10:09 by hgeffroy         ###   ########.fr       */
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

	if (raycasting(cub, cub->player.angle) < 3 && cub->ray.wall_found == DOOR)
	{
		doornb = find_door(cub, cub->ray.map_check[0], cub->ray.map_check[1]);
		printf("pos : %f, state : %d\n", cub->doors[doornb].pos,
			cub->doors[doornb].state);
		if (cub->doors[doornb].pos > 0.5 && cub->doors[doornb].state == NEUTRAL)
		{
			puts("We set the door");
			cub->doors[doornb].state = OPENING;
		}
		else if (cub->doors[doornb].pos < 0.5
			&& cub->doors[doornb].state == NEUTRAL)
			cub->doors[doornb].state = CLOSING;
	}
	return (0);
}

int	move_doors(t_data *cub)
{
	int	i;

	i = 0;
	while (cub->doors[i].pos > -0.5)
	{
		if (cub->doors[i].state == OPENING)
		{
			printf("Door %d opening\n", i);
			cub->doors[i].pos -= 0.01;
			if (cub->doors[i].pos < 0.001)
			{
				printf("Door %d to neutral\n", i);
				cub->doors[i].pos = 0.f;
				cub->doors[i].state = NEUTRAL;
			}
		}
		else if (cub->doors[i].state == CLOSING)
		{
			printf("Door %d closing\n", i);
			cub->doors[i].pos += 0.01;
			if (cub->doors[i].pos > 0.999)
			{
				printf("Door %d to neutral\n", i);
				cub->doors[i].pos = 1.f;
				cub->doors[i].state = NEUTRAL;
			}
		}
		i++;
	}
	return (0);
}
