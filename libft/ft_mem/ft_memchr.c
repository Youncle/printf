/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarstoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:11:48 by vcarstoc          #+#    #+#             */
/*   Updated: 2018/03/02 14:11:51 by vcarstoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*x;
	void			*y;

	x = (unsigned char *)src;
	y = (void *)src;
	i = 0;
	while (i < n)
	{
		if (x[i] == (unsigned char)c)
			return (y + i);
		i++;
	}
	return (NULL);
}
