/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_col.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:51:36 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/06 13:15:05 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	_init_col_n(t_data *cub, t_wallray *wallray)
{
	wallray->x_impact = cub->ray.impact[0] * cub->walls[NORTH].width;
	wallray->y_impact = cub->ray.impact[1] * cub->walls[NORTH].width;
	wallray->y_ratio = cub->walls[NORTH].height / wallray->height;
}

static void	_init_col_s(t_data *cub, t_wallray *wallray)
{
	wallray->x_impact = cub->ray.impact[0] * cub->walls[SOUTH].width;
	wallray->y_impact = cub->ray.impact[1] * cub->walls[SOUTH].width;
	wallray->y_ratio = cub->walls[SOUTH].height / wallray->height;
}

static void	_init_col_w(t_data *cub, t_wallray *wallray)
{
	wallray->x_impact = cub->ray.impact[0] * cub->walls[WEST].width;
	wallray->y_impact = cub->ray.impact[1] * cub->walls[WEST].width;
	wallray->y_ratio = cub->walls[WEST].height / wallray->height;
}

static void	_init_col_e(t_data *cub, t_wallray *wallray)
{
	wallray->x_impact = cub->ray.impact[0] * cub->walls[EAST].width;
	wallray->y_impact = cub->ray.impact[1] * cub->walls[EAST].width;
	wallray->y_ratio = cub->walls[EAST].height / wallray->height;
}

void	init_col(t_data *cub, t_wallray *wallray)
{
	static t_init_col	tab[] = {&_init_col_n, &_init_col_s, &_init_col_w,
		&_init_col_e, NULL, NULL};

	if (BONUS)
		tab[4] = &init_col_d;
	tab[cub->ray.wall_found](cub, wallray);
}
