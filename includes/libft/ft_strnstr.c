/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:43:00 by icanker           #+#    #+#             */
/*   Updated: 2019/09/25 19:45:28 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_n;

	len_n = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len-- >= len_n)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, len_n) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
