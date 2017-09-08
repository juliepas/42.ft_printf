#include "libftprintf.h"

void	is_string(t_conv **tamp, char *argument) 
{
	t_conv	*tmp;
	int i;

	tmp = *tamp;
	i = 0;
	if (argument == NULL)
		argument = "(null)";
	if (tmp->largeur != 0 && (tmp->largeur > tmp->precision
		|| tmp->largeur >= ft_strlen(argument))) 
	{
		longueur_de_champ(&tmp);
		if (tmp->attributs[2] == 0)
		{
			if (tmp->precision > 0 &&
				tmp->precision < ft_strlen(argument))
				i = ft_strlen(tmp->data) - tmp->precision;
			else if (tmp->precision == -1)
				i = tmp->precision;
			else
				i = ft_strlen(tmp->data) - ft_strlen(argument);
		}
	}
	else if (tmp->precision < (int)ft_strlen(argument))
		tmp->data = ft_strnew(tmp->precision + 1);
	else
		tmp->data = ft_memalloc(ft_strlen(argument));
	precision_str(&tmp, argument, i);
}

char	*conversion_S(t_conv **tamp, wchar_t *argument)
{
	t_conv *tmp;
	int i;
	char *str;

	tmp = *tamp;
	i = 0;
	if (argument == NULL)
	{
		str = ft_strdup("(null)");
		return(str);
	}
	else if (argument[i] == '\0')
		return(NULL);
	str = ft_strdup(conversion_C(&tmp, argument[i]));
	i += 1;
	while (argument[i])
	{
		str = ft_strjoin(str, conversion_C(&tmp, argument[i]));
		i++;
	}
	return(str);
}

void	is_string_S(t_conv **tamp, wchar_t *argument) 
{
	t_conv	*tmp;
	char *str;
	int i;
	int j;

	tmp = *tamp;
	i = 0;
	str = conversion_S(&tmp, argument);
	if (str != NULL)
	{
		if (tmp->largeur != 0 && (tmp->largeur > tmp->precision
		|| sizeof(tmp->largeur) >= sizeof(argument)))
		{
			longueur_de_champ(&tmp);
			if (tmp->attributs[2] == 0)
			{
				if (tmp->precision > 0 && 
					tmp->precision < (sizeof(argument)))
					i = sizeof(argument) - sizeof(tmp->precision);
				else if (tmp->precision == -1)
					i = tmp->precision;
				else
					i = sizeof(tmp->data) - sizeof(argument);
			}
		}
		else
			tmp->data = ft_memalloc(sizeof(argument));
		precision_str(&tmp, str, i);
	}
	ft_strdel(&str);
}