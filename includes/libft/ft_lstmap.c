/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:50:17 by icanker           #+#    #+#             */
/*   Updated: 2019/09/26 19:10:15 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *res;

	if (lst != NULL)
	{
		res = (t_list*)malloc(sizeof(f(lst)));
		if (res == NULL)
			return (NULL);
		res = f(lst);
		res->next = ft_lstmap(lst->next, f);
		return (res);
	}
	return (NULL);
}
