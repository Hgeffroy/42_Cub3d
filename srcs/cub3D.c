/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:17:17 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/31 16:42:04 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

int	main(int ac, char **av)
{
	t_data	cub;
//	t_game	*g;
	
	if (ac != 2)
		return (ft_fdprintf(2, "This program should be ran with one argument.\n"));
	if (parsing(av[1], &cub))
		return (0);
	play(&cub);
	return (0);
}