/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:58:35 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/31 17:30:01 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mlx_close(t_data *cub)
{
	int	i;

	i = 0;
	mlx_destroy_image(cub->mlx, cub->display.img);
	while (i < 4)
	{
		mlx_destroy_image(cub->mlx, cub->walls[i].img);
		i++;
	}
	mlx_destroy_window(cub->mlx, cub->win);
	free(cub);
	exit (0);
}

int	is_whitespace(char c)
{
	if (c == ' ' || (c > 8 && c < 13))
		return (YES);
	return (NO);
}

char	*set_texture(char *texture)
{
	int		i;
	char	*res;
	
	i = 0;
	while (is_whitespace(texture[i]) == YES)
		i++;
	res = ft_strndup(&texture[i], ft_strlen(texture) - i);
	return (res);
}

int	init_walls(t_data *cub)
{
	char	*texture[4];

	int	i = 0;
	
	texture[0] = set_texture(cub->txr.north);
	texture[1] = set_texture(cub->txr.south);
	texture[2] = set_texture(cub->txr.west);
	texture[3] = set_texture(cub->txr.east);

	while (i < 4)
		printf("lala: %s\n", texture[i++]);
	
	cub->walls[NORTH].img = mlx_xpm_file_to_image(cub->mlx, texture[0], &cub->walls[NORTH].width, &cub->walls[NORTH].height);
	if (!cub->walls[NORTH].img)
		return (-1);
	cub->walls[NORTH].addr = mlx_get_data_addr(cub->walls[NORTH].img, &cub->walls[NORTH].bits_per_pixel, &cub->walls[NORTH].line_len, &cub->walls[NORTH].endian);
	cub->walls[SOUTH].img = mlx_xpm_file_to_image(cub->mlx, texture[1], &cub->walls[SOUTH].width, &cub->walls[SOUTH].height);
	if (!cub->walls[SOUTH].img)
		return (-1);
	cub->walls[SOUTH].addr = mlx_get_data_addr(cub->walls[SOUTH].img, &cub->walls[SOUTH].bits_per_pixel, &cub->walls[SOUTH].line_len, &cub->walls[SOUTH].endian);
	cub->walls[WEST].img = mlx_xpm_file_to_image(cub->mlx, texture[2], &cub->walls[WEST].width, &cub->walls[WEST].height);
	if (!cub->walls[WEST].img)
		return (-1);
	cub->walls[WEST].addr = mlx_get_data_addr(cub->walls[WEST].img, &cub->walls[WEST].bits_per_pixel, &cub->walls[WEST].line_len, &cub->walls[WEST].endian);
	cub->walls[EAST].img = mlx_xpm_file_to_image(cub->mlx, texture[3], &cub->walls[EAST].width, &cub->walls[EAST].height);
	if (!cub->walls[EAST].img)
		return (-1);
	cub->walls[EAST].addr = mlx_get_data_addr(cub->walls[EAST].img, &cub->walls[EAST].bits_per_pixel, &cub->walls[EAST].line_len, &cub->walls[EAST].endian);
	return (0);
}

int	init_game(t_data *cub)
{
	cub->player.fx = cub->player.x + 0.5;
	cub->player.fy = cub->player.y + 0.5;
	if (cub->player.dir == 'E')
		cub->player.angle = 0;
	if (cub->player.dir == 'N')
		cub->player.angle = M_PI_2;
	if (cub->player.dir == 'W')
		cub->player.angle = M_PI;
	if (cub->player.dir == 'S')
		cub->player.angle = - M_PI_2;
	init_minimap(cub);
	init_walls(cub);
	return (0);
}

int	display(t_data *cub)
{
	draw_display(cub);
	draw_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->display.img, 0, 0);
	/* mlx_string_put(cub->mlx, cub->win, \
			6 * TILE_SZ * cosf((-1) * cub->player.angle + M_PI) + 7 * TILE_SZ, \
			6 * TILE_SZ * sinf((-1) * cub->player.angle + M_PI) + 7 * TILE_SZ, \
			H_RED, "N"); */
	return (0);
}

int	mlx_play(t_data *cub)
{
	if (cub->movement.rotate_left)
		rotate_left(cub, 10);
	if (cub->movement.rotate_right)
		rotate_right(cub, 10);
	if (cub->movement.move_up)
		move_forward(cub);
	if (cub->movement.move_down)
		move_backward(cub);
	if (cub->movement.move_left)
		move_left(cub);
	if (cub->movement.move_right)
		move_right(cub);
	display(cub);
	return (0);
}

void	play(t_data *cub)
{
	init_game(cub);
	mlx_hook(cub->win, 2, 1L << 0, &press_key, cub);
	mlx_hook(cub->win, 3, 1L << 1, &release_key, cub);
	mlx_hook(cub->win, 4, 1L << 2, &press_mouse, cub);
	mlx_hook(cub->win, 5, 1L << 3, &release_mouse, cub);
	mlx_hook(cub->win, 6, 1L << 6, &move_mouse, cub);
	mlx_loop_hook(cub->mlx, &mlx_play, cub);
	mlx_loop(cub->mlx);
}
