/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_doors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:34:38 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/08 13:32:20 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_door(t_data *cub)
{
	cub->walls[DOOR].img = mlx_xpm_file_to_image(cub->mlx, DOORTXR,
			&cub->walls[DOOR].width, &cub->walls[DOOR].height);
	if (!cub->walls[DOOR].img)
		return (ft_fdprintf(2, E_OPNTXR, "DOOR"), -1);
	cub->walls[DOOR].addr = mlx_get_data_addr(cub->walls[DOOR].img,
			&cub->walls[DOOR].bits_per_pixel, &cub->walls[DOOR].line_len,
			&cub->walls[DOOR].endian);
	if (!cub->walls[DOOR].addr)
		return (-1);
	return (0);
}
