/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 18:15:40 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/10 18:15:42 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_nbrlongue(long n, int base)
{
	int				i;

	i = 0;
	if (n == 0)
		i = 1;
	else if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

char				*ft_itoa_base(int n, int base)
{
	char			*str;
	int				i;
	long int		nb;

	nb = n;
	i = ft_nbrlongue(nb, base);
	str = ft_memalloc(i);
	if (nb < 0 && base == 10)
	{
		str[i - i] = '-';
		nb = -nb;
	}
	str[i] = '\0';
	if (nb == 0 || nb == -0)
		str[i - 1] = '0';
	while (nb > 0)
	{
		str[--i] = (nb % base <= 9) ?
		nb % base + '0' : ((nb % base) - 10) + 'a';
		nb = nb / base;
	}
	return (str);
}
