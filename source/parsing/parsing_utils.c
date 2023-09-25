/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:04:36 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/25 13:43:27 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file(char *file)
{
	int	fd;
	
	if (ft_strncmp(&file[ft_strlen(file) - 4], ".ber", 4))
		return (ft_dprintf(2, "Wrong map extension"), -1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_dprintf(2, "Couldn't open file, check path, name and rights please");
	return (fd);
}

int	is_mapline(char *line)
{
	int	i;
	int	player;
	
	if (!line)
		return (NO);
	if (line[0] == '\n')
		return (NO);
	i = -1;
	player = 0;
	while (line[++i])
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
		{
			player++;
			if (player > 1)
				return (NO);
		}
		else if (line[i] != '0' && line[i] != '1' && line[i] != ' ' && line[i] != '\n')
			return (NO);
	}
	return (YES);
}
