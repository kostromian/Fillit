/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:51:30 by icanker           #+#    #+#             */
/*   Updated: 2019/09/25 19:54:34 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MAX_INT 9223372036854775807

int		ft_atoi(const char *str)
{
	unsigned long long			s;
	int							n;

	s = 0;
	n = 1;
	str = ft_strscroll(str, ft_space);
	if (*str == '-')
		n = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		s = s * 10 + *str - '0';
		str++;
		if (s >= MAX_INT && n > 0)
			return (-1);
		if (s > MAX_INT && n < 0)
			return (0);
	}
	return (s * n);
}
