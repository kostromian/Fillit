/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:19:55 by icanker           #+#    #+#             */
/*   Updated: 2020/01/24 16:22:39 by tmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	t_map		map;
	t_figure	*figs;
	int			size;

	size = -1;
	if (ac != 2)
	{
		ft_putstr("usage: \"./fillit input_file\"\n");
		return (1);
	}
	if (!read_figs(av, &size, &figs))
	{
		ft_putstr("error\n");
		return (1);
	}
	map.size = 1;
	inc_map(&map);
	solve(&figs, &map, ++size);
	print_map(&map);
	free(figs);
	return (0);
}
