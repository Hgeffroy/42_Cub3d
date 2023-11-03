/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:25:15 by xcharra           #+#    #+#             */
/*   Updated: 2023/11/03 15:25:52 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_mlx(t_data *cub)
{
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	cub->display.img = mlx_new_image(cub->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	cub->display.addr = mlx_get_data_addr(cub->display.img,
			&cub->display.bits_per_pixel, &cub->display.line_len,
			&cub->display.endian);
}
