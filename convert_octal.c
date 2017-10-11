/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 18:13:21 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/10 18:13:23 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*conversion_o_o(t_conv **tamp, unsigned long long int argument)
{
	t_conv		*tmp;
	char		*str2;

	tmp = *tamp;
	if (tmp->indicateur == 'O' || tmp->longueur[3] == 1
		|| tmp->longueur[2] == 1 || tmp->longueur[4] == 1
		|| tmp->longueur[5] == 1)
		str2 = ft_itoabaseunsigned(argument, 8);
	else if (tmp->longueur[1] == 1)
		str2 = ft_itoa_base((unsigned char)argument, 8);
	else if (tmp->longueur[0] == 1)
		str2 = ft_itoa_base((unsigned short)argument, 8);
	else if ((int)argument < 0)
		str2 = ft_itoabaselong((unsigned)argument, 8);
	else
		str2 = ft_itoa_base((unsigned)argument, 8);
	return (str2);
}

void			flag_o_o(t_conv **tamp, unsigned long long int argument)
{
	t_conv		*tmp;
	char		*str;
	int			i;
	int			j;

	tmp = *tamp;
	i = 0;
	j = -1;
	str = conversion_o_o(&tmp, argument);
	if (tmp->largeur != 0 && tmp->largeur > tmp->precision
		&& tmp->largeur > (int)ft_strlen(str))
	{
		longueur_de_champ(&tmp);
		if (tmp->attributs[2] == 0)
			i = (tmp->precision > (int)ft_strlen(str)) ?
			ft_strlen(tmp->data) - tmp->precision :
			ft_strlen(tmp->data) - ft_strlen(str);
	}
	else if (tmp->precision > (int)ft_strlen(str))
		tmp->data = ft_strnew(tmp->precision);
	else
		tmp->data = ft_memalloc(ft_strlen(str));
	precision_int(&tmp, str, i);
	ft_strdel(&str);
}
