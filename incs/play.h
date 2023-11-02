/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:01:00 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/01 10:48:08 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAY_H
# define PLAY_H

int		press_key(int keycode, t_data *cub);
int		release_key(int keycode, t_data *cub);
void	move_forward(t_data *cub);
void	move_backward(t_data *cub);
void	move_left(t_data *cub);
void	move_right(t_data *cub);
void	rotate_left(t_data *cub, int ratio);
void	rotate_right(t_data *cub, int ratio);
int		play(t_data *cub);

int		mlx_close(t_data *cub);

int		move_mouse(int x, int y, t_data *cub);
int		release_mouse(int keycode, int x, int y, t_data *cub);
int		press_mouse(int keycode, int x, int y, t_data *cub);

int		open_door(t_data *cub);
int		init_walls(t_data *cub);

typedef	int	(*t_init_wall)(t_data *cub);

#endif