/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:53:17 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/31 16:00:15 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	open_door(t_game *g)
{
	if (raycasting(g, g->player.angle) < 3 && g->ray.wall_found == DOOR)
		puts("lala"); // Booleen de la porte a true
	return (0);
}