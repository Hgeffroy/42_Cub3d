/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:46:01 by xcharra           #+#    #+#             */
/*   Updated: 2023/10/31 15:41:07 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

static void	_flood_fill_map(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] ||!map[y][x]
		|| map[y][x] == 'x' || map[y][x] == '1'
		|| map[y][x] == ' ' || map[y][x] == '\n')
		return ;
	if (ft_ischarset(map[y][x], FFCHARSET))
		map[y][x] = 'x';
	_flood_fill_map(map, x - 1, y);
	_flood_fill_map(map, x, y - 1);
	_flood_fill_map(map, x + 1, y);
	_flood_fill_map(map, x, y + 1);
}

static int	_is_closed(char **map, int x, int y)
{
	static int	ret = 1;

	if (x < 0 || y < 0 || !map[y] ||!map[y][x]
		|| map[y][x] == ' ' || map[y][x] == '\n')
		return (0);
	if (map[y] && map[y][x] && (map[y][x] == '1' || map[y][x] == '0'))
		return (1);
	if (map[y][x] == 'x')
	{
		map[y][x] = '0';
		ret &= _is_closed(map, x - 1, y);
		ret &= _is_closed(map, x, y - 1);
		ret &= _is_closed(map, x + 1, y);
		ret &= _is_closed(map, x, y + 1);
	}
	return (ret);
}

int	is_closed_map(t_data *cub)
{
	_flood_fill_map(cub->map, cub->player.x, cub->player.y);
//	print_tab_msg(cub->map, UNDERLINE"DEBUG: After flood filling :\n"RESET);
	if (!_is_closed(cub->map, cub->player.x, cub->player.y))
		return (ft_fdprintf(2, E_MNCLOSED), 0);
	return (1);
}
