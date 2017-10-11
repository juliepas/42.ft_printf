/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 18:14:31 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/10 18:14:33 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_strcat_p(char *dest, const char *src, size_t n, size_t *len)
{
	size_t		i;

	i = n;
	if (src < dest)
	{
		while (i)
		{
			dest[*len + i - 1] = src[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dest[*len + i] = src[i];
			i++;
		}
	}
	*len += n;
	return (dest);
}

void			print_str(char **finalstr, t_conv **tamp, char *format, int k)
{
	t_conv		*tmp;
	size_t		i;
	size_t		j;
	size_t		len;

	tmp = *tamp;
	len = 0;
	j = 0;
	i = 0;
	while (format[j + i] != '\0')
		if (format[j + i] == '%' && tmp)
		{
			ft_strcat_p(*finalstr, &format[j], i, &len);
			ft_strcat_p(*finalstr, tmp->data, tmp->leng, &len);
			i = (tmp->indicateur == '%') ? i + 1 : i + 0;
			while (format[j + i] != tmp->indicateur && format[j + i] != '\0')
				i++;
			j += i + 1;
			i = 0;
			tmp = tmp->next;
		}
		else
			i++;
	ft_strcat_p(*finalstr, &format[j], i, &len);
	write(1, *finalstr, k);
}
