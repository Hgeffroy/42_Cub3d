/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:03:20 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/06 10:23:54 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_col_d(t_data *cub, t_wallray *wallray)
{
	wallray->x_impact = cub->ray.impact[0] * cub->walls[DOOR].width;
	wallray->y_impact = cub->ray.impact[1] * cub->walls[DOOR].width;
	wallray->y_ratio = cub->walls[DOOR].height / wallray->height;
}

void	get_door_color(t_data *cub, t_wallray *wallray)
{
	int	x;
	int	y;
	
	if (cub->ray.door_type == EAST || cub->ray.door_type == WEST)
	{
		x = wallray->y_impact;
		y = cub->walls[DOOR].width - (int)(cub->walls[DOOR].height / 2
				- (wallray->height - wallray->half_height) * wallray->y_ratio);
		if (y > cub->walls[DOOR].height - 1)
			y = cub->walls[DOOR].height - 1;
	}
	else if (cub->ray.door_type == NORTH || cub->ray.door_type == SOUTH)
	{
		x = cub->walls[DOOR].width - wallray->x_impact;
		y = cub->walls[DOOR].width - (int)(cub->walls[DOOR].height / 2
				- (wallray->height - wallray->half_height) * wallray->y_ratio);
		if (y > cub->walls[DOOR].height - 1)
			y = cub->walls[DOOR].height - 1;
	}
	wallray->color = get_color(cub->walls[DOOR], x, y);
}
