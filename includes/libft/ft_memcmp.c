/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:47:22 by icanker           #+#    #+#             */
/*   Updated: 2019/09/25 18:48:55 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *src1;
	unsigned char *src2;

	src1 = (unsigned char*)s1;
	src2 = (unsigned char*)s2;
	while (n--)
	{
		if (*src1 != *src2)
			return (*src1 - *src2);
		src1++;
		src2++;
	}
	return (0);
}
