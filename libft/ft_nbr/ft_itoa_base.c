/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarstoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:16:11 by vcarstoc          #+#    #+#             */
/*   Updated: 2018/03/02 14:16:14 by vcarstoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_length(unsigned long n, int b)
{
	int		i;

	i = 0;
	if (!n)
		i = 1;
	while (n)
	{
		n /= b;
		i++;
	}
	return (i);
}

static void		ft_digits(char *a, unsigned long num, int len, unsigned int b)
{
	char	c;

	if (!num)
		a[--len] = 48;
	while (len > 0)
	{
		c = num % b;
		if (c < 10)
			a[--len] = (c + 48);
		else
			a[--len] = (c + 55);
		num /= b;
	}
}

char			*ft_itoa_base(unsigned long n, unsigned int b)
{
	int				len;
	unsigned long	num;
	char			*a;

	if (b <= 1)
		return (NULL);
	num = n;
	len = ft_length(num, b);
	a = ft_strnew(len);
	if (!a)
		return (a);
	ft_digits(a, num, len, b);
	return (a);
}
