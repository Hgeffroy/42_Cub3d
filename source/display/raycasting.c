/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:06:56 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/27 17:37:51 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

	
int		raycasting(t_game *g)
{
	int	len;
	int	height;
	
	//Mettre ca dan une boucle
	len = ray(g, g->player->angle);
	height = SCREEN_DIST * WALL_HEIGHT / len;
}