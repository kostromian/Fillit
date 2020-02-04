/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorgana <tmorgana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:03:32 by icanker           #+#    #+#             */
/*   Updated: 2020/01/20 20:09:59 by tmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>

typedef struct	s_map
{
	int		size;
	char	**c_map;
}				t_map;

typedef struct	s_figure
{
	int	coord[4][2];
}				t_figure;

void			free_map(t_map *map);
int				help_check_figure(int **t);
int				check_map(char *buff);
t_figure		get_t_figure(char *buff);
t_figure		eqvil_t_figure(t_figure a, t_figure b);
int				check_figure(t_figure *fig);
void			add(t_figure **figs, int size, t_figure fig);
int				read_figs(char **av, int *size, t_figure **figs);
void			inc_map(t_map *map);
void			solve_0(t_figure **figs, t_map *map, int *i, int ***coords);
void			solve(t_figure **figs, t_map *map, int size);
int				map_check(t_figure fig, int x, int y, t_map *map);
int				insert(t_figure fig, char c, int *crd, t_map *map);
void			remove_fig(t_figure fig, int x, int y, t_map *map);
int				**innit_coord(int size);
void			increase(int *x, int *y, int size);
void			print_map(t_map *map);

#endif
