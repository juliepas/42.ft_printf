#include "libft.h"

int		ft_nbrlongu(int n, int base)
{
	int i;

	i = 0;
	if (n == 0)
		i = 1;
	else if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

char				*ft_itoa_base(int n, int base)
{
	char			*str;
	int	i;
	int	nb;

	nb = n;
	i = ft_nbrlongu(nb, base);
	if (base == 8)
		i += 1;
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	else if (nb < 0 && base == 10)
	{
		str[i - i] = '-';
		nb = -nb;
	}
	str[i] = '\0';
	i--;
	if (nb == 0 || nb == -0)
		str[i] = '0';
	while (nb > 0)
	{
		if (nb % base <= 9)
			str[i] = nb % base + '0';
		else
			str[i] = ((nb % base) - 10) + 'a';
		nb = nb / base;
		i--;
	}
	return (str);
}