/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:04:00 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/25 13:29:25 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*go_to_map(int fd)
{
	char *line;
	
	line = NULL;
	while (is_mapline(line) == NO)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	return (line);
}

char	**malloc_map(char *file)
{
	int		fd;
	int		mapsz;
	char	*line;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = go_to_map(fd);
	mapsz = 1;
	while (is_mapline(line) == YES)
	{
		if (line)
			free(line);
		mapsz++;
		line = get_next_line(fd);
	}
	map = (char **)malloc(sizeof(char *) * mapsz + 1);
	if (!map)
		return (NULL);
	close (fd);
	return (map);
}

char	**fill_map(char **map, char *line, int fd)
{
	int	i;
	
	i = 0;
	while (is_mapline(line) == YES)
	{
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	if (line)
		free(line);
	return (map);
}

char	**get_map(char *file)
{
	int		fd;
	char	*line;
	char	**map;

	map = malloc_map(file);
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = NULL;
	line = go_to_map(fd);
	map = fill_map(map, line, fd);
	if (!map)
		return (NULL);
	close(fd);	
	return (map);
}
