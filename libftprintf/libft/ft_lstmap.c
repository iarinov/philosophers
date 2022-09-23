/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:41:16 by aiarinov          #+#    #+#             */
/*   Updated: 2022/04/17 10:30:52 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst1;
	t_list	*new;

	lst1 = (void *)0;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&lst1, del);
			return (lst1);
		}
		ft_lstadd_back(&lst1, new);
		lst = lst->next;
	}
	return (lst1);
}
