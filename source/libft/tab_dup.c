/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 07:50:10 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/26 07:58:49 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**tab_dup(char **tab)
{
	char	**res;
	int		i;
	
	if (!tab)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (tab_len(tab) + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (tab[++i])
	{
		res[i] = ft_strdup(tab[i]);
		if (!res[i])
		{
			free_tab(res);
			return (NULL);
		}
	}
	res[i] = NULL;
	return (res);
}
