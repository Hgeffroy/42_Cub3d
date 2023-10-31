/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:50:28 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/23 14:55:15 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

enum e_keycode
{
	a_key		=	97,
	b_key		=	98,
	c_key		=	99,
	d_key		=	100,
	s_key		=	115,
	f_key		=	102,
	g_key		=	103,
	h_key		=	104,
	z_key		=	122,
	x_key		=	120,
	v_key		=	118,
	q_key		=	113,
	w_key		=	119,
	e_key		=	101,
	r_key		=	114,
	y_key		=	121,
	t_key		=	116,
	one_key		=	49,
	two_key		=	50,
	three_key	=	51,
	four_key	=	52,
	six_key		=	54,
	five_key	=	53,
	equal_key	=	61,
	nine_key	=	57,
	seven_key	=	55,
	minus_key	=	45,
	eight_key	=	56,
	zero_key	=	48,
	cbracket_key=	93,
	o_key		=	111,
	u_key		=	117,
	obracket_key=	91,
	i_key		=	105,
	p_key		=	112,
	enter_key	=	65293,
	l_key		=	108,
	j_key		=	106,
	quote_key	=	39,
	k_key		=	107,
	semico_key	=	59,
	pipe_key	=	92,
	comma_key	=	44,
	slash_key	=	47,
	n_key		=	110,
	m_key		=	109,
	dot_key		=	46,
	tab_key		=	65289,
	space_key	=	32,
	tilde_key	=	96,
	del_key		=	65288,
	esc_key		=	65307,
	left_key	=	65361,
	right_key	=	65363,
	down_key	=	65364,
	up_key		=	65362,
	ctrl_l_key	=	65507,
	ctrl_r_key	=	65508,
	maj_l_key	=	65505,
	maj_r_key	=	65506,
	alt_l_key	=	65513,
	alt_r_key	=	65514,
	majlock_key	=	65509
};

enum	e_mousecode
{
	m_left_key		= 1,
	scroll_key		= 2,
	m_right_key		= 3,
	m_down_key		= 4,
	m_up_key		= 5
};

enum	e_yesno
{
	YES,
	NO
};

enum	e_map
{
	FTILE,
	WALL,
	OPEN
};

enum	e_wall
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	DOOR
};

enum	e_error
{
	NOPLAYER	= 1,
	NBTEXT		= 2
};

#endif