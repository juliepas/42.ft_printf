#include "libft.h"

char	*ft_strrev(char *str)
{
	int i;
	int j;
	char c;

	i = 0;
	j = ft_strlen(str) - 1;
	c = 0;
	while (i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
	return(str);
}