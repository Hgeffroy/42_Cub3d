/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:34:38 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/02 13:11:38 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_wall_north(t_data *cub)
{
	cub->walls[NORTH].img = mlx_xpm_file_to_image(cub->mlx, cub->txr.north,
			&cub->walls[NORTH].width, &cub->walls[NORTH].height);
	if (!cub->walls[NORTH].img)
		return (-1);
	cub->walls[NORTH].addr = mlx_get_data_addr(cub->walls[NORTH].img,
			&cub->walls[NORTH].bits_per_pixel, &cub->walls[NORTH].line_len,
			&cub->walls[NORTH].endian);
	if (!cub->walls[NORTH].addr)
		return (-1);
	return (0);
}

int	init_wall_south(t_data *cub)
{
	cub->walls[SOUTH].img = mlx_xpm_file_to_image(cub->mlx, cub->txr.south,
			&cub->walls[SOUTH].width, &cub->walls[SOUTH].height);
	if (!cub->walls[SOUTH].img)
		return (-1);
	cub->walls[SOUTH].addr = mlx_get_data_addr(cub->walls[SOUTH].img,
			&cub->walls[SOUTH].bits_per_pixel, &cub->walls[SOUTH].line_len,
			&cub->walls[SOUTH].endian);
	if (!cub->walls[SOUTH].addr)
		return (-1);
	return (0);
}

int	init_wall_west(t_data *cub)
{
	cub->walls[WEST].img = mlx_xpm_file_to_image(cub->mlx, cub->txr.west,
			&cub->walls[WEST].width, &cub->walls[WEST].height);
	if (!cub->walls[WEST].img)
		return (-1);
	cub->walls[WEST].addr = mlx_get_data_addr(cub->walls[WEST].img,
			&cub->walls[WEST].bits_per_pixel, &cub->walls[WEST].line_len,
			&cub->walls[WEST].endian);
	if (!cub->walls[WEST].addr)
		return (-1);
	return (0);
}

int	init_wall_east(t_data *cub)
{
	cub->walls[EAST].img = mlx_xpm_file_to_image(cub->mlx, cub->txr.east,
			&cub->walls[EAST].width, &cub->walls[EAST].height);
	if (!cub->walls[EAST].img)
		return (-1);
	cub->walls[EAST].addr = mlx_get_data_addr(cub->walls[EAST].img,
			&cub->walls[EAST].bits_per_pixel, &cub->walls[EAST].line_len,
			&cub->walls[EAST].endian);
	if (!cub->walls[EAST].addr)
		return (-1);
	return (0);
}

int	init_door(t_data *cub)
{
	cub->walls[DOOR].img = mlx_xpm_file_to_image(cub->mlx, DOORTXR,
			&cub->walls[DOOR].width, &cub->walls[DOOR].height);
	if (!cub->walls[DOOR].img)
		return (-1);
	cub->walls[DOOR].addr = mlx_get_data_addr(cub->walls[DOOR].img,
			&cub->walls[DOOR].bits_per_pixel, &cub->walls[DOOR].line_len,
			&cub->walls[DOOR].endian);
	if (!cub->walls[DOOR].addr)
		return (-1);
	return (0);
}

int	init_walls(t_data *cub)
{
	int	i;

	const t_init_wall	tab[] = {&init_wall_north, &init_wall_south, \
									&init_wall_west, &init_wall_east, &init_door};
									
	i = 0;
	while (i < 5)
	{
		if ((*tab[i])(cub) < 0)
			return (-1);
		i++;
	}
	return (0);
}
