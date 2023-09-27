/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:01:00 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/27 11:13:57 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAY_H
# define PLAY_H

int		press_key(int keycode, t_game *g);
int		release_key(int keycode, t_game *g);
void	move_forward(t_game *g);
void	move_backward(t_game *g);
void	move_left(t_game *g);
void	move_right(t_game *g);
void	rotate_left(t_game *g);
void	rotate_right(t_game *g);
void	play(t_game *g);

#endif