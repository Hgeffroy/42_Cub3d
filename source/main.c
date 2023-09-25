/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:17:17 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/25 13:18:00 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	*g;
	
	if (ac != 2)
		return (ft_dprintf(2, "This program should be ran with one argument.\n"));
	g = parsing(av[1]);
	print_parsing(g);
	return (0);
}