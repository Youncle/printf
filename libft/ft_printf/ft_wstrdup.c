/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_w_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:52:13 by mienache          #+#    #+#             */
/*   Updated: 2018/01/14 19:28:47 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_wstrlen(const wchar_t *s)
{
	int		i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

wchar_t		*ft_wstrnew(size_t size)
{
	wchar_t		*m;

	m = (wchar_t*)ft_memalloc(sizeof(wchar_t) * (size + 1));
	return (m);
}

wchar_t		*ft_wstrjoin(wchar_t const *s1, wchar_t const *s2)
{
	wchar_t		*s;
	size_t		n;

	n = (int)(ft_wstrlen(s1) + ft_wstrlen(s2));
	s = ft_wstrnew(n);
	if (!s)
		return (s);
	ft_wstrcpy(s, s1);
	ft_wstrcat(s, s2);
	return (s);
}

wchar_t		*ft_wstrjoinreplace(wchar_t const *s1, wchar_t const *s2)
{
	wchar_t		*s;
	size_t		n;

	n = (int)(ft_wstrlen(s1) + ft_wstrlen(s2));
	s = ft_wstrnew(n);
	if (!s)
		return (s);
	ft_wstrcpy(s, s1);
	ft_wstrcat(s, s2);
	ft_memdel((void**)&s1);
	return (s);
}

wchar_t		*ft_wstrdup(const wchar_t *s1)
{
	wchar_t		*s;
	int			i;

	s = ft_wstrnew(ft_wstrlen(s1));
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
