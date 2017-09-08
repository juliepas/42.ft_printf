#include "libftprintf.h"

void		is_char(t_conv **tamp, int argument)
{
	t_conv	*tmp;
	int i;

	tmp = *tamp;
	i = 0;
	if (tmp->largeur != 0 && tmp->largeur > tmp->precision)
	{
		longueur_de_champ(&tmp);
		if (tmp->attributs[2] == 0)
			i = ft_strlen(tmp->data) - 1;
	}
	else
		tmp->data = ft_strnew(1);
	tmp->data[i] = argument;
}

int		longueur_wchart(wchar_t argument, int len)
{
	int i;
	
	i = 0;
	if (len % 6 == 0)
		i = len / 6;
	else
		i = len / 6 + 1;
	return(i);
}

char 	*conversion_C(t_conv **tamp, wchar_t argument)
{
	t_conv *tmp;
	int len;
	int i;
	char *str;

	tmp = *tamp;
	len = ft_nbrlongue(argument, 2);
	i = longueur_wchart(argument, len);
	str = ft_memalloc(sizeof(wchar_t) * i);
	if (len > 7)
	{
		str[i] = '\0';
		while(i > 1)
		{
			str[i - 1] = (argument & 0x3F);
			str[i - 1] += 0x80;
			argument = argument >> 6;
			i--;

		}
		i = longueur_wchart(argument, len);
		str[0] = (0xF0 << (4 - i)) | argument;
	}
	else
		str[0] = (char)argument;
	return(str);
}


void		is_char_extended(t_conv **tamp, wchar_t argument)
{
	t_conv	*tmp;
	char *str;
	int i;
	int j;

	tmp = *tamp;
	i = 0;
	str = conversion_C(&tmp, argument);
	if (str != NULL)
	{
		if (tmp->largeur != 0 && tmp->largeur > tmp->precision
			&& tmp->largeur > ft_strlen(str)) 
		{
			longueur_de_champ(&tmp);
			if (tmp->attributs[2] == 0)
				i = ft_strlen(tmp->data) - ft_strlen(str);
		}
		else
			tmp->data = (char*)malloc(sizeof(char) * (ft_strlen(str)));
		precision_str(&tmp, str, i);
	}
	ft_strdel(&str);
}