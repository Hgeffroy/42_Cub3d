/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 08:07:59 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/31 16:05:49 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

// A del
# include <stdio.h>

# include "mlx.h"
# include "libft.h"
# include "define.h"
# include "structs.h"
# include "enum.h"
# include "parsing.h"
# include "display.h"
# include "play.h"
# include "colors.h"

# ifndef IS_BONUS
#  define BONUS		0
#  define CHARSET	M_CHARSET
#  define FFCHARSET	"NSEW0"
# else
#  define BONUS		1
#  define CHARSET	B_CHARSET
#  define FFCHARSET	"NSEW0D"
# endif

#endif