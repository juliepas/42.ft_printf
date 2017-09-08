#include "libftprintf.h"

char	*ft_strcat_p(char *dest, const char *src, size_t n, size_t len)
{
	unsigned char	*s11;
	unsigned char	*s22;
	size_t			i;

	s11 = (unsigned char*)dest;
	s22 = (unsigned char*)src;
	i = n;
	if (src < dest)
	{
		while (i)
		{
			s11[len + i - 1] = s22[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			s11[len + i] = s22[i];
			i++;
		}
	}
	return(dest);
}

void	print_str(char **finalstr, t_conv **tamp, char *format, int k)
{
	t_conv	*tmp;
	int i;
	int j;
	int len;

	tmp = *tamp;
	len = 0;
	i = 0;
	j = 0;
	while (tmp != NULL)
	{
		i = ft_strchrint(&format[j], '%');
		if (i > -1)
		{
			if (i > 0)
			{
				ft_strcat_p(*finalstr, &format[j], i, len);
				len += i;
			}
			if (tmp->data != NULL)
			{
				ft_strcat_p(*finalstr, tmp->data, tmp->leng, len);
				len += tmp->leng;
			}
			j += i;
			i = ft_strchrint(&format[j + 1], tmp->indicateur);
			i += 2;
			j += i;
			tmp = tmp->next;
		}
	}
	i = ft_strchrint(&format[j], '%');
	if (i != -1)
	{
		if (i > 0)
			ft_strcat_p(*finalstr, &format[j], i, len);
		len += i;
		j += i + 1;
		if (format[j] == ' ')
			j += 1;
	}
	i = ft_strchrint(&format[j], '\0');
	ft_strcat_p(*finalstr, &format[j], i, len);
	write(1, *finalstr, k);
}