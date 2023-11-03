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

int	press_key(int keycode, t_data *cub)
{
	if (keycode == left_key)
		cub->movement.rotate_left = true;
	if (keycode == right_key)
		cub->movement.rotate_right = true;
	if (keycode == up_key || keycode == w_key)
		cub->movement.move_up = true;
	if (keycode == down_key || keycode == s_key)
		cub->movement.move_down = true;
	if (keycode == a_key)
		cub->movement.move_left = true;
	if (keycode == d_key)
		cub->movement.move_right = true;
	if (keycode == esc_key)
		mlx_close(cub);
	if (keycode == space_key && BONUS)
		set_door(cub);
	return (0);
}

int	release_key(int keycode, t_data *cub)
{
	if (keycode == left_key)
		cub->movement.rotate_left = false;
	if (keycode == right_key)
		cub->movement.rotate_right = false;
	if (keycode == up_key || keycode == w_key)
		cub->movement.move_up = false;
	if (keycode == down_key || keycode == s_key)
		cub->movement.move_down = false;
	if (keycode == a_key)
		cub->movement.move_left = false;
	if (keycode == d_key)
		cub->movement.move_right = false;
	return (0);
}

int	press_mouse(int keycode, int x, int y, t_data *cub)
{
	(void)x;
	(void)y;
	if (keycode == m_right_key)
		cub->movement.mouse = true;
	return (0);
}

int	release_mouse(int keycode, int x, int y, t_data *cub)
{
	(void)x;
	(void)y;
	if (keycode == m_right_key)
		cub->movement.mouse = false;
	return (0);
}
