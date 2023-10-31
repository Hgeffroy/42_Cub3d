/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:49:53 by xcharra           #+#    #+#             */
/*   Updated: 2023/10/31 17:22:31 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static t_textures	_init_txr(void)
{
	t_textures	txr;

	txr.north = NULL;
	txr.south = NULL;
	txr.west = NULL;
	txr.east = NULL;
	return (txr);
}

static void	_init_rgb(t_data *cub)
{
	cub->c_rgb[R] = -1;
	cub->c_rgb[G] = -1;
	cub->c_rgb[B] = -1;
	cub->f_rgb[R] = -1;
	cub->f_rgb[G] = -1;
	cub->f_rgb[B] = -1;
}

static void	_init_cub(t_data *cub)
{
	cub->map_file = NULL;
	cub->txr = _init_txr();
	_init_rgb(cub);
	cub->end_desc = -1;
	cub->map = NULL;
	cub->player.x = 0;
	cub->player.y = 0;
	cub->doors = NULL;
	cub->start = 0;
	cub->max_y = 0;
	cub->max_x = 0;
}

void	clear_parsing(t_data *cub)
{
	free_txr(cub->txr);
	if (BONUS && cub->doors)
		free(cub->doors);
	ft_tabfree(cub->map);
}

int	parsing(char *map_path, t_data *cub)
{
	_init_cub(cub);
	if (ft_strlen(map_path) < 5
		|| ft_strcmp(&map_path[ft_strlen(map_path) - 4], ".cub\0"))
		return (ft_fdprintf(2, E_WREXT), 1);
	if (get_map_file(map_path, cub))
		return (1);
	if (get_txr_and_rgb(cub))
		return (ft_tabfree(cub->map_file), 1);
	if (get_map(cub))
		return (free_txr(cub->txr), ft_tabfree(cub->map_file), 1);
	ft_tabfree(cub->map_file);
	// clear_parsing(cub);
	return (0);
}
