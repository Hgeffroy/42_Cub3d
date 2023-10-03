/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:03:48 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/02 15:00:30 by hgeffroy         ###   ########.fr       */
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
		(*g)->colors->rgb_roof = ft_strdup(line); // Protection malloc, passer les whitespaces et enlever le \n.
	else if (line[0] == 'F')
		(*g)->colors->rgb_floor = ft_strdup(line); // Protection malloc, passer les whitespaces.
	else if (line[0] == 'N')
		(*g)->textures->north = ft_strdup(line); // Protection malloc, passer les whitespaces.
	else if (line[0] == 'S')
		(*g)->textures->south = ft_strdup(line); // Protection malloc, passer les whitespaces.
	else if (line[0] == 'W')
		(*g)->textures->west = ft_strdup(line); // Protection malloc, passer les whitespaces.
	else if (line[0] == 'E')
		(*g)->textures->east = ft_strdup(line); // Protection malloc, passer les whitespaces.
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
	char	*texture;
	
	g->north_wall = (t_walltext *)malloc(sizeof(t_walltext));
	g->south_wall = (t_walltext *)malloc(sizeof(t_walltext));
	g->west_wall = (t_walltext *)malloc(sizeof(t_walltext));
	g->east_wall = (t_walltext *)malloc(sizeof(t_walltext));
	texture = set_texture(g->textures->north);
	g->north_wall->img = mlx_xpm_file_to_image(g->mlx, texture, &g->north_wall->width, &g->north_wall->height);
	g->north_wall->addr = mlx_get_data_addr(g->north_wall->img, &g->north_wall->bits_per_pixel, &g->north_wall->line_len, &g->north_wall->endian);
	if (!g->north_wall->img)
		puts("lala");
	free(texture);
	return (0);
	// g->south_wall->img = mlx_xpm_file_to_image(g->mlx, g->textures->south, &g->south_wall->width, &g->south_wall->height);
	// g->west_wall->img = mlx_xpm_file_to_image(g->mlx, g->textures->west, &g->west_wall->width, &g->west_wall->height);
	// g->east_wall->img = mlx_xpm_file_to_image(g->mlx, g->textures->east, &g->east_wall->width, &g->east_wall->height);
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
	(*g)->colors->hexa_roof = rgb_to_int((*g)->colors->rgb_roof);
	(*g)->colors->hexa_floor = rgb_to_int((*g)->colors->rgb_floor);
	// On peut check qu'on a bien toutes les textures ici.
	// La derniere ligne est la premiere ligne de la map, donc soit on la recupere soit on reparcourt le fichier.
	return (0);
}
