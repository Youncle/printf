/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wc_to_uni.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:53:22 by mienache          #+#    #+#             */
/*   Updated: 2018/01/14 19:28:24 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define B ((unsigned char*)&wide)

int			ft_wclen(wchar_t c)
{
	if (c <= (MB_CUR_MAX == 1 ? 0x00FF : 0x007F))
		return (1);
	if (c <= 0x07FF)
		return (2);
	if (c <= 0xFFFF)
		return (3);
	if (c <= 0x1FFFFF)
		return (4);
	return (0);
}

size_t		ft_wcblen(wchar_t *wstr)
{
	size_t		len;

	len = 0;
	while (*wstr != 0)
	{
		len += ft_wclen(*wstr);
		wstr++;
	}
	return (len);
}

void		ft_wctouni(wchar_t wide, char *tmp)
{
	if (wide <= (MB_CUR_MAX == 1 ? 0x00FF : 0x007F))
		tmp[0] = B[0];
	else if (wide <= 0x00FF)
	{
		tmp[1] = 128 | (63 & B[0]);
		tmp[0] = 192 | (B[0] >> 6);
	}
	else if (wide <= 0x07FF)
	{
		tmp[1] = 128 | (63 & B[0]);
		tmp[0] = 192 | (B[0] >> 6) | (B[1] << 2);
	}
	else if (wide <= 0xFFFF)
	{
		tmp[2] = 128 | (63 & B[0]);
		tmp[1] = 128 | (B[0] >> 6) | (B[1] << 2 & 63);
		tmp[0] = 224 | (B[1] >> 4);
	}
	else if (wide <= 0x1FFFFF)
	{
		tmp[3] = 128 | (63 & B[0]);
		tmp[2] = 128 | (B[0] >> 6) | (B[1] << 2 & 60);
		tmp[1] = 128 | (B[1] >> 4) | (B[2] << 4 & 48);
		tmp[0] = 240 | (B[2] >> 2);
	}
}

char		*ft_wstouni(wchar_t *wstr)
{
	char		*ustr;
	size_t		blen;
	size_t		i;

	blen = ft_wcblen(wstr);
	ustr = ft_strnew(blen);
	i = 0;
	while (i < blen)
	{
		ft_wctouni(*wstr, &ustr[i]);
		i += ft_wclen(*wstr);
		wstr++;
	}
	return (ustr);
}
