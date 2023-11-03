/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:03:20 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/03 10:11:37 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_north_color(t_data *cub, t_wallray *wallray)
{
	// puts("color north");
	wallray->color = get_color(cub->walls[NORTH], wallray->x_impact,
			cub->walls[NORTH].width - (int)(cub->walls[NORTH].height / 2
			- (wallray->height - wallray->half_height) * wallray->y_ratio));
}

void	get_south_color(t_data *cub, t_wallray *wallray)
{
	// puts("color south");
	wallray->color = get_color(cub->walls[SOUTH], cub->walls[SOUTH].width - wallray->x_impact,
			cub->walls[SOUTH].width - (int)(cub->walls[SOUTH].height / 2
			- (wallray->height - wallray->half_height) * wallray->y_ratio));
}

void	get_west_color(t_data *cub, t_wallray *wallray)
{
	// puts("color west");
	wallray->color = get_color(cub->walls[WEST], cub->walls[WEST].width - wallray->y_impact,
			cub->walls[WEST].width - (int)(cub->walls[WEST].height / 2
			- (wallray->height - wallray->half_height) * wallray->y_ratio));
}

void	get_east_color(t_data *cub, t_wallray *wallray)
{
	// puts("color east");
	wallray->color = get_color(cub->walls[EAST], wallray->y_impact,
			cub->walls[EAST].width - (int)(cub->walls[EAST].height / 2
			- (wallray->height - wallray->half_height) * wallray->y_ratio));
}

void	get_door_color(t_data *cub, t_wallray *wallray)
{
	// puts("color door")
	if (cub->ray.door_type == EAST || cub->ray.door_type == WEST)
		wallray->color = get_color(cub->walls[DOOR], wallray->y_impact,
			cub->walls[DOOR].width - (int)(cub->walls[DOOR].height / 2
			- (wallray->height - wallray->half_height) * wallray->y_ratio));
	else if (cub->ray.door_type == NORTH || cub->ray.door_type == SOUTH)
		wallray->color = get_color(cub->walls[DOOR], cub->walls[DOOR].width - wallray->x_impact,
			cub->walls[DOOR].width - (int)(cub->walls[DOOR].height / 2
			- (wallray->height - wallray->half_height) * wallray->y_ratio));
	
}

void	get_wall_color(t_data *cub, t_wallray *wallray)
{
	const t_wall_color	tab[] = {&get_north_color, &get_south_color,
		&get_west_color, &get_east_color, &get_door_color};

	(*tab[cub->ray.wall_found])(cub, wallray);
}
