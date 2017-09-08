#include "libftprintf.h"

char				*ft_itoabaseXlong(unsigned long long int n, int base)
{
	char			*str;
	long long int	i;
	unsigned long long int	nb;

	nb = n;
	i = ft_nbrunsigned(nb, base);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	i--;
	if (nb == 0 || nb == -0)
		str[i] = '0';
	while (nb > 0)
	{
		if (nb % base <= 9)
			str[i] = nb % base + '0';
		else
			str[i] = ((nb % base) - 10) + 'A';
		nb = nb / base;
		i--;
	}
	return (str);
}

char				*ft_itoa_baseX(unsigned int n, int base)
{
	char			*str;
	int	i;
	long	nb;

	nb = n;
	i = ft_nbrlongue(nb, base);
	if (!(str = (char*)malloc(sizeof(char) * i)))
		return (0);
	str[i] = '\0';
	i--;
	if (nb == 0 || nb == -0)
		str[i] = '0';
	while (nb > 0)
	{
		if (nb % base <= 9)
			str[i] = nb % base + '0';
		else
			str[i] = ((nb % base) - 10) + 'A';
		nb = nb / base;
		i--;
	}
	return (str);
}