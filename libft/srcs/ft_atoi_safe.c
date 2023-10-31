/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:56:58 by xcharra           #+#    #+#             */
/*   Updated: 2023/08/29 15:11:32 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_safe(const char *nbr, int *result)
{
	int	i;
	int	m;
	int	nb;

	i = 0;
	m = 1;
	nb = 0;
	while (nbr[i] == 32 || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			m *= -1;
		i++;
	}
	while (nbr[i] && (nbr[i] >= '0' && nbr[i] <= '9'))
	{
		if (nb != ((nb * 10 + (m * (nbr[i] - 48))) / 10))
			return (-1);
		nb = nb * 10;
		nb = nb + (nbr[i] - '0') * m;
		i++;
	}
	*result = nb;
	return (0);
}
