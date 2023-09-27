/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:59:35 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/27 12:54:43 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	press_key(int keycode, t_game *g)
{
	if (keycode == left_key)
		g->movement->rotate_left = true;
	if (keycode == right_key)
		g->movement->rotate_right = true;
	if (keycode == up_key || keycode == w_key)
		g->movement->move_up = true;
	if (keycode == down_key || keycode == s_key)
		g->movement->move_down= true;
	if (keycode == a_key)
		g->movement->move_left = true;
	if (keycode == d_key)
		g->movement->move_right = true;
	return (0);
}

int	release_key(int keycode, t_game *g)
{
	if (keycode == left_key)
		g->movement->rotate_left = false;
	if (keycode == right_key)
		g->movement->rotate_right = false;
	if (keycode == up_key || keycode == w_key)
		g->movement->move_up = false;
	if (keycode == down_key || keycode == s_key)
		g->movement->move_down= false;
	if (keycode == a_key)
		g->movement->move_left = false;
	if (keycode == d_key)
		g->movement->move_right = false;
	return (0);
}