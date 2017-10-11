/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 18:11:56 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/10 18:11:59 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				add_indicateur(t_conv **new, char *arg, int i)
{
	int			j;
	int			k;
	char		*str;
	t_conv		*tmp;

	tmp = *new;
	k = 0;
	str = "%sSpdDioOuUxXcC";
	j = ft_strlen(arg);
	tmp->data = NULL;
	if ((j - 1) == i && arg[i] != '\0')
		tmp->indicateur = arg[j - 1];
	else
		return (0);
	while (str[++k])
		if (arg[j - 1] == str[k])
			break ;
	if (arg[j - 1] != str[k])
		is_char(&tmp, arg[j - 1]);
	return (1);
}

int				add_attributs(t_conv **new, char *arg)
{
	int			i;
	char		*str;
	int			j;
	t_conv		*tmp;

	tmp = *new;
	i = -1;
	j = -1;
	str = "#0-+ ";
	while (tmp->attributs[++j])
		tmp->attributs[j] = 0;
	while (arg[++i] == '#' || arg[i] == '0' || arg[i] == '-'
		|| arg[i] == '+' || arg[i] == ' ')
	{
		j = -1;
		while (str[++j])
		{
			if (arg[i] == str[j])
			{
				tmp->attributs[j] = 1;
				break ;
			}
		}
	}
	return (i);
}

int				add_longueur(t_conv **new, char *arg, int i)
{
	char		*str;
	int			j;
	t_conv		*tmp;

	tmp = *new;
	j = -1;
	str = "hwlqjz";
	while (tmp->longueur[++j])
		tmp->longueur[j] = 0;
	j = -1;
	while (str[++j])
		if (arg[i] == str[j])
		{
			if (arg[i + 1] == str[j])
			{
				tmp->longueur[j + 1] = 1;
				i += 1;
			}
			else
				tmp->longueur[j] = 1;
			break ;
		}
	if (j <= 5)
		i++;
	return (i);
}

int				add_largeur_precision(t_conv **new, char *arg, int i)
{
	char		*str;
	t_conv		*tmp;

	tmp = *new;
	str = NULL;
	if (arg[i] >= 48 && arg[i] <= 57)
	{
		while (arg[i] >= 48 && arg[i] <= 57)
		{
			str = ft_strjoinchar(str, arg[i]);
			i++;
		}
		tmp->largeur = ft_atoi(str);
		ft_strdel(&str);
	}
	if (arg[i] == '.')
	{
		while (arg[++i] >= 48 && arg[i] <= 57)
			str = ft_strjoinchar(str, arg[i]);
		tmp->precision = (str != NULL && ft_strcmp(str, "0") != 0) ?
			ft_atoi(str) : -1;
		ft_strdel(&str);
	}
	return (i);
}
