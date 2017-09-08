#include "libftprintf.h"

void			create_maillon(t_conv **conversions, char *arg)
{
	t_conv	*tmp;
	t_conv	*new;
	int i;
	int j;

	j = -1;
	tmp = *conversions;
	new = (t_conv*)malloc(sizeof(t_conv));
	i = add_attributs(&new, arg);
	i = add_largeur_precision(&new, arg, i);
	i = add_longueur(&new, arg, i);
	i = add_indicateur(&new, arg, i);
	if (i == 1)
	{
		new->leng = 0;
		new->next = NULL;
		new->data = NULL;
		if (*conversions == NULL)
			*conversions = new;
		else 
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}

int				trim_argument(char *format, char **arg, int i)	
{
	char	*str;
	int 	j;
	int 	k;

	j = i + 1;
	k = 0;
	str = "%sSpdDioOuUxXcC";
	while (format[j]) 
	{
		while (str[k]) 
		{
			if (format[j] == str[k])
				break;
			else
				k++;
		}
		*arg = ft_strjoinchar(*arg, format[j]);
		if (str[k])
			return(j);
		j++;
		k = 0;
	}
	if (!(format[j] && str[k]))
		ft_strdel(arg);
	return(i);
}

int			parseur_printf(char *format, t_conv **conversions) 
{
	int		i;
	int 	j;
	int 	k;
	char	*arg;

	i = 0;
	j = 0;
	k = 0;
	arg = NULL;
	while (format[i] != '\0') 
	{
		if (format[i] == '%' && format[i + 1])
		{
				i = trim_argument(format, &arg, i);
				if (arg != NULL)
				{
					create_maillon(conversions, arg);
					if (*conversions == NULL)
					{
						while (format[i] != '%')
							i--;
						i += 1;
					}
					arg = NULL;
				}
		}
		else if (format[i] != '%')
			j++;
		i++;
	}
	return(j);
}