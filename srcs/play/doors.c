/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:53:17 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/31 16:34:33 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

int	open_door(t_data *cub)
{
	if (raycasting(cub, cub->player.angle) < 3 && cub->ray.wall_found == DOOR)
		puts("lala"); // Booleen de la porte a true
	return (0);
}