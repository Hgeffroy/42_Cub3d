/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_door_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:03:20 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/03 18:16:28 by xcharra          ###   ########.fr       */
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
	if (cub->ray.door_type == EAST || cub->ray.door_type == WEST)
		wallray->color = get_color(cub->walls[DOOR],
				wallray->y_impact,
				cub->walls[DOOR].width - (int)(cub->walls[DOOR].height / 2
					- (wallray->height - wallray->half_height)
					* wallray->y_ratio));
	else if (cub->ray.door_type == NORTH || cub->ray.door_type == SOUTH)
		wallray->color = get_color(cub->walls[DOOR],
				cub->walls[DOOR].width - wallray->x_impact,
				cub->walls[DOOR].width - (int)(cub->walls[DOOR].height / 2
					- (wallray->height - wallray->half_height)
					* wallray->y_ratio));
}
