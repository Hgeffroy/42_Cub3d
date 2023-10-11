/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:59:35 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/11 15:40:00 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	press_key(int keycode, t_game *g)
{
	if (keycode == left_key)
		g->movement.rotate_left = true;
	if (keycode == right_key)
		g->movement.rotate_right = true;
	if (keycode == up_key || keycode == w_key)
		g->movement.move_up = true;
	if (keycode == down_key || keycode == s_key)
		g->movement.move_down= true;
	if (keycode == a_key)
		g->movement.move_left = true;
	if (keycode == d_key)
		g->movement.move_right = true;
	if (keycode == esc_key)
		mlx_close(g);
	return (0);
}

int	release_key(int keycode, t_game *g)
{
	if (keycode == left_key)
		g->movement.rotate_left = false;
	if (keycode == right_key)
		g->movement.rotate_right = false;
	if (keycode == up_key || keycode == w_key)
		g->movement.move_up = false;
	if (keycode == down_key || keycode == s_key)
		g->movement.move_down= false;
	if (keycode == a_key)
		g->movement.move_left = false;
	if (keycode == d_key)
		g->movement.move_right = false;
	return (0);
}

int	press_mouse(int keycode, int x, int y, t_game *g)
{
	(void)x;
	(void)y;
	if (keycode == m_right_key)
		g->movement.mouse = true;
	return (0);
}

int	release_mouse(int keycode, int x, int y, t_game *g)
{
	(void)x;
	(void)y;
	if (keycode == m_right_key)
		g->movement.mouse = false;
	return (0);
}

int	move_mouse(int x, int y, t_game *g)
{
	(void)y;
	int	diff_x;
	int	mouse_x;
	int	mouse_y;

	if (g->movement.mouse)
		return (0);
	diff_x = x - g->movement.last_x;
	if (diff_x > 0.5)
		rotate_right(g, diff_x);
	else if (diff_x < - 0.5)
		rotate_right(g, diff_x);
	mlx_mouse_get_pos(g->mlx, g->win, &mouse_x, &mouse_y);
	if (mouse_x > 1850 || mouse_y > 1000)
	{
		mlx_mouse_move(g->mlx, g->win, 1920 / 2, 1080 / 2);
		g->movement.last_x = 1920 / 2;
		return (0);
	}
	g->movement.last_x += diff_x;
	return (0);
}