/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:39:45 by icanker           #+#    #+#             */
/*   Updated: 2019/09/25 19:41:47 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int len_h;
	int len_n;

	len_h = ft_strlen(haystack);
	len_n = ft_strlen(needle);
	if (!len_n)
		return (char *)haystack;
	while (len_h >= len_n)
	{
		if (!ft_memcmp(haystack, needle, len_n))
			return (char *)haystack;
		haystack++;
		len_h--;
	}
	return (NULL);
}
