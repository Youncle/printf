/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 19:03:38 by mienache          #+#    #+#             */
/*   Updated: 2018/01/14 19:32:53 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_strlenlocal(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

char				*ft_strdup(const char *s1)
{
	char	*s;
	size_t	i;

	s = ft_strnew(ft_strlenlocal(s1));
	if (!s)
		return (NULL);
	if (s1)
	{
		i = 0;
		while (s1[i])
		{
			s[i] = s1[i];
			i++;
		}
	}
	return (s);
}
