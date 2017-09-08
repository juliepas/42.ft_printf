#include "libftprintf.h"

int		finalstr(t_conv **tamp, char *format, int i)
{
	t_conv *tmp;
	char *finalstr;

	tmp = *tamp;
	while (tmp != NULL)
	{

		if (tmp->data != NULL)
			tmp->leng = ft_strlen(tmp->data);
		if (tmp->data != NULL && (tmp->data[0] == '\0' || tmp->data[tmp->largeur] == '\0') 
			&& (tmp->indicateur == 'c' || tmp->indicateur == 'C'))
			tmp->leng += 1;
		i += tmp->leng;
		tmp = tmp->next;
	}
	if (!(finalstr = (char*)malloc(sizeof(char) * i)))
		return(-1);
	tmp = *tamp;
	print_str(&finalstr, &tmp, format, i);
	return(i);
}

void	is_unsigned_int(t_conv **tamp, unsigned long long int argument)
{
	t_conv *tmp;

	tmp = *tamp;
	if (tmp->indicateur == 'u' || tmp->indicateur == 'U')
		flag_u_U(&tmp, argument);
	else if (tmp->indicateur == 'o' || tmp->indicateur == 'O')
		flag_o_O(&tmp, argument);
	else if (tmp->indicateur == 'x' || tmp->indicateur == 'X' 
		|| tmp->indicateur == 'p')
		flag_x_X(&tmp, argument);
}

int		ft_printf(const char * restrict format, ...) 
{
	t_conv	*conversions;
	t_conv 	*tmp;
	va_list	ap;
	int i;

	conversions = NULL;
	i = parseur_printf((char*)format, &conversions);
	tmp = conversions;
	va_start(ap, format);
	while (tmp != NULL)
	{
		if (tmp->indicateur == 'S' || (tmp->indicateur == 's' && tmp->longueur[2] == 1))
			is_string_S(&tmp, va_arg(ap, wchar_t*));
		else if (tmp->indicateur == 's') 
			is_string(&tmp, va_arg(ap, char*));
		else if (tmp->indicateur == 'C' || (tmp->indicateur == 'c' && tmp->longueur[2] == 1))
			is_char_extended(&tmp, (wchar_t)va_arg(ap, wint_t));
		else if (tmp->indicateur == 'c')
			is_char(&tmp, va_arg(ap, int));
		else if (tmp->indicateur == 'D' || tmp->indicateur == 'd' || tmp->indicateur == 'i')
			flag_d_i(&tmp, va_arg(ap, long long int));
		else if (tmp->indicateur == 'p')
			flag_x_X(&tmp, (unsigned long long)va_arg(ap, void*));
		else if (tmp->indicateur == '%')
			flag_pourcent(&tmp);
		else
			is_unsigned_int(&tmp, (unsigned long long)va_arg(ap, long long int));
		tmp = tmp->next;
	}
	va_end(ap);
	i = finalstr(&conversions, (char*)format, i);
	return(i);
}