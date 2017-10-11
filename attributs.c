/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attributs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 18:12:20 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/10 18:12:23 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ajout_attributs_gauche_bis(t_conv **tamp, char *arg, int *i,
	int *j)
{
	t_conv		*tmp;

	tmp = *tamp;
	if (((tmp->attributs[3] == 1 && arg[0] != '-') ||
		(tmp->attributs[3] == 1 && tmp->attributs[1] == 1 && arg[0] != '-')))
	{
		tmp->data[0] = '+';
		if (*i == 0)
			*i += 1;
	}
	else if ((arg[0] == '-' && tmp->attributs[1] == 1) ||
		(arg[0] == '-' && tmp->precision > (int)ft_strlen(arg)))
	{
		tmp->data[0] = '-';
		*i += 1;
		*j += 1;
	}
	else if (tmp->attributs[4] == 1 && arg[0] != '-')
	{
		tmp->data[0] = ' ';
		if (*i == 0)
			*i += 1;
	}
}

void			ajout_attributs_gauche(t_conv **tamp, char *arg, int *i, int *j)
{
	t_conv		*tmp;

	tmp = *tamp;
	if ((tmp->indicateur == 'o' || tmp->indicateur == 'O')
		&& tmp->attributs[0] == 1)
	{
		tmp->data[0] = '0';
		if (*i == 0)
			*i += 1;
	}
	else if (tmp->indicateur == 'p' || tmp->indicateur == 'x'
		|| tmp->indicateur == 'X')
	{
		tmp->data[0] = '0';
		if (tmp->indicateur == 'X')
			tmp->data[1] = 'X';
		else
			tmp->data[1] = 'x';
	}
	else
		ajout_attributs_gauche_bis(&tmp, arg, i, j);
}

void			ajout_attributs_droite_bis(t_conv **tamp, char *arg, int *i,
	int *j)
{
	t_conv		*tmp;

	tmp = *tamp;
	if ((tmp->attributs[3] == 1 && arg[0] != '-') ||
		(tmp->attributs[3] == 1 && tmp->attributs[1] == 1 && arg[0] != '-'))
		tmp->data[*i - 1] = '+';
	else if ((arg[0] == '-' && tmp->attributs[1] == 1) ||
		(arg[0] == '-' && tmp->precision > (int)ft_strlen(arg)))
	{
		tmp->data[*i - 1] = '-';
		*j += 1;
	}
	else if (tmp->attributs[4] == 1 && arg[0] != '-')
		tmp->data[*i - 1] = ' ';
}

void			ajout_attributs_droite(t_conv **tamp, char *arg, int *i, int *j)
{
	t_conv		*tmp;

	tmp = *tamp;
	if ((tmp->indicateur == 'o' || tmp->indicateur == 'O')
		&& tmp->attributs[0] == 1 && tmp->data[*i - 1] != '0')
		tmp->data[*i - 1] = '0';
	else if (tmp->indicateur == 'p' || tmp->indicateur == 'x'
		|| tmp->indicateur == 'X')
	{
		tmp->data[*i - 2] = '0';
		if (tmp->indicateur == 'X')
			tmp->data[*i - 1] = 'X';
		else
			tmp->data[*i - 1] = 'x';
	}
	else
		ajout_attributs_droite_bis(&tmp, arg, i, j);
}
