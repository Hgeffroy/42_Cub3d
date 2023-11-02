/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:18:01 by xcharra           #+#    #+#             */
/*   Updated: 2023/11/02 14:10:42 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	_count_doors(char **map)
{
	size_t	doors;
	size_t	y;
	size_t	x;

	doors = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'D')
				doors++;
			x++;
		}
		y++;
	}
	return (doors);
}

static t_door	*_init_doors(size_t size)
{
	size_t	i;
	t_door	*doors;

	i = 0;
	doors = malloc(sizeof(t_door) * (size + 1));
	if (!doors)
		return (NULL);
	while (i < size)
	{
		doors[i].pos = 1;
		doors[i].x = 0;
		doors[i].y = 0;
		doors[i].state = NEUTRAL;
		i++;
	}
	doors[i].pos = -1;
	return (doors);
}

void	_find_doors(t_data *cub)
{
	size_t	i;
	size_t	x;
	size_t	y;

	i = 0;
	y = 0;
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (cub->map[y][x] == 'D')
			{
				cub->doors[i].x = x;
				cub->doors[i].y = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	replace_doors(t_data *cub)
{
	size_t	i;

	i = 0;
	while (cub->doors && cub->doors[i].pos != -1)
	{
		cub->map[cub->doors[i].y][cub->doors[i].x] = 'D';
		i++;
	}
}

int	get_doors(t_data *cub)
{
	size_t	doors;

	doors = _count_doors(cub->map);
	if (doors == 0)
		return (0);
	cub->doors = _init_doors(doors);
	if (!cub->doors)
		return (1);
	_find_doors(cub);
	return (0);
}
