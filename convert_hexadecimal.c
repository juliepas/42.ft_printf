#include "libftprintf.h"

char	*conversion_x_X(t_conv **tamp, unsigned long long int argument)
{
	t_conv *tmp;
	char *str2;

	tmp = *tamp;
	if (tmp->longueur[2] == 1 || tmp->longueur[3] == 1
		|| tmp->longueur[4] == 1 || tmp->longueur[5] == 1 || (int)argument < 0
		|| tmp->indicateur == 'p')
		str2 = (tmp->indicateur == 'x' || tmp->indicateur == 'p') ? ft_itoabaseunsigned(argument, 16) : ft_itoabaseXlong(argument, 16);
	else if (tmp->longueur[1] == 1)
		str2 = (tmp->indicateur == 'x') ? ft_itoa_base((unsigned char)argument, 16) : ft_itoa_baseX((unsigned char)argument, 16);
	else
		str2 = (tmp->indicateur == 'x') ? ft_itoa_base(argument, 16) : ft_itoa_baseX(argument, 16);
	return (str2);
}


void	flag_x_X(t_conv **tamp, unsigned long long int argument) 
{
	t_conv	*tmp;
	char *str;
	int i;
	int j;

	tmp = *tamp;
	i = 0;
	j = -1;
	str = conversion_x_X(&tmp, argument);
	if (tmp->largeur != 0 && tmp->largeur > tmp->precision 
		&& tmp->largeur > ft_strlen(str)) 
	{
		longueur_de_champ(&tmp);
		if (tmp->attributs[2] == 0)
		{
			if (tmp->precision > ft_strlen(str))
				i = ft_strlen(tmp->data) - tmp->precision;
			else
				i = ft_strlen(tmp->data) - ft_strlen(str);
		}
		else if (tmp->attributs[0] == 1 || tmp->indicateur == 'p')
			i += 2;
	}
	else if ((tmp->largeur < tmp->precision) && (tmp->precision > (int)ft_strlen(str)))
	{
		if (tmp->indicateur == 'p' || (tmp->attributs[0] == 1 && ft_strcmp(str, "0") != 0))
			i += 2;
		tmp->data = ft_strnew(tmp->precision + i);
	}
	else
	{
		if (tmp->indicateur == 'p' || (tmp->attributs[0] == 1 && ft_strcmp(str, "0") != 0))
			i += 2;
		tmp->data = (char*)malloc(sizeof(char) * (ft_strlen(str) + i));
	}
	if (tmp->precision != -1 || tmp->indicateur == 'p')
		precision_int(&tmp, str, i);
	ft_strdel(&str);
}
