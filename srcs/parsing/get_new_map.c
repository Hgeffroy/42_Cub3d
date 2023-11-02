/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:41:01 by xcharra           #+#    #+#             */
/*   Updated: 2023/10/31 16:00:15 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	**_rectangulate(t_data *cub)
{
	size_t	i;
	char	**newmap;

	i = 0;
	newmap = ft_calloc(sizeof(char *), cub->max_y + 1);
	if (!newmap)
		return (ft_tabfree(cub->map), NULL);
	while (i < cub->max_y)
	{
		newmap[i] = ft_calloc(sizeof(char), cub->max_x + 1);
		if (!newmap[i])
			return (ft_tabfree(cub->map), ft_tabfree(newmap), NULL);
		ft_strlcpy(newmap[i], cub->map[i + cub->start], cub->max_x + 1);
		i++;
	}
	newmap[i] = NULL;
	return (ft_tabfree(cub->map), newmap);
}

static void	_find_player(t_data *cub)
{
	cub->player.y = 0;
	while (cub->map && cub->map[cub->player.y])
	{
		cub->player.x = 0;
		while (cub->map[cub->player.y][cub->player.x])
		{
			if (ft_ischarset(cub->map[cub->player.y][cub->player.x], "NSEW"))
			{
				cub->player.dir = cub->map[cub->player.y][cub->player.x];
				return ;
			}
			cub->player.x++;
		}
		cub->player.y++;
	}
}

int	get_new_map(t_data *cub)
{
	cub->map = _rectangulate(cub);
	if (!cub->map)
		return (1);
	if (!cub->map[0])
		return (free(cub->map), ft_fdprintf(2, E_NOMAP), 1);
	_find_player(cub);
	if (BONUS)
		if (get_doors(cub) && !cub->doors)
			return (ft_tabfree(cub->map), 1);
	return (0);
}
