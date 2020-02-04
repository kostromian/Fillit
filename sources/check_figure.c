/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_figure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:50:09 by icanker           #+#    #+#             */
/*   Updated: 2020/01/22 18:50:14 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			help_check_figure(int **t)
{
	int i;
	int boool;

	i = 0;
	boool = 0;
	while (i != 4)
	{
		if ((*t)[i] == 0)
			return (0);
		if ((*t)[i] >= 2)
			boool = 1;
		i++;
	}
	free(*t);
	return (boool);
}

int			check_figure(t_figure *fig)
{
	int		i;
	int		j;
	int		*t;

	t = (int *)malloc(4 * sizeof(int));
	i = 0;
	while (i != 4)
	{
		t[i] = 0;
		j = 0;
		while (j != 4)
		{
			if (fig->coord[i][0] == fig->coord[j][0] &&
				(fig->coord[i][1] - fig->coord[j][1] == 1 ||
				fig->coord[i][1] - fig->coord[j][1] == -1))
				t[i]++;
			if (fig->coord[i][1] == fig->coord[j][1]
				&& (fig->coord[i][0] - fig->coord[j][0] == 1 ||
				fig->coord[i][0] - fig->coord[j][0] == -1))
				t[i]++;
			j++;
		}
		i++;
	}
	return (help_check_figure(&t));
}
