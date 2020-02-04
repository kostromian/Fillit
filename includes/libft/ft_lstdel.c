/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:38:19 by icanker           #+#    #+#             */
/*   Updated: 2019/09/26 18:53:16 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*temp_list;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		temp_list = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = temp_list;
	}
	*alst = NULL;
	return ;
}
