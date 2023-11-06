/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:03:20 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/06 10:19:32 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	_get_north_color(t_data *cub, t_wallray *wallray)
{
	int	x;
	int	y;

	x = wallray->x_impact;
	y = cub->walls[NORTH].width - (int)(cub->walls[NORTH].height / 2
			- (wallray->height - wallray->half_height) * wallray->y_ratio);
	if (y > cub->walls[NORTH].height - 1)
		y = cub->walls[NORTH].height - 1;
	wallray->color = get_color(cub->walls[NORTH], x, y);
}

static void	_get_south_color(t_data *cub, t_wallray *wallray)
{
	int	x;
	int	y;

	x = cub->walls[SOUTH].width - wallray->x_impact;
	y = cub->walls[SOUTH].width - (int)(cub->walls[SOUTH].height / 2
			- (wallray->height - wallray->half_height) * wallray->y_ratio);
	if (y > cub->walls[SOUTH].height - 1)
		y = cub->walls[SOUTH].height - 1;
	wallray->color = get_color(cub->walls[SOUTH], x, y);
}

static void	_get_west_color(t_data *cub, t_wallray *wallray)
{
	int	x;
	int	y;

	x = cub->walls[WEST].width - wallray->y_impact;
	y = cub->walls[WEST].width - (int)(cub->walls[WEST].height / 2
			- (wallray->height - wallray->half_height) * wallray->y_ratio);
	if (y > cub->walls[WEST].height - 1)
		y = cub->walls[WEST].height - 1;
	wallray->color = get_color(cub->walls[WEST], x, y);
}

static void	_get_east_color(t_data *cub, t_wallray *wallray)
{
	int	x;
	int	y;

	x = wallray->y_impact;
	y = cub->walls[EAST].width - (int)(cub->walls[EAST].height / 2
			- (wallray->height - wallray->half_height) * wallray->y_ratio);
	if (y > cub->walls[EAST].height - 1)
		y = cub->walls[EAST].height - 1;
	wallray->color = get_color(cub->walls[EAST], x, y);
}

void	get_wall_color(t_data *cub, t_wallray *wallray)
{
	static t_wall_color	tab[] = {&_get_north_color, &_get_south_color,
		&_get_west_color, &_get_east_color, NULL, NULL};

	if (BONUS)
		tab[4] = &get_door_color;
	tab[cub->ray.wall_found](cub, wallray);
}
