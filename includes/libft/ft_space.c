/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:41:10 by icanker           #+#    #+#             */
/*   Updated: 2019/09/26 19:41:30 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_space(int c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' ||
		c == '\v');
}