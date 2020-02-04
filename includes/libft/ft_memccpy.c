/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:32:11 by icanker           #+#    #+#             */
/*   Updated: 2019/09/25 18:34:13 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*temp_d;
	const unsigned char *temp_s;

	temp_d = dst;
	temp_s = src;
	while (n--)
	{
		if ((*temp_d++ = *temp_s++) == (unsigned char)c)
			return (temp_d);
	}
	return (NULL);
}
