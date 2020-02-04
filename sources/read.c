/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorgana <tmorgana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 17:10:05 by icanker           #+#    #+#             */
/*   Updated: 2020/01/24 12:34:49 by tmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				check_map(char *buff)
{
	int			i;
	int			kol;

	kol = 0;
	i = 0;
	while (i != 20)
	{
		if ((i + 1) % 5 == 0)
		{
			if (buff[i] != '\n')
				return (0);
		}
		else
		{
			if (buff[i] != '#' && buff[i] != '.')
				return (0);
			if (buff[i] == '#')
				kol++;
		}
		i++;
	}
	return (kol == 4) ? 1 : 0;
}

t_figure		get_t_figure(char *buff)
{
	int			i;
	int			k;
	t_figure	fig;

	i = 0;
	k = 0;
	while (i != 20)
	{
		if (buff[i] == '#')
		{
			fig.coord[k][0] = i / 5;
			fig.coord[k][1] = (i + 1) % 5 - 1;
			k++;
		}
		i++;
	}
	return (fig);
}

t_figure		eqvil_t_figure(t_figure a, t_figure b)
{
	int			i;
	int			j;

	i = 0;
	while (i != 4)
	{
		j = 0;
		while (j != 2)
		{
			a.coord[i][j] = b.coord[i][j];
			j++;
		}
		i++;
	}
	return (a);
}

void			add(t_figure **figs, int size, t_figure fig)
{
	t_figure	**tmp;
	t_figure	*null_figs;
	int			i;

	tmp = figs;
	i = 0;
	null_figs = (t_figure *)malloc(sizeof(t_figure) * (size + 1));
	while (i != size)
	{
		null_figs[i] = (*figs)[i];
		i++;
	}
	null_figs[i] = eqvil_t_figure(null_figs[i], fig);
	if (size > 0)
		free(*figs);
	*figs = null_figs;
}

int				read_figs(char **av, int *size, t_figure **figs)
{
	int			fd;
	int			i;
	char		buff[21];
	int			nbr;

	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	while ((nbr = read(fd, buff, 21)))
	{
		if (nbr == 20)
			buff[20] = '\0';
		if (!check_map(buff) || *size > 24)
			return (0);
		add(figs, ++(*size), get_t_figure(buff));
		if (!check_figure(&(*figs)[*size]))
			return (0);
		i = 0;
		while (i != 20 && nbr == 21)
		{
			buff[i] = '\0';
			i++;
		}
	}
	close(fd);
	return (buff[20] == '\n' || (*size) < 0) ? 0 : 1;
}
