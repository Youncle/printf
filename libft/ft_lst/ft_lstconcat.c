/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstconcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarstoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:07:40 by vcarstoc          #+#    #+#             */
/*   Updated: 2018/03/02 14:07:43 by vcarstoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstconcat(t_list *lnk_first_list, t_list *head_second_list)
{
	if (lnk_first_list && head_second_list)
	{
		while (lnk_first_list->next)
			lnk_first_list = lnk_first_list->next;
		lnk_first_list->next = head_second_list;
	}
}
