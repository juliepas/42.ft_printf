/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 18:14:13 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/10 18:14:15 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char						*ft_itoabasexlong(unsigned long long int n,
	int base)
{
	char					*str;
	long long int			i;
	unsigned long long int	nb;

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
			str[i] = ((nb % base) - 10) + 'A';
		nb = nb / base;
		i--;
	}
	return (str);
}

char						*ft_itoa_basex(unsigned int n, int base)
{
	char					*str;
	int						i;
	long int				nb;

	nb = n;
	i = ft_nbrlongue(nb, base);
	str = ft_memalloc(i);
	str[i] = '\0';
	i--;
	if (nb == 0 || nb == -0)
		str[i] = '0';
	while (nb > 0)
	{
		if (nb % base <= 9)
			str[i] = nb % base + '0';
		else
			str[i] = ((nb % base) - 10) + 'A';
		nb = nb / base;
		i--;
	}
	return (str);
}
