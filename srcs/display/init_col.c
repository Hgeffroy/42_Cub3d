/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_col.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:51:36 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/31 16:34:33 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

void	init_col_n(t_data *cub, t_wallray *wallray)
{
	// puts("init north");
	wallray->x_impact = cub->ray.impact[0] * cub->walls[NORTH].width;
	wallray->y_impact = cub->ray.impact[1] * cub->walls[NORTH].width;
	wallray->y_ratio = cub->walls[NORTH].height / wallray->height;
}

void	init_col_s(t_data *cub, t_wallray *wallray)
{
	// puts("init south");
	wallray->x_impact = cub->ray.impact[0] * cub->walls[SOUTH].width;
	wallray->y_impact = cub->ray.impact[1] * cub->walls[SOUTH].width;
	wallray->y_ratio = cub->walls[SOUTH].height / wallray->height;
}

void	init_col_w(t_data *cub, t_wallray *wallray)
{
	// puts("init west");
	wallray->x_impact = cub->ray.impact[0] * cub->walls[WEST].width;
	wallray->y_impact = cub->ray.impact[1] * cub->walls[WEST].width;
	wallray->y_ratio = cub->walls[WEST].height / wallray->height;
}

void	init_col_e(t_data *cub, t_wallray *wallray)
{
	// puts("init east");
	wallray->x_impact = cub->ray.impact[0] * cub->walls[EAST].width;
	wallray->y_impact = cub->ray.impact[1] * cub->walls[EAST].width;
	wallray->y_ratio = cub->walls[EAST].height / wallray->height;
}

void	init_col(t_data *cub, t_wallray *wallray)
{
	const t_init_col	tab[] = {&init_col_n, &init_col_s, &init_col_w, \
								&init_col_w};
								
	(*tab[cub->ray.wall_found])(cub, wallray);
}