/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_spe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 18:14:07 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/10 18:14:08 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long int				ft_nbrlonglong(long long int n, int base)
{
	long long int		i;

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

char					*ft_itoabaselong(long long int n, int base)
{
	char				*str;
	long long int		i;
	long long int		nb;

	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	nb = n;
	i = ft_nbrlonglong(nb, base);
	str = ft_memalloc(i);
	if (nb < 0 && base == 10)
	{
		str[0] = '-';
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

int						ft_nbrunsigned(unsigned long long int n, int base)
{
	int					i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

char					*ft_itoabaseunsigned(unsigned long long n, int base)
{
	char				*str;
	int					i;
	unsigned long long	nb;

	nb = n;
	i = ft_nbrunsigned(nb, base);
	str = ft_memalloc(i + 1);
	str[i] = '\0';
	i--;
	if (nb == 0 || nb == -0)
		str[i] = '0';
	while (nb > 0)
	{
		if (nb % base <= 9)
			str[i] = nb % base + '0';
		else
			str[i] = ((nb % base) - 10) + 'a';
		nb = nb / base;
		i--;
	}
	return (str);
}
