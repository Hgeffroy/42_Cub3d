/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:17:17 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/11/04 11:04:24 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_data	cub;

	if (ac != 2)
		return (ft_fdprintf(2, E_NARGS), 1);
	if (parsing(av[1], &cub))
		return (0);
//	print_parsing(&cub);
	play(&cub);
	return (0);
}
