/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:03:02 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/02 14:26:57 by hgeffroy         ###   ########.fr       */
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

void	move_forward(t_data *cub)
{
	float	nextx;
	float	nexty;

	nextx = cub->player.fx + cos (cub->player.angle) * SPEED;
	nexty = cub->player.fy + sin (cub->player.angle) * SPEED;
	if (cub->map[(int)(cub->player.fy)][(int)(nextx)] == '0' || (cub->map[(int)(cub->player.fy)][(int)(nextx)] == 'D' && cub->doors[find_door(cub, (int)(nextx), (int)(cub->player.fy))].pos < 0.001))
		cub->player.fx += cos(cub->player.angle) * SPEED;
	if (cub->map[(int)(nexty)][(int)(cub->player.fx)] == '0' || (cub->map[(int)(nexty)][(int)(cub->player.fx)] == 'D' && cub->doors[find_door(cub, (int)(cub->player.fx), (int)(nexty))].pos < 0.001))
		cub->player.fy += sin(cub->player.angle) * SPEED;
}

void	move_backward(t_data *cub)
{
	float	nextx;
	float	nexty;

	nextx = cub->player.fx + cos (cub->player.angle + M_PI) * SPEED;
	nexty = cub->player.fy + sin (cub->player.angle + M_PI) * SPEED;
	if (cub->map[(int)(cub->player.fy)][(int)(nextx)] == '0' || (cub->map[(int)(cub->player.fy)][(int)(nextx)] == 'D' && cub->doors[find_door(cub, (int)(nextx), (int)(cub->player.fy))].pos < 0.001))
		cub->player.fx += cos(cub->player.angle + M_PI) * SPEED;
	if (cub->map[(int)(nexty)][(int)(cub->player.fx)] == '0' || (cub->map[(int)(nexty)][(int)(cub->player.fx)] == 'D' && cub->doors[find_door(cub, (int)(cub->player.fx), (int)(nexty))].pos < 0.001))
		cub->player.fy += sin(cub->player.angle + M_PI) * SPEED;
}

void	move_left(t_data *cub)
{
	float	nextx;
	float	nexty;

	nextx = cub->player.fx + cos (cub->player.angle - M_PI_2) * SPEED;
	nexty = cub->player.fy + sin (cub->player.angle - M_PI_2) * SPEED;
	if (cub->map[(int)(cub->player.fy)][(int)(nextx)] == '0' || (cub->map[(int)(cub->player.fy)][(int)(nextx)] == 'D' && cub->doors[find_door(cub, (int)(nextx), (int)(cub->player.fy))].pos < 0.001))
		cub->player.fx += cos(cub->player.angle - M_PI_2) * SPEED;
	if (cub->map[(int)(nexty)][(int)(cub->player.fx)] == '0' || (cub->map[(int)(nexty)][(int)(cub->player.fx)] == 'D' && cub->doors[find_door(cub, (int)(cub->player.fx), (int)(nexty))].pos < 0.001))
		cub->player.fy += sin(cub->player.angle - M_PI_2) * SPEED;
}

void	move_right(t_data *cub)
{
	float	nextx;
	float	nexty;

	nextx = cub->player.fx + cos (cub->player.angle + M_PI_2) * SPEED;
	nexty = cub->player.fy + sin (cub->player.angle + M_PI_2) * SPEED;
	if (cub->map[(int)(cub->player.fy)][(int)(nextx)] == '0' || (cub->map[(int)(cub->player.fy)][(int)(nextx)] == 'D' && cub->doors[find_door(cub, (int)(nextx), (int)(cub->player.fy))].pos < 0.001))
		cub->player.fx += cos(cub->player.angle + M_PI_2) * SPEED;
	if (cub->map[(int)(nexty)][(int)(cub->player.fx)] == '0' || (cub->map[(int)(nexty)][(int)(cub->player.fx)] == 'D' && cub->doors[find_door(cub, (int)(cub->player.fx), (int)(nexty))].pos < 0.001))
		cub->player.fy += sin(cub->player.angle + M_PI_2) * SPEED;
}
