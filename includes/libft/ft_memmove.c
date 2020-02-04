/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:43:07 by icanker           #+#    #+#             */
/*   Updated: 2019/09/25 18:46:12 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char *source;

	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	if (dest == NULL && source == NULL)
		return (NULL);
	if (dest <= source)
		ft_memcpy(dest, source, len);
	else
	{
		dest += len;
		source += len;
		while (len--)
			*(--dest) = *(--source);
	}
	return (dest);
}
