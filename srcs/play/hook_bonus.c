/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:59:35 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/02 18:07:50 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	move_mouse(int x, int y, t_data *cub)
{
	int	diff_x;
	int	mouse_x;
	int	mouse_y;

	(void)y;
	if (cub->movement.mouse)
		return (0);
	diff_x = x - cub->movement.last_x;
	if (diff_x > 0.5)
		rotate_right(cub, diff_x / 10);
	else if (diff_x < -0.5)
		rotate_right(cub, diff_x / 10);
	mlx_mouse_get_pos(cub->mlx, cub->win, &mouse_x, &mouse_y);
	if (mouse_x > SCREEN_WIDTH - 50 || mouse_y > SCREEN_HEIGHT - 50)
	{
		mlx_mouse_move(cub->mlx, cub->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		cub->movement.last_x = SCREEN_WIDTH / 2;
		return (0);
	}
	cub->movement.last_x += diff_x;
	return (0);
}
