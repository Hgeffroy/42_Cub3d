/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:39:32 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/26 07:58:45 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	tab_len(char **tab)
{
	int	len;

	if (!tab)
		return (0);
	len = 0;
	while (tab[len])
		len++;
	return (len);
}
