/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:58:35 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/09 08:24:13 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mlx_close(t_game *g)
{
	(void)g;
	exit (0);
}

int	init_game(t_game *g)
{
	g->player->fx = g->player->x + 0.5;
	g->player->fy = g->player->y + 0.5;
	return (0);
}

int	mlx_play(t_game *g)
{
	if (g->movement->rotate_left)
		rotate_left(g);
	if (g->movement->rotate_right)
		rotate_right(g);
	if (g->movement->move_up)
		move_forward(g);
	if (g->movement->move_down)
		move_backward(g);
	if (g->movement->move_left)
		move_left(g);
	if (g->movement->move_right)
		move_right(g);
	draw_display(g);
	draw_minimap(g);
	mlx_put_image_to_window(g->mlx, g->win, g->display->img, 0, 0);
	mlx_set_font(g->mlx, g->win, "-*-*-*-*-*-*-*-*-*-*-*-123-*-*");
	mlx_string_put(g->mlx, g->win, 6 * TILE_SZ * cosf((-1) * g->player->angle + M_PI) + 7 * TILE_SZ, 6 * TILE_SZ * sinf((-1) * g->player->angle + M_PI) + 7 * TILE_SZ, H_RED, "N");

	return (0);
}

void	play(t_game *g)
{
	init_game(g);
	init_minimap(g);
	init_walls(g);
	mlx_hook(g->win, 17, 1L << 17, &mlx_close, g);
	mlx_hook(g->win, 2, 1L << 0, &press_key, g);
	mlx_hook(g->win, 3, 1L << 1, &release_key, g);
	mlx_loop_hook(g->mlx, &mlx_play, g);
	mlx_loop(g->mlx);
}
