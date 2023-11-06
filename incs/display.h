/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:55:41 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/06 07:58:40 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "cub3D.h"

void	init_mlx(t_data *cub);
void	draw_minimap(t_data *cub);
float	minimap_ray(t_data *cub, float angle);
float	raycasting(t_data *cub, float angle, int optn);
void	pixel_put(t_img *img, int x, int y, int color);
int		draw_display(t_data *cub);
void	init_col(t_data *cub, t_wallray *wallray);
int		get_color(t_walltext w, int x, int y);
void	get_wall_color(t_data *cub, t_wallray *wallray);

void	init_col_d(t_data *cub, t_wallray *wallray);
void	get_door_color(t_data *cub, t_wallray *wallray);

int		test(t_data *cub, float angle, float *len, int optn);

typedef void	(*t_init_col)(t_data *cub, t_wallray *wallray);
typedef void	(*t_wall_color)(t_data *cub, t_wallray *wallray);
typedef	int		(*t_ray_wall)(t_data *cub, float angle, float *len, int doornb);

#endif