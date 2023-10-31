/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:53:17 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/23 15:12:39 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_door(t_game *g)
{
	if (raycasting(g, g->player.angle) < 3 && g->ray.wall_found == DOOR)
		puts("lala"); // Booleen de la porte a true
	return (0);
}