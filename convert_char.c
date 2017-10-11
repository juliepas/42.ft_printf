/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 18:12:55 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/10 18:12:57 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			is_char(t_conv **tamp, int argument)
{
	t_conv		*tmp;
	int			i;

	tmp = *tamp;
	i = 0;
	if (tmp->largeur != 0 && tmp->largeur > tmp->precision)
	{
		longueur_de_champ(&tmp);
		if (tmp->attributs[2] == 0)
			i = ft_strlen(tmp->data) - 1;
	}
	else
		tmp->data = ft_strnew(1);
	tmp->data[i] = argument;
	tmp->leng = ft_strlen(tmp->data);
	if (argument == 0)
		tmp->leng += 1;
}

int				longueur_wchart(int len)
{
	int			i;

	i = 0;
	if (len % 6 == 0)
		i = len / 6;
	else
		i = len / 6 + 1;
	return (i);
}

char			*conversion_grand_c(t_conv **tamp, wchar_t argument)
{
	t_conv		*tmp;
	int			len;
	int			i;
	char		*str;

	tmp = *tamp;
	len = ft_nbrlongue(argument, 2);
	i = longueur_wchart(len);
	str = ft_memalloc(i);
	str[i] = '\0';
	if (len > 7)
	{
		while (--i > 0)
		{
			str[i] = (argument & 0x3F);
			str[i] += 0x80;
			argument = argument >> 6;
		}
		i = longueur_wchart(len);
		str[0] = (0xF0 << (4 - i)) | argument;
	}
	else
		str[0] = (char)argument;
	tmp->leng += ft_strlen(str);
	return (str);
}

void			is_char_extended(t_conv **tamp, wchar_t argument)
{
	t_conv		*tmp;
	char		*str;
	int			i;

	tmp = *tamp;
	i = 0;
	str = conversion_grand_c(&tmp, argument);
	if (str != NULL)
	{
		if (tmp->largeur != 0 && tmp->largeur > tmp->precision
			&& tmp->largeur > (int)ft_strlen(str))
		{
			longueur_de_champ(&tmp);
			if (tmp->attributs[2] == 0)
				i = ft_strlen(tmp->data) - ft_strlen(str);
		}
		else
			tmp->data = ft_memalloc(ft_strlen(str));
		precision_str(&tmp, str, i);
	}
	tmp->leng = ft_strlen(tmp->data);
	if (argument == 0)
		tmp->leng += 1;
	ft_strdel(&str);
}
