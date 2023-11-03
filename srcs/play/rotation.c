/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:03:02 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/03 10:49:42 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_left(t_data *cub, int ratio)
{
	cub->player.angle -= ratio * M_PI / 600;
	if (cub->player.angle < 0)
		cub->player.angle += 2 * M_PI;
}

void	rotate_right(t_data *cub, int ratio)
{
	cub->player.angle += ratio * M_PI / 600;
	if (cub->player.angle > 2 * M_PI)
		cub->player.angle -= 2 * M_PI;
}
