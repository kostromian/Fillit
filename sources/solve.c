/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:21:26 by icanker           #+#    #+#             */
/*   Updated: 2020/01/24 15:49:41 by tmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_map(t_map *map)
{
	int i;

	i = 0;
	while (i != (*map).size)
	{
		ft_putstr((*map).c_map[i]);
		i++;
	}
	free_map(map);
}

void		free_map(t_map *map)
{
	int i;

	i = 0;
	while (map->c_map[i] != NULL)
	{
		free(map->c_map[i]);
		i++;
	}
	free(map->c_map);
}

void		inc_map(t_map *map)
{
	int		i;
	int		j;
	t_map	n_map;

	n_map.size = (map->size + 1);
	if (map->size > 1)
		free_map(map);
	n_map.c_map = (char **)malloc((n_map.size + 1) * sizeof(char *));
	i = 0;
	while (i < n_map.size)
	{
		n_map.c_map[i] = (char *)malloc((n_map.size + 2) * sizeof(char));
		j = 0;
		while (j < n_map.size)
		{
			n_map.c_map[i][j] = '.';
			j++;
		}
		n_map.c_map[i][j] = '\n';
		n_map.c_map[i][j + 1] = '\0';
		i++;
	}
	n_map.c_map[i] = NULL;
	*map = n_map;
}

void		solve_0(t_figure **figs, t_map *map, int *i, int ***coords)
{
	if (*i == 0)
	{
		(*coords)[*i][0] = 0;
		(*coords)[*i][1] = 0;
		inc_map(map);
	}
	else
	{
		(*coords)[*i][0] = 0;
		(*coords)[*i][1] = 0;
		(*i)--;
		remove_fig((*figs)[*i], (*coords)[*i][0], (*coords)[*i][1], map);
		increase(&((*coords)[*i][0]), &((*coords)[*i][1]), (*map).size);
	}
}

void		solve(t_figure **figs, t_map *map, int size)
{
	int i;
	int **coords;

	coords = innit_coord(size);
	i = 0;
	while (i != size)
	{
		while (!insert((*figs)[i], 'A' + i, coords[i], map))
		{
			increase(&(coords[i][0]), &(coords[i][1]), (*map).size);
			if (coords[i][1] == (*map).size)
				solve_0(figs, map, &i, &coords);
		}
		i++;
	}
	i = 0;
	while (i != size)
	{
		free(coords[i]);
		i++;
	}
	free(coords);
}
