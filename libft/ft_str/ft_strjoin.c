/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:46:43 by mienache          #+#    #+#             */
/*   Updated: 2018/01/14 19:29:24 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	n;

	n = (int)(ft_strlen(s1) + ft_strlen(s2));
	s = ft_strnew(n);
	if (!s)
		return (s);
	ft_strcpy(s, s1);
	ft_strcat(s, s2);
	return (s);
}
