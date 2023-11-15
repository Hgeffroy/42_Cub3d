/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:17:17 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/09 12:19:56 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_data	cub;

	if (ac != 2)
		return (ft_fdprintf(2, E_NARGS), 1);
	if (parsing(av[1], &cub))
		return (1);
	if (play(&cub) < 0)
	{
		cub.exit_code = 1;
		return (mlx_close(&cub), 1);
	}
	return (0);
}
