/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:34:19 by icanker           #+#    #+#             */
/*   Updated: 2019/09/25 18:56:33 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *temp;

	temp = dst;
	if ((char*)dst == 0 && (char*)src == 0)
		return (NULL);
	while (n--)
		*((unsigned char*)dst++) = *((unsigned char*)src++);
	return (temp);
}
