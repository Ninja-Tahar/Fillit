/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 21:31:04 by mbenkara          #+#    #+#             */
/*   Updated: 2017/12/10 14:38:23 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*first;

	first = NULL;
	new = f(lst);
	first = new;
	while (lst->next != NULL)
	{
		new->next = f(lst->next);
		new = new->next;
		lst = lst->next;
	}
	return (first);
}
