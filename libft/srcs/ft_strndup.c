/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:39:45 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/31 16:40:08 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, int n)
{
	char		*sdup;
	size_t		len;
	int			i;

	len = ft_strlen(s);
	sdup = (char *)malloc(sizeof(char) * (len + 1));
	if (!sdup)
		return (NULL);
	i = 0;
	while (s[i] && i < n)
	{
		sdup[i] = ((char *)s)[i];
		i++;
	}
	sdup[i] = '\0';
	return (sdup);
}