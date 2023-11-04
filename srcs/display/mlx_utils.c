/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:25:15 by xcharra           #+#    #+#             */
/*   Updated: 2023/11/04 09:26:16 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
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
	cub->win = mlx_new_window(cub->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	cub->display.img = mlx_new_image(cub->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	cub->display.addr = mlx_get_data_addr(cub->display.img,
			&cub->display.bits_per_pixel, &cub->display.line_len,
			&cub->display.endian);
}
