/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:13:28 by icanker           #+#    #+#             */
/*   Updated: 2019/09/25 19:20:20 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*ret;
	size_t	size;

	size = ft_strlen(src);
	if (size > len)
		size = len;
	if (size != len)
		ft_memset(dst + size, '\0', len - size);
	ret = ft_memcpy(dst, src, size);
	return (ret);
}
