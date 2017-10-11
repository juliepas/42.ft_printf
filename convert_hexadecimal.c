/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hexadecimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 18:13:12 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/10 18:13:14 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*conversion_x_x(t_conv **tamp, unsigned long long int argument)
{
	t_conv		*tmp;
	char		*str2;

	tmp = *tamp;
	if (tmp->longueur[2] == 1 || tmp->longueur[3] == 1
		|| tmp->longueur[4] == 1 || tmp->longueur[5] == 1
		|| tmp->indicateur == 'p')
		str2 = (tmp->indicateur == 'x' || tmp->indicateur == 'p') ?
			ft_itoabaseunsigned(argument, 16) :
			ft_itoabasexlong(argument, 16);
	else if (tmp->longueur[1] == 1)
		str2 = (tmp->indicateur == 'x') ?
			ft_itoa_base((unsigned char)argument, 16) :
			ft_itoa_basex((unsigned char)argument, 16);
	else
		str2 = (tmp->indicateur == 'x') ?
			ft_itoabaseunsigned((unsigned int)argument, 16) :
			ft_itoa_basex((unsigned int)argument, 16);
	return (str2);
}

int				flag_x_x_bis(t_conv **tamp, char *str, int i)
{
	t_conv		*tmp;

	tmp = *tamp;
	if ((tmp->largeur < tmp->precision) &&
		(tmp->precision > (int)ft_strlen(str)))
	{
		if (tmp->indicateur == 'p' ||
			(tmp->attributs[0] == 1 && ft_strcmp(str, "0") != 0))
			i += 2;
		tmp->data = ft_strnew(tmp->precision + i);
	}
	else
	{
		if (tmp->indicateur == 'p' ||
			(tmp->attributs[0] == 1 && ft_strcmp(str, "0") != 0))
			i += 2;
		tmp->data = ft_strnew(ft_strlen(str) + 1 + i);
	}
	return (i);
}

void			flag_x_x(t_conv **tamp, unsigned long long int argument)
{
	t_conv		*tmp;
	char		*str;
	int			i;

	tmp = *tamp;
	i = 0;
	str = conversion_x_x(&tmp, argument);
	if (tmp->largeur != 0 && tmp->largeur > tmp->precision
		&& tmp->largeur > (int)ft_strlen(str))
	{
		longueur_de_champ(&tmp);
		if (tmp->attributs[2] == 0)
			i = (tmp->precision > (int)ft_strlen(str)) ?
			ft_strlen(tmp->data) - tmp->precision :
			ft_strlen(tmp->data) - ft_strlen(str);
		else if (tmp->attributs[0] == 1 || tmp->indicateur == 'p')
			i += 2;
	}
	else
		i = flag_x_x_bis(&tmp, str, i);
	if (tmp->precision != -1 || tmp->indicateur == 'p')
		precision_int(&tmp, str, i);
	ft_strdel(&str);
}
