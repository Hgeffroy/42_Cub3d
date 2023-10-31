/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_txr_and_rgb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:18:15 by xcharra           #+#    #+#             */
/*   Updated: 2023/10/31 16:00:15 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*_get_txr_path(char *map_line, char *dir)
{
	char	*tmp;
	size_t	i;

	tmp = ft_strnstr(map_line, dir, ft_strlen(map_line)) + 2;
	i = 0;
	while (tmp[i] && tmp[i] == ' ')
		i++;
	if (tmp[i] && tmp[i + 1])
		return (ft_strtrim(&tmp[i], "\n"));
	return (NULL);
}

static void	_get_rgb(char *map_line, int rgb[3], char c)
{
	char	*tmp;
	size_t	i;

	tmp = ft_strchr(map_line, c) + 1;
	i = 0;
	while (tmp[i] && tmp[i] == ' ')
		i++;
	if (ft_isdigit(tmp[i]))
		if (ft_atoi_safe(&tmp[i], &rgb[R]) || (rgb[R] > 255 || rgb[R] < 0))
			return ;
	while (ft_isdigit(tmp[i]))
		i++;
	while (tmp[i] && (tmp[i] == ',' || tmp[i] == ' '))
		i++;
	if (ft_isdigit(tmp[i]))
		if (ft_atoi_safe(&tmp[i], &rgb[G]) || (rgb[G] > 255 || rgb[G] < 0))
			return ;
	while (ft_isdigit(tmp[i]))
		i++;
	while (tmp[i] && (tmp[i] == ',' || tmp[i] == ' '))
		i++;
	if (ft_isdigit(tmp[i]))
		if (ft_atoi_safe(&tmp[i], &rgb[B]) || (rgb[B] > 255 || rgb[B] < 0))
			return ;
}

static int	_check_txr_and_rgb(t_data *cub)
{
	if (!cub->txr.north || !cub->txr.south || !cub->txr.west || !cub->txr.east)
		return (ft_fdprintf(2, E_NOTXR), 1);
	if (ft_strlen(cub->txr.north) < 5
		|| ft_strcmp(&cub->txr.north[ft_strlen(cub->txr.north) - 4], ".xpm\0"))
		return (ft_fdprintf(2, E_WRTXREXT, "north"), 1);
	if (ft_strlen(cub->txr.south) < 5
		|| ft_strcmp(&cub->txr.south[ft_strlen(cub->txr.south) - 4], ".xpm\0"))
		return (ft_fdprintf(2, E_WRTXREXT, "south"), 1);
	if (ft_strlen(cub->txr.west) < 5
		|| ft_strcmp(&cub->txr.west[ft_strlen(cub->txr.west) - 4], ".xpm\0"))
		return (ft_fdprintf(2, E_WRTXREXT, "west"), 1);
	if (ft_strlen(cub->txr.east) < 5
		|| ft_strcmp(&cub->txr.east[ft_strlen(cub->txr.east) - 4], ".xpm\0"))
		return (ft_fdprintf(2, E_WRTXREXT, "east"), 1);
	if (cub->c_rgb[R] < 0 || cub->c_rgb[G] < 0 || cub->c_rgb[B] < 0
		|| cub->f_rgb[R] < 0 || cub->f_rgb[G] < 0 || cub->f_rgb[B] < 0)
		return (ft_fdprintf(2, E_NORGB), 2);
	rgb_converter(cub);
	return (0);
}

static int	_get_txr(char *map_line, char *dir, char **txr_path)
{
	if (ft_strnstr(map_line, dir, ft_strlen(map_line)))
	{
		if (!*txr_path)
			*txr_path = _get_txr_path(map_line, dir);
		else
			return (ft_fdprintf(2, E_DUPPATH, dir), 1);
	}
	return (0);
}

int	get_txr_and_rgb(t_data *cub)
{
	size_t	i;

	i = 0;
	while (cub->map_file[i])
	{
		if (_get_txr(cub->map_file[i], "NO", &(cub->txr.north)))
			return (free_txr(cub->txr), 1);
		if (_get_txr(cub->map_file[i], "SO", &(cub->txr.south)))
			return (free_txr(cub->txr), 1);
		if (_get_txr(cub->map_file[i], "WE", &(cub->txr.west)))
			return (free_txr(cub->txr), 1);
		if (_get_txr(cub->map_file[i], "EA", &(cub->txr.east)))
			return (free_txr(cub->txr), 1);
		if (ft_strchr(cub->map_file[i], 'C'))
			_get_rgb(cub->map_file[i], cub->c_rgb, 'C');
		if (ft_strchr(cub->map_file[i], 'F'))
			_get_rgb(cub->map_file[i], cub->f_rgb, 'F');
		i++;
	}
	if (_check_txr_and_rgb(cub))
		return (free_txr(cub->txr), 1);
	cub->end_desc = i;
	return (0);
}
