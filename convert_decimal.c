/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_decimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 18:13:02 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/10 18:13:03 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*conversion_d_i(t_conv **tamp, long long int argument)
{
	t_conv		*tmp;
	char		*str2;

	tmp = *tamp;
	if (tmp->longueur[2] == 1 || tmp->longueur[3] == 1
		|| tmp->longueur[4] == 1 || tmp->longueur[5] == 1 ||
		tmp->indicateur == 'D')
		str2 = ft_itoabaselong(argument, 10);
	else if (tmp->longueur[1] == 1)
		str2 = ft_itoa_base((char)argument, 10);
	else if (tmp->longueur[0] == 1)
		str2 = ft_itoa_base((short)argument, 10);
	else
		str2 = ft_itoa_base(argument, 10);
	return (str2);
}

void			flag_d_i(t_conv **tamp, long long int argument)
{
	t_conv		*tmp;
	char		*str;
	int			i;

	tmp = *tamp;
	i = 0;
	str = conversion_d_i(&tmp, argument);
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
		tmp->data = ft_strnew(tmp->precision + 1);
	else
		tmp->data = (char*)malloc(sizeof(char) * (ft_strlen(str)));
	precision_int(&tmp, str, i);
	ft_strdel(&str);
}

char			*conversion_u_u(t_conv **tamp, unsigned long long int argument)
{
	t_conv		*tmp;
	char		*str2;

	tmp = *tamp;
	if (tmp->indicateur == 'U' || tmp->longueur[3] == 1
		|| tmp->longueur[2] == 1 || tmp->longueur[4] == 1
		|| tmp->longueur[5] == 1)
		str2 = ft_itoabaseunsigned(argument, 10);
	else if (tmp->longueur[1] == 1)
		str2 = ft_itoa_base((unsigned char)argument, 10);
	else if (tmp->longueur[0] == 1)
		str2 = ft_itoa_base((unsigned short)argument, 10);
	else if ((int)argument < 0)
		str2 = ft_itoabaselong((unsigned)argument, 10);
	else
		str2 = ft_itoa_base((unsigned)argument, 10);
	return (str2);
}

void			flag_u_u(t_conv **tamp, unsigned long long int argument)
{
	t_conv		*tmp;
	char		*str;
	int			i;
	int			j;

	tmp = *tamp;
	i = 0;
	j = -1;
	str = conversion_u_u(&tmp, argument);
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
		tmp->data = ft_strnew(tmp->precision + 1);
	else
		tmp->data = ft_memalloc(ft_strlen(str));
	precision_int(&tmp, str, i);
	ft_strdel(&str);
}
