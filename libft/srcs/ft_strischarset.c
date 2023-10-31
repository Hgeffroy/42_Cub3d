/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strischarset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:00:52 by xcharra           #+#    #+#             */
/*   Updated: 2023/10/23 13:34:34 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strischarset(char *str, char *charset)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_ischarset(str[i], charset))
			i++;
		else
			return (0);
	}
	return (1);
}
