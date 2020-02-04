/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:29:16 by icanker           #+#    #+#             */
/*   Updated: 2019/09/25 19:30:32 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	int				len;

	ch = (unsigned char)c;
	len = ft_strlen(s);
	s += len;
	if (ch == '\0')
		return ((char*)s);
	while (len + 1)
	{
		if ((unsigned char)*s == ch)
			return ((char*)s);
		s--;
		len--;
	}
	return (0);
}
