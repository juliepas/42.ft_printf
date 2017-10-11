/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 18:15:12 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/10 18:15:13 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			rm(t_conv **tamp)
{
	t_conv *tmp;

	tmp = *tamp;
	while (tmp != NULL)
	{
		if (tmp->data)
			ft_strdel(&tmp->data);
		free(tmp);
		*tamp = NULL;
		tmp = tmp->next;
	}
	tmp = NULL;
}

int				finalstr(t_conv **tamp, char *format, int i)
{
	t_conv		*tmp;
	char		*finalstr;

	tmp = *tamp;
	while (tmp != NULL)
	{
		if (tmp->data != NULL && tmp->indicateur != 'c'
			&& tmp->indicateur != 'C')
			tmp->leng = ft_strlen(tmp->data);
		i += tmp->leng;
		tmp = tmp->next;
	}
	finalstr = ft_memalloc(i);
	tmp = *tamp;
	print_str(&finalstr, tamp, format, i);
	if (finalstr != NULL)
		ft_strdel(&finalstr);
	rm(tamp);
	return (i);
}

void			is_unsigned_int(t_conv **tamp, long long int argument)
{
	t_conv		*tmp;

	tmp = *tamp;
	if (tmp->indicateur == 'u' || tmp->indicateur == 'U')
		flag_u_u(&tmp, (unsigned long long int)argument);
	else if (tmp->indicateur == 'D' || tmp->indicateur == 'd'
		|| tmp->indicateur == 'i')
		flag_d_i(&tmp, argument);
	else if (tmp->indicateur == 'c')
		is_char(&tmp, (int)argument);
	else if (tmp->indicateur == 'o' || tmp->indicateur == 'O')
		flag_o_o(&tmp, (unsigned long long int)argument);
	else if (tmp->indicateur == 'x' || tmp->indicateur == 'X'
		|| tmp->indicateur == 'p')
		flag_x_x(&tmp, (unsigned long long int)argument);
}

void			is_str(t_conv **tamp, char *argument)
{
	t_conv		*tmp;

	tmp = *tamp;
	if (tmp->indicateur == 'S' || (tmp->indicateur == 's'
		&& tmp->longueur[2] == 1))
		is_string_s(&tmp, (wchar_t*)argument);
	else if (tmp->indicateur == 's')
		is_string(&tmp, argument);
}

int				ft_printf(const char *restrict format, ...)
{
	t_conv		*conversions;
	t_conv		*tmp;
	va_list		ap;
	int			i;

	conversions = NULL;
	i = parseur_printf((char*)format, &conversions);
	tmp = conversions;
	va_start(ap, format);
	while (tmp != NULL)
	{
		if (tmp->data == NULL)
		{
			if (tmp->indicateur == 'S' || tmp->indicateur == 's')
				is_str(&tmp, va_arg(ap, char*));
			else if (tmp->indicateur == 'C' || (tmp->indicateur == 'c'
				&& tmp->longueur[2] == 1))
				is_char_extended(&tmp, (wchar_t)va_arg(ap, wint_t));
			else
				is_unsigned_int(&tmp, va_arg(ap, long long int));
		}
		tmp = tmp->next;
	}
	va_end(ap);
	return (finalstr(&conversions, (char*)format, i));
}
