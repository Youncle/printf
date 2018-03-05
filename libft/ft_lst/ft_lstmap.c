/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarstoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:09:39 by vcarstoc          #+#    #+#             */
/*   Updated: 2018/03/02 14:09:41 by vcarstoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*ret_last;

	if (!lst)
		return (NULL);
	if (!(ret_last = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	ret_last = f(lst);
	ret = ret_last;
	while (lst->next)
	{
		ret->next = f(lst->next);
		ret = ret->next;
		lst = lst->next;
	}
	return (ret_last);
}
