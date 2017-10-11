/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 18:13:59 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/10 18:14:01 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			precision_superieure(t_conv **tamp, char *arg, int *i)
{
	t_conv		*tmp;
	int			j;

	tmp = *tamp;
	j = 0;
	if (tmp->attributs[0] == 1 && (tmp->indicateur == 'o'
		|| tmp->indicateur == 'O'))
		*i -= 1;
	if (tmp->precision == (int)ft_strlen(arg) && arg[0] == '-')
		*i -= 1;
	while ((*i + j) < (*i + tmp->precision))
	{
		tmp->data[*i + j] = '0';
		j++;
	}
	if (arg[0] == '-')
		*i += tmp->precision - ft_strlen(arg) + 1;
	else
		*i += tmp->precision - ft_strlen(arg);
}

void			precision_int(t_conv **tamp, char *arg, int i)
{
	t_conv		*tmp;
	int			j;

	tmp = *tamp;
	j = -1;
	if (tmp->indicateur != 'u' && tmp->indicateur != 'U'
		&& ((tmp->indicateur != 'o' && tmp->indicateur != 'O'
			&& tmp->indicateur != 'x' && tmp->indicateur != 'X')
			|| tmp->attributs[0] == 1) && (tmp->indicateur == 'd'
			|| tmp->indicateur == 'p' || ft_strcmp(arg, "0") != 0))
		(tmp->attributs[1] == 1 || i == 0) ?
			ajout_attributs_gauche(&tmp, arg, &i, &j) :
			ajout_attributs_droite(&tmp, arg, &i, &j);
	if (tmp->precision >= (int)ft_strlen(arg) && tmp->precision != -1)
		precision_superieure(&tmp, arg, &i);
	if (tmp->precision != -1 || tmp->attributs[0] == 1
		|| ft_strcmp(arg, "0") != 0)
		while (++j < (int)ft_strlen(arg))
		{
			tmp->data[i] = arg[j];
			i++;
		}
	if (tmp->data[i] != ' ')
		tmp->data[i] = '\0';
}

void			precision_str(t_conv **tamp, char *arg, int i)
{
	t_conv		*tmp;
	int			j;
	int			len;

	j = 0;
	tmp = *tamp;
	len = ft_strlen(arg);
	if (tmp->precision > 0 && tmp->precision < len)
		len = tmp->precision;
	if (tmp->precision != -1)
	{
		while (j < len)
		{
			tmp->data[i] = arg[j];
			i++;
			j++;
		}
	}
	if (tmp->data[i] != ' ')
		tmp->data[i] = '\0';
}

void			longueur_de_champ(t_conv **tamp)
{
	t_conv		*tmp;
	int			i;
	int			size;

	tmp = *tamp;
	i = -1;
	size = tmp->largeur;
	if (tmp->largeur != 0)
	{
		tmp->data = ft_memalloc(tmp->largeur);
		if ((tmp->attributs[1] == 1 && tmp->attributs[2] == 0) &&
			!((tmp->indicateur == 'i' || tmp->indicateur == 'd')
				&& tmp->precision != 0))
			while (++i < size)
				tmp->data[i] = '0';
		else
			while (++i < size)
				tmp->data[i] = ' ';
		tmp->data[i] = '\0';
	}
}
