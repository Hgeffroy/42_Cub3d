/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:16:06 by xcharra           #+#    #+#             */
/*   Updated: 2023/10/31 15:41:07 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

static int	_skip_desc(t_data *cub)
{
	static char	*desc[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	int			i;
	size_t		j;
	size_t		k;

	i = 0;
	k = 0;
	while (cub->map_file[i] && k != 6)
	{
		j = 0;
		while (desc[j] && k != 6)
		{
			if (cub->map_file[i] && ft_strnstr(cub->map_file[i],
					desc[j], ft_strlen(cub->map_file[i])))
				k++;
			if (cub->map_file[i] && cub->map_file[i][0] != '\n'
			&& ft_strischarset(cub->map_file[i], CHARSET) && k != 6)
				return (-1);
			j++;
		}
		i++;
	}
	while (cub->map_file[i] && !ft_strncmp(cub->map_file[i], "\n", 1))
		i++;
	return (i);
}

int	get_map(t_data *cub)
{
	size_t	i;

	cub->end_desc = _skip_desc(cub);
	if (cub->end_desc < 0)
		return (ft_fdprintf(2, E_NOENDMAP));
	if (!cub->map_file[cub->end_desc])
		return (ft_fdprintf(2, E_NOMAP), 1);
	i = cub->end_desc;
	while (cub->map_file[i] && ft_strncmp(cub->map_file[i], "\n", 2))
		i++;
	cub->map = ft_tabdup(&cub->map_file[cub->end_desc]);
	if (!cub->map)
		return (3);
	if (check_map(cub))
		return (4);
	return (0);
}
