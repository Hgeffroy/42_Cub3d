/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:18:28 by xcharra           #+#    #+#             */
/*   Updated: 2023/11/02 18:21:21 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_txr(t_textures txr)
{
	if (txr.north)
		free(txr.north);
	txr.north = NULL;
	if (txr.south)
		free(txr.south);
	txr.south = NULL;
	if (txr.west)
		free(txr.west);
	txr.west = NULL;
	if (txr.east)
		free(txr.east);
	txr.east = NULL;
}

void	print_tab_msg(char **tab, char *msg)
{
	size_t	i;

	i = 0;
	ft_printf("%s", msg);
	while (tab && tab[i])
	{
		ft_printf(RED"%s"RESET, tab[i]);
		i++;
	}
}

void	rgb_converter(t_data *cub)
{
	cub->rgb_c = cub->c_rgb[R] << 16 | cub->c_rgb[G] << 8 | cub->c_rgb[B];
	cub->rgb_f = cub->f_rgb[R] << 16 | cub->f_rgb[G] << 8 | cub->f_rgb[B];
}

void	print_parsing(t_data *cub)
{
	print_tab_msg(cub->map_file, GREEN"map file:\n"RESET);
	if (!cub->map_file)
		ft_printf(BLUE"(null)"RESET);
	ft_printf(GREEN"\ntextures paths:\n"RESET);
	ft_printf(RED"no_txr=%s\n"RESET, cub->txr.north);
	ft_printf(RED"so_txr=%s\n"RESET, cub->txr.south);
	ft_printf(RED"we_txr=%s\n"RESET, cub->txr.west);
	ft_printf(RED"ea_txr=%s\n"RESET, cub->txr.east);
	ft_printf(GREEN"\nrgb values:\n"RESET);
	ft_printf(RED"C r = %d, g = %d, B = %d\n"RESET,
		cub->c_rgb[R], cub->c_rgb[G], cub->c_rgb[B]);
	ft_printf(RED"F r = %d, g = %d, B = %d\n"RESET,
		cub->f_rgb[R], cub->f_rgb[G], cub->f_rgb[B]);
	print_tab_msg(cub->map, GREEN"map file:\n"RESET);
	ft_printf(RED"max_x: %d\n"RESET, cub->max_x);
}
