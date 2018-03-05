/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarstoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:17:35 by vcarstoc          #+#    #+#             */
/*   Updated: 2018/03/02 14:17:42 by vcarstoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int		x;
	int		i;

	i = 0;
	x = 1;
	while (i <= (nb / 2))
	{
		if (x * x == nb)
			return (x);
		x = (x + nb / x) / 2;
		i++;
	}
	return (0);
}
