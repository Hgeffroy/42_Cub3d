/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:01:19 by xcharra           #+#    #+#             */
/*   Updated: 2023/11/08 17:01:29 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color(t_walltext w, int x, int y)
{
	char	*addr;

	addr = w.addr + y * w.line_len + x * (w.bits_per_pixel / 8);
	return (*(unsigned int *)addr);
}

void	init_mlx(t_data *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return ((void)mlx_close(cub));
	cub->win = mlx_new_window(cub->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!cub->win)
		return ((void)mlx_close(cub));
	cub->display.img = mlx_new_image(cub->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!cub->display.img)
		return ((void)mlx_close(cub));
	cub->display.addr = mlx_get_data_addr(cub->display.img,
			&cub->display.bits_per_pixel, &cub->display.line_len,
			&cub->display.endian);
	if (!cub->display.addr)
		return ((void)mlx_close(cub));
}
