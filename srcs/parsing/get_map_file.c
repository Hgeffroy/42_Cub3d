/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:49:53 by xcharra           #+#    #+#             */
/*   Updated: 2023/10/31 15:41:07 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

static char	**_start_tab(char *line)
{
	char	**tab;

	tab = malloc(sizeof(char *) * 2);
	if (!tab)
		return (NULL);
	tab[0] = ft_strdup(line);
	tab[1] = NULL;
	if (!tab[0])
		return (free(tab), NULL);
	return (tab);
}

static char	**_add_line_to_tab(char **tab, char *line)
{
	size_t	i;
	char	**newtab;

	i = 0;
	if (!tab)
		return (_start_tab(line));
	while (tab[i])
		i++;
	newtab = malloc(sizeof(char *) * (i + 2));
	if (!newtab)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		newtab[i] = ft_strdup(tab[i]);
		if (!newtab[i])
			ft_tabfree(newtab);
		i++;
	}
	newtab[i] = ft_strdup(line);
	newtab[i + 1] = NULL;
	ft_tabfree(tab);
	return (newtab);
}

int	get_map_file(char *map_path, t_data *cub)
{
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (perror(map_path), 1);
	cub->map_file = NULL;
	line = get_next_line(fd);
	if (!line)
		return (close(fd), ft_fdprintf(2, E_EMMA), 2);
	while (line)
	{
		cub->map_file = _add_line_to_tab(cub->map_file, line);
		free(line);
		if (!cub->map_file)
			return (close(fd), ft_fdprintf(2, E_NOMEM), 3);
		line = get_next_line(fd);
		if (!line && errno == ENOMEM)
			return (ft_tabfree(cub->map_file), close(fd),
				ft_printf(E_NOMEM), 4);
	}
	close(fd);
	return (0);
}
