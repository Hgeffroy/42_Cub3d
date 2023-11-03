/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:58:35 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/03 16:57:35 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mlx_close(t_data *cub)
{
	int	i;

	i = 0;
	mlx_destroy_image(cub->mlx, cub->display.img);
	while (i < 4)
	{
		mlx_destroy_image(cub->mlx, cub->walls[i].img);
		i++;
	}
	if (BONUS)
		mlx_destroy_image(cub->mlx, cub->walls[DOOR].img);
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
	free(cub->mlx);
	clear_parsing(cub);
	exit (0);
}

int	init_game(t_data *cub)
{
	cub->player.fx = cub->player.x + 0.5;
	cub->player.fy = cub->player.y + 0.5;
	if (cub->player.dir == 'E')
		cub->player.angle = 0;
	if (cub->player.dir == 'N')
		cub->player.angle = 3 * M_PI_2;
	if (cub->player.dir == 'W')
		cub->player.angle = M_PI;
	if (cub->player.dir == 'S')
		cub->player.angle = M_PI_2;
	init_mlx(cub);
	if (init_walls(cub) < 0)
		return (-1);
	ft_bzero(&(cub->movement), 8);
	return (0);
}

int	display(t_data *cub)
{
	draw_display(cub);
	if (BONUS)
		draw_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->display.img, 0, 0);
	if (BONUS)
		mlx_string_put(cub->mlx, cub->win,
			6 * TILE_SZ * cosf((-1) * cub->player.angle + M_PI) + 7 * TILE_SZ,
			6 * TILE_SZ * sinf((-1) * cub->player.angle + M_PI) + 7 * TILE_SZ,
			H_RED, "N");
	return (0);
}

int	mlx_play(t_data *cub)
{
	if (cub->movement.rotate_left)
		rotate_left(cub, 10);
	if (cub->movement.rotate_right)
		rotate_right(cub, 10);
	if (cub->movement.move_up)
		move_forward(cub);
	if (cub->movement.move_down)
		move_backward(cub);
	if (cub->movement.move_left)
		move_left(cub);
	if (cub->movement.move_right)
		move_right(cub);
	if (BONUS)
		move_doors(cub);
	display(cub);
	return (0);
}

int	play(t_data *cub)
{
	if (init_game(cub) < 0)
		return (-1);
	mlx_hook(cub->win, 2, 1L << 0, &press_key, cub);
	mlx_hook(cub->win, 3, 1L << 1, &release_key, cub);
	mlx_hook(cub->win, 4, 1L << 2, &press_mouse, cub);
	mlx_hook(cub->win, 5, 1L << 3, &release_mouse, cub);
	 if (BONUS)
	 	mlx_hook(cub->win, 6, 1L << 6, &move_mouse, cub);
	mlx_loop_hook(cub->mlx, &mlx_play, cub);
	mlx_loop(cub->mlx);
	return (0);
}
