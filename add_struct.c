#include "libftprintf.h"


int			add_indicateur(t_conv **new, char *arg, int i)
{
	int j;
	t_conv *tmp;

	tmp = *new;
	j = ft_strlen(arg);
	if ((j - 1) == i && arg[i] != '\0')
		tmp->indicateur = arg[j - 1];
	else
		return(0);
	return(1);
}

int			add_attributs(t_conv **new, char *arg) 
{
	int i;
	char *str;
	int j;
	t_conv *tmp;
	tmp = *new;
	i = -1;
	j = -1;
	str = "#0-+ ";
	while (tmp->attributs[++j])
		tmp->attributs[j] = 0;
	j = -1;
	while (arg[++i] == '#' || arg[i] == '0' || arg[i] == '-' || arg[i] == '+' || arg[i] == ' ')
	{
		while (str[++j]) 
		{
			if (arg[i] == str[j]) 
			{
				tmp->attributs[j] = 1;
				break;
			}
		}		
		j = -1;
	}
	return(i);
}

int			add_longueur(t_conv **new, char *arg, int i) 
{
	char *str;
	int j;
	t_conv *tmp;

	tmp = *new;
	j = -1;
	str = "hxlyjz";
	while (tmp->longueur[++j])
		tmp->longueur[j] = 0;
	j = -1;
	while (arg[i] == 'h' || arg[i] == 'l' || arg[i] == 'j' || arg[i] == 'z')
	{
		while (str[++j]) 
		{
			if (arg[i] == str[j]) 
			{
				if (arg[i + 1] == str[j]) {
					tmp->longueur[j + 1] = 1;
					i += 1;
				}
				else
					tmp->longueur[j] = 1;
				break;
			}
		}
		if (j < 5)
		{
			i++;
			break;
		}
		i++;
		j = -1;
	}
	return(i);
}

int			add_largeur_precision(t_conv **new, char *arg, int i) 
{
	char 	*str;
	t_conv	*tmp;

	tmp = *new;
	str = NULL;
	if (arg[i] >= 48 && arg[i] <= 57) {
		while (arg[i] >= 48 && arg[i] <= 57) 
		{
			str = ft_strjoinchar(str, arg[i]);
			i++;
		}
		tmp->largeur = ft_atoi(str);
		ft_strdel(&str);
	}
	if (arg[i] == '.') {
		str = NULL;
		while (arg[++i] >= 48 && arg[i] <= 57)
			str = ft_strjoinchar(str, arg[i]);
		if (str != NULL && ft_strcmp(str, "0") != 0)
			tmp->precision = ft_atoi(str);
		else 
			tmp->precision = -1;
		ft_strdel(&str);
	}
	return(i);
}