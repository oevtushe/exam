#include "inf_add.h"

void	prefix_del(char **str, size_t n)
{
	size_t	i;
	size_t	len;
	char	*buf;

	i = n;
	len = ft_strlen(*str);
	buf = ft_strnew(len - n);
	while (i < len)
	{
		buf[i - n] = (*str)[i];
		++i;
	}
	free(*str);	
	*str = buf;
}

void	prefix_add(char **str, char prefix)
{
	size_t	i;
	char	*new_str;
	size_t	new_size;

	i = 0;
	new_size = ft_strlen(*str) + 1;
	new_str = ft_strnew(new_size);
	new_str[i++] = prefix;
	while (i < new_size)
	{
		new_str[i] = (*str)[i - 1];
		++i;
	}
	free(*str);
	*str = new_str;
}
