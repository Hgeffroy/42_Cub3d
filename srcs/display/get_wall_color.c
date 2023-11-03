/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:03:20 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/03 18:13:40 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	_get_north_color(t_data *cub, t_wallray *wallray)
{
	wallray->color = get_color(cub->walls[NORTH],
			wallray->x_impact,
			cub->walls[NORTH].width - (int)(cub->walls[NORTH].height / 2
				- (wallray->height - wallray->half_height) * wallray->y_ratio));
}

static void	_get_south_color(t_data *cub, t_wallray *wallray)
{
	wallray->color = get_color(cub->walls[SOUTH],
			cub->walls[SOUTH].width - wallray->x_impact,
			cub->walls[SOUTH].width - (int)(cub->walls[SOUTH].height / 2
				- (wallray->height - wallray->half_height) * wallray->y_ratio));
}

static void	_get_west_color(t_data *cub, t_wallray *wallray)
{
	wallray->color = get_color(cub->walls[WEST],
			cub->walls[WEST].width - wallray->y_impact,
			cub->walls[WEST].width - (int)(cub->walls[WEST].height / 2
				- (wallray->height - wallray->half_height) * wallray->y_ratio));
}

static void	_get_east_color(t_data *cub, t_wallray *wallray)
{
	wallray->color = get_color(cub->walls[EAST],
			wallray->y_impact,
			cub->walls[EAST].width - (int)(cub->walls[EAST].height / 2
				- (wallray->height - wallray->half_height) * wallray->y_ratio));
}

void	get_wall_color(t_data *cub, t_wallray *wallray)
{
	static t_wall_color	tab[] = {&_get_north_color, &_get_south_color,
		&_get_west_color, &_get_east_color, NULL, NULL};

	if (BONUS)
		tab[4] = get_door_color;
	tab[cub->ray.wall_found](cub, wallray);
}
