/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:03:48 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/12 13:04:08 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



int	rgb_to_int(char *str)
{
	int		i;
	int		j;
	int		power;
	char	*toconvert;
	int		res;

	res = 0;
	power = 2;
	i = 0;
	while (power >= 0)
	{
		while (!ft_isdigit(str[i]))
			i++;
		j = i;
		while (ft_isdigit(str[j]))
			j++;
		toconvert = ft_strndup(&str[i], j - i);
		i = j;
		res += (ft_atoi(toconvert) % 256) * pow(256, power);
		free(toconvert);
		power--;
	}
	return (res);
}

/*
Faire un ptr sur fct
*/
void	fill_texture(t_game **g, char *line)
{
	// Il va falloir check les doublons ici aussi.
	if (line[0] == 'C')
		(*g)->colors.rgb_roof = ft_strdup(line); // Protection malloc, passer les whitespaces et enlever le \n.
	else if (line[0] == 'F')
		(*g)->colors.rgb_floor = ft_strdup(line); // Protection malloc, passer les whitespaces.
	else if (line[0] == 'N')
		(*g)->textures.north = ft_strdup(line); // Protection malloc, passer les whitespaces.
	else if (line[0] == 'S')
		(*g)->textures.south = ft_strdup(line); // Protection malloc, passer les whitespaces.
	else if (line[0] == 'W')
		(*g)->textures.west = ft_strdup(line); // Protection malloc, passer les whitespaces.
	else if (line[0] == 'E')
		(*g)->textures.east = ft_strdup(line); // Protection malloc, passer les whitespaces.
}

int	is_textstart(char *line)
{
	if (line[0] == 'C')
		return (YES);
	else if (line[0] == 'F')
		return (YES);
	else if (line[1] && line[0] == 'N' && line[1] == 'O')
		return (YES);
	else if (line[1] && line[0] == 'S' && line[1] == 'O')
		return (YES);
	else if (line[1] && line[0] == 'W' && line[1] == 'E')
		return (YES);
	else if (line[1] && line[0] == 'E' && line[1] == 'A')
		return (YES);
	return (NO);
}


void	check_line(t_game **g, char *line)
{
	int	i;
	int	text_start;

	i = -1;
	text_start = NO;
	while (line[++i])
	{
		text_start = is_textstart(&line[i]);
		if (text_start == YES)
			break ;
	}
	if (text_start == NO)
		return ;
	fill_texture(g, &line[i]);
}

char	*set_texture(char *texture)
{
	int		i;
	char	*res;
	
	i = 2;
	while (is_whitespace(texture[i]) == YES)
		i++;
	res = ft_strndup(&texture[i], ft_strlen(texture) - i - 1);
	return (res);
}

int	init_walls(t_game *g)
{
	char	*texture[4];
	
	texture[0] = set_texture(g->textures.north);
	texture[1] = set_texture(g->textures.south);
	texture[2] = set_texture(g->textures.west);
	texture[3] = set_texture(g->textures.east);

	g->walls[NORTH].img = mlx_xpm_file_to_image(g->mlx, texture[0], &g->walls[NORTH].width, &g->walls[NORTH].height);
	if (!g->walls[NORTH].img)
		return (-1);
	g->walls[NORTH].addr = mlx_get_data_addr(g->walls[NORTH].img, &g->walls[NORTH].bits_per_pixel, &g->walls[NORTH].line_len, &g->walls[NORTH].endian);
	g->walls[SOUTH].img = mlx_xpm_file_to_image(g->mlx, texture[1], &g->walls[SOUTH].width, &g->walls[SOUTH].height);
	if (!g->walls[SOUTH].img)
		return (-1);
	g->walls[SOUTH].addr = mlx_get_data_addr(g->walls[SOUTH].img, &g->walls[SOUTH].bits_per_pixel, &g->walls[SOUTH].line_len, &g->walls[SOUTH].endian);
	g->walls[WEST].img = mlx_xpm_file_to_image(g->mlx, texture[2], &g->walls[WEST].width, &g->walls[WEST].height);
	if (!g->walls[WEST].img)
		return (-1);
	g->walls[WEST].addr = mlx_get_data_addr(g->walls[WEST].img, &g->walls[WEST].bits_per_pixel, &g->walls[WEST].line_len, &g->walls[WEST].endian);
	g->walls[EAST].img = mlx_xpm_file_to_image(g->mlx, texture[3], &g->walls[EAST].width, &g->walls[EAST].height);
	if (!g->walls[EAST].img)
		return (-1);
	g->walls[EAST].addr = mlx_get_data_addr(g->walls[EAST].img, &g->walls[EAST].bits_per_pixel, &g->walls[EAST].line_len, &g->walls[EAST].endian);
	return (0);
}

int	get_textures(t_game **g, int fd)
{
	char	*line;

	line = NULL;
	while (is_mapline(line) == NO)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		check_line(g, line);
	}
	free(line);
	(*g)->colors.hexa_roof = rgb_to_int((*g)->colors.rgb_roof);
	(*g)->colors.hexa_floor = rgb_to_int((*g)->colors.rgb_floor);
	// On peut check qu'on a bien toutes les textures ici.
	// La derniere ligne est la premiere ligne de la map, donc soit on la recupere soit on reparcourt le fichier.
	return (0);
}
