/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:55:41 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/31 16:00:15 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "cub3D.h"

typedef void	(*t_init_col)(t_game *g, t_wallray *wallray);
typedef void	(*t_wall_color)(t_game *g, t_wallray *wallray);

void			init_minimap(t_game *g);
void			draw_minimap(t_game *g);
float			minimap_ray(t_game *g, float angle);
float			raycasting(t_game *g, float angle);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
int				draw_display(t_game *g);
void			init_col(t_game *g, t_wallray *wallray);
int				get_color(t_walltext w, int x, int y);
void			get_wall_color(t_game *g, t_wallray *wallray);


#endif