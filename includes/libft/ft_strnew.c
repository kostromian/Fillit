/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:23:42 by icanker           #+#    #+#             */
/*   Updated: 2019/09/25 20:25:01 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *s;

	if (size + 1 == 0)
		return (NULL);
	s = (char*)malloc(sizeof(char) * size + 1);
	if (!s)
		return (NULL);
	ft_memset(s, '\0', size + 1);
	return (s);
}
