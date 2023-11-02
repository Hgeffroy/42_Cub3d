/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:59:35 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/02 13:53:02 by hgeffroy         ###   ########.fr       */
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
		cub->movement.move_down= false;
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

int	move_mouse(int x, int y, t_data *cub)
{
	(void)y;
	int	diff_x;
	int	mouse_x;
	int	mouse_y;

	if (cub->movement.mouse)
		return (0);
	diff_x = x - cub->movement.last_x;
	if (diff_x > 0.5)
		rotate_right(cub, diff_x / 10);
	else if (diff_x < - 0.5)
		rotate_right(cub, diff_x / 10);
	mlx_mouse_get_pos(cub->mlx, cub->win, &mouse_x, &mouse_y);
	if (mouse_x > 1850 || mouse_y > 1000)
	{
		mlx_mouse_move(cub->mlx, cub->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		cub->movement.last_x = SCREEN_WIDTH / 2;
		return (0);
	}
	cub->movement.last_x += diff_x;
	return (0);
}