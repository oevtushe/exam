#include <unistd.h>

void	ft_putstr(const char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		write(1, &str[i++], 1);
}

int		ft_isallowed(char c)
{
	if (c == ' ' || c == '\t')
		return (0);
	return (1);
}

size_t	ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

void	rev_wstr(const char *str)
{
	size_t	i;
	size_t	start;
	size_t	end;
	int		apr;

	apr = 0;
	i = ft_strlen(str);
	while (i--)
	{
		if (ft_isallowed(str[i]))
		{
			end = i;
			while (i && ft_isallowed(str[i - 1]))
				--i;
			start = i;
			if (apr)
				ft_putstr(" ", 1);
			ft_putstr(str + start, end - start + 1);
			i = start;
			apr = 1;
		}
	}
	ft_putstr("\n", 1);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("\n", 1);
		return (1);
	}
	rev_wstr(argv[1]);
	return (0);
}
