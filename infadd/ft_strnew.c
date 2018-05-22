#include "inf_add.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	while (i <= size)
		str[i++] = '\0';
	return (str);
}
