/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:46:01 by xcharra           #+#    #+#             */
/*   Updated: 2023/10/31 16:00:15 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	_is_illegal_char(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (ft_strischarset(map[i], CHARSET))
			i++;
		else
			return (ft_fdprintf(2, E_ILLCHAR, map[i]), 1);
	}
	return (0);
}

static int	_skip_whitespaces(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (ft_strischarset(map[i], " \n"))
			(i)++;
		else
			return (i);
	}
	return (i);
}

static int	_is_one_player(char **map)
{
	size_t	i;
	size_t	j;
	size_t	p;

	i = 0;
	p = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_ischarset(map[i][j], "NSEW\0"))
				p++;
			if (p > 1)
				return (ft_fdprintf(2, E_MPLAYER), 0);
			j++;
		}
		i++;
	}
	if (p == 0)
		return (ft_fdprintf(2, E_NPLAYER), 0);
	return (1);
}

static int	_get_real_size_map(t_data *cub)
{
	size_t	i;
	size_t	j;

	cub->start = _skip_whitespaces(cub->map);
	i = cub->start;
	while (cub->map[i] && !ft_strischarset(cub->map[i], " \n"))
	{
		j = 0;
		while (cub->map[i][j])
			j++;
		if (cub->max_x < j)
			cub->max_x = j;
		i++;
	}
	cub->max_y = i - cub->start;
	while (cub->map[i] && ft_strischarset(cub->map[i], " \n"))
		i++;
	if (cub->map[i])
		return (ft_fdprintf(2, E_THAMAP, cub->map[i]), 1);
	return (0);
}

int	check_map(t_data *cub)
{
	if (_is_illegal_char(cub->map))
		return (ft_tabfree(cub->map), 1);
	if (_get_real_size_map(cub))
		return (ft_tabfree(cub->map), 1);
	if (get_new_map(cub))
		return (1);
	if (!_is_one_player(cub->map))
		return (ft_tabfree(cub->map), 1);
	if (!is_closed_map(cub))
	{
		if (cub->doors)
			free(cub->doors);
		return (ft_tabfree(cub->map), 1);
	}
	if (BONUS && cub->doors)
		replace_doors(cub);
	return (0);
}
