/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:03:02 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/02 18:17:27 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_left(t_data *cub, int ratio)
{
	cub->player.angle -= ratio * M_PI / 600;
}

void	rotate_right(t_data *cub, int ratio)
{
	cub->player.angle += ratio * M_PI / 600;
}
