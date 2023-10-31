/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:03:20 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/31 16:55:03 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_north_color(t_data *cub, t_wallray *wallray)
{
	// puts("color north");
	wallray->color = get_color(cub->walls[NORTH], wallray->x_impact, \
					(int)(cub->walls[NORTH].height / 2 - \
					(wallray->height - wallray->half_height) * wallray->y_ratio));
}

void	get_south_color(t_data *cub, t_wallray *wallray)
{
	// puts("color south");
	wallray->color = get_color(cub->walls[SOUTH], wallray->x_impact, \
					(int)(cub->walls[SOUTH].height / 2 - \
					(wallray->height - wallray->half_height) * wallray->y_ratio));
}

void	get_west_color(t_data *cub, t_wallray *wallray)
{
	// puts("color west");
	wallray->color = get_color(cub->walls[WEST], wallray->y_impact, \
					(int)(cub->walls[WEST].height / 2 - \
					(wallray->height - wallray->half_height) * wallray->y_ratio));
}

void	get_east_color(t_data *cub, t_wallray *wallray)
{
	// puts("color east");
	wallray->color = get_color(cub->walls[EAST], wallray->y_impact, \
					(int)(cub->walls[EAST].height / 2 - \
					(wallray->height - wallray->half_height) * wallray->y_ratio));
}

void	get_wall_color(t_data *cub, t_wallray *wallray)
{
	const t_wall_color	tab[] = {&get_north_color, &get_south_color, \
									&get_west_color, &get_east_color};

	(*tab[cub->ray.wall_found])(cub, wallray);
}