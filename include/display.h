/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:55:41 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/12 09:16:52 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub3d.h"

void	init_minimap(t_game *g);
void	draw_minimap(t_game *g);
float	minimap_ray(t_game *g, float angle);
float	raycasting(t_game *g, float angle);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		draw_display(t_game *g);
void	init_col(t_game *g, t_wallray *wallray);
int		get_color(t_walltext w, int x, int y);
void	get_wall_color(t_game *g, t_wallray *wallray);

typedef	void	(*t_init_col)(t_game *g, t_wallray *wallray);
typedef void	(*t_wall_color)(t_game *g, t_wallray *wallray);

#endif