/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:21:37 by icanker           #+#    #+#             */
/*   Updated: 2020/01/24 15:42:49 by tmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			map_check(t_figure fig, int x, int y, t_map *map)
{
	int i;

	i = 0;
	while (4 > i)
	{
		if ((*map).size < y + fig.coord[i][0] - fig.coord[0][0] + 1
			|| (*map).size < x + fig.coord[i][1] - fig.coord[0][1] + 1)
			return (0);
		if (x + fig.coord[i][1] - fig.coord[0][1] < 0)
			return (0);
		if ((*map).c_map[y + fig.coord[i][0] - fig.coord[0][0]]
			[x + fig.coord[i][1] - fig.coord[0][1]] != '.')
			return (0);
		i++;
	}
	return (1);
}

int			insert(t_figure fig, char c, int *crd, t_map *map)
{
	int k;

	k = 0;
	if (map_check(fig, crd[0], crd[1], map))
	{
		while (k != 4)
		{
			(*map).c_map[crd[1] + fig.coord[k][0] - fig.coord[0][0]]
				[crd[0] + fig.coord[k][1] - fig.coord[0][1]] = c;
			k++;
		}
		return (1);
	}
	return (0);
}

void		remove_fig(t_figure fig, int x, int y, t_map *map)
{
	int k;

	k = 0;
	while (k != 4)
	{
		(*map).c_map[y + fig.coord[k][0] - fig.coord[0][0]]
			[x + fig.coord[k][1] - fig.coord[0][1]] = '.';
		k++;
	}
}

int			**innit_coord(int size)
{
	int **cords;
	int i;

	cords = (int **)malloc(size * sizeof(int *));
	i = 0;
	while (i != size)
	{
		cords[i] = (int *)malloc(2 * sizeof(int));
		cords[i][0] = 0;
		cords[i][1] = 0;
		i++;
	}
	return (cords);
}

void		increase(int *x, int *y, int size)
{
	(*x)++;
	if (*x == size)
	{
		*x = 0;
		(*y)++;
	}
}
