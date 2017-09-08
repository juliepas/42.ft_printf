#include "libftprintf.h"

char	*conversion_o_O(t_conv **tamp, unsigned long long int argument)
{
	t_conv *tmp;
	char *str2;

	tmp = *tamp;
	if (tmp->indicateur == 'O' || tmp->longueur[3] == 1 
		|| tmp->longueur[2] == 1 || tmp->longueur[4] == 1
		|| tmp->longueur[5] == 1)
		str2 = ft_itoabaseunsigned(argument, 8);
	else if (tmp->longueur[1] == 1)
		str2 = ft_itoa_base((unsigned char)argument, 8);
	else if (tmp->longueur[0] == 1)
		str2 = ft_itoa_base((unsigned short)argument, 8);
	else if ((int)argument < 0)
		str2 = ft_itoabaselong((unsigned long)argument, 8);
	else
		str2 = ft_itoa_base((unsigned long)argument, 8);
	return(str2);
}

void	flag_o_O(t_conv **tamp, unsigned long long int argument) 
{
	t_conv	*tmp;
	char *str;
	int i;
	int j;

	tmp = *tamp;
	i = 0;
	j = -1;
	str = conversion_o_O(&tmp, argument);
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
	}
	else if (tmp->precision > (int)ft_strlen(str))
	{
		if (tmp->largeur < tmp->precision) 
			tmp->data = ft_strnew(tmp->precision + 1);
	}
	else
		tmp->data = (char*)malloc(sizeof(char) * (ft_strlen(str)));
	precision_int(&tmp, str, i);
	ft_strdel(&str);
}