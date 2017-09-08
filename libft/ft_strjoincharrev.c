/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoincharrev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:34:30 by jpascal           #+#    #+#             */
/*   Updated: 2017/03/06 18:34:51 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoincharrev(char *str, char c)
{
	int		i;
	int 	j;
	char	*tmp;

	i = 0;
	j = 0;
	if (str == NULL)
	{
		if (!(tmp = (char*)malloc(sizeof(char) * 2)))
			return (0);
	}
	else
	{
		if (!(tmp = (char*)malloc(sizeof(char) * (ft_strlen(str) + 2))))
			return (0);
		tmp[i] = c;
		while (str[i++])
		{
			tmp[j] = str[i];
			j++;
		}
	}
	tmp[j + 1] = '\0';
	ft_strdel(&str);
	return (tmp);
}
