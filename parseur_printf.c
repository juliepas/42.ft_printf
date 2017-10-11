/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 18:14:22 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/10 18:14:24 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			create_maillon(t_conv **conversions, char *arg)
{
	t_conv		*tmp;
	t_conv		*new;
	int			i;
	int			j;

	j = -1;
	tmp = *conversions;
	new = ft_memalloc(sizeof(t_conv));
	i = add_attributs(&new, arg);
	i = add_largeur_precision(&new, arg, i);
	i = add_longueur(&new, arg, i);
	i = add_indicateur(&new, arg, i);
	if (i == 1)
	{
		new->leng = 0;
		new->next = NULL;
		if (*conversions == NULL)
			*conversions = new;
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}

int				trim_argument(char *format, char **arg, int i)
{
	char		*str;
	int			j;
	int			k;

	j = i;
	k = -1;
	str = "%sSpdDioOuUxXcC";
	while (format[++j])
	{
		while (str[++k])
			if (format[j] == str[k] || (ft_isalpha(format[j]) == 1
				&& format[j] != 'h' && format[j] != 'l' && format[j] != 'j'
				&& format[j] != 'z'))
				break ;
		*arg = ft_strjoinchar(*arg, format[j]);
		if (str[k])
			return (j);
		k = -1;
	}
	if (format[j] != str[k] && ft_isalpha(format[j]) == 0)
		*arg = NULL;
	else
		i += 1;
	return (i);
}

int				parseur_printf(char *format, t_conv **conversions)
{
	int			i;
	int			j;
	int			k;
	char		*arg;

	i = -1;
	j = 0;
	k = 0;
	while (format[++i] != '\0')
	{
		arg = NULL;
		if (format[i] == '%' && format[i + 1])
		{
			i = trim_argument(format, &arg, i);
			create_maillon(conversions, arg);
			if (arg != NULL)
				ft_strdel(&arg);
			if (*conversions == NULL)
				while (format[i - 1] != '%')
					i--;
		}
		else if (format[i] != '%')
			j++;
	}
	return (j);
}
