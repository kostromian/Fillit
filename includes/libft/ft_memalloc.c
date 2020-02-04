/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:21:04 by icanker           #+#    #+#             */
/*   Updated: 2019/09/25 20:36:08 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *m;

	m = (void*)malloc(size);
	if (m == NULL)
		return (NULL);
	ft_memset(m, 0, size);
	return (m);
}
