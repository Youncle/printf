/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarstoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:11:15 by vcarstoc          #+#    #+#             */
/*   Updated: 2018/03/02 14:11:18 by vcarstoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*m;
	void	*tmp;

	m = (void *)malloc(size);
	if (!m)
		return (NULL);
	tmp = m;
	while (size-- > 0)
		*(unsigned char*)tmp++ = 0;
	return (m);
}
