/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarstoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:12:57 by vcarstoc          #+#    #+#             */
/*   Updated: 2018/03/02 14:13:00 by vcarstoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*m;
	unsigned char	*old;

	m = (unsigned char*)dst;
	old = (unsigned char*)src;
	if (src > dst)
	{
		while (len-- > 0)
			*m++ = *old++;
	}
	else
	{
		m += len;
		old += len;
		while (len-- > 0)
			*--m = *--old;
	}
	return (dst);
}
