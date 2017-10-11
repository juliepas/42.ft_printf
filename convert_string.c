/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 18:13:34 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/10 18:13:35 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ii(t_conv *tmp, int lenarg)
{
	int			i;

	i = 0;
	if (tmp->precision > 0 && tmp->precision < lenarg)
		i = ft_strlen(tmp->data) - tmp->precision;
	else
		i = (tmp->precision == -1) ? tmp->precision :
			ft_strlen(tmp->data) - lenarg;
	return (i);
}

void			is_string(t_conv **tamp, char *argument)
{
	t_conv		*tmp;
	int			i;

	tmp = *tamp;
	i = 0;
	argument = (argument == NULL) ? "(null)" : argument;
	if (!(argument[i] == '\0' && tmp->attributs[4] == 1))
	{
		if (tmp->largeur != 0 && (tmp->largeur > tmp->precision
			|| tmp->largeur >= (int)ft_strlen(argument)))
		{
			longueur_de_champ(&tmp);
			if (tmp->attributs[2] == 0)
				i = ii(tmp, ft_strlen(argument));
		}
		else
			tmp->data = ft_memalloc(ft_strlen(argument) + 1);
		precision_str(&tmp, argument, i);
	}
}

char			*conversion_s(t_conv **tamp, wchar_t *argument)
{
	t_conv		*tmp;
	int			i;
	char		*str;
	char		*str2;

	str2 = NULL;
	tmp = *tamp;
	i = 0;
	if ((char*)argument == NULL)
	{
		str = ft_strdup("(null)");
		return (str);
	}
	else if (argument[i] == '\0')
		return (NULL);
	str2 = conversion_grand_c(&tmp, argument[i]);
	str = ft_strdup(str2);
	ft_strdel(&str2);
	while (argument[++i])
	{
		str2 = conversion_grand_c(&tmp, argument[i]);
		str = ft_strjoinfree(str, str2);
		ft_strdel(&str2);
	}
	return (str);
}

void			is_string_s(t_conv **tamp, wchar_t *argument)
{
	t_conv		*tmp;
	char		*str;
	int			i;

	tmp = *tamp;
	i = 0;
	str = conversion_s(&tmp, argument);
	if (str != NULL)
	{
		if (tmp->largeur > tmp->precision
			|| tmp->largeur >= (int)ft_strlen(str))
		{
			longueur_de_champ(&tmp);
			if (tmp->attributs[2] == 0)
				i = ii(tmp, ft_strlen(str));
		}
		else
			tmp->data = ft_memalloc(ft_strlen(str));
		precision_str(&tmp, str, i);
	}
	ft_strdel(&str);
}
