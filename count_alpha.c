#include <stdio.h>
#include <unistd.h>

int		is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

void	count_alpha(char *str)
{
	int		i;
	int		j;
	int		cnt;
	char	c;

	i = -1;
	while (str[++i])
	{
		if (is_alpha(str[i]))
		{
			c = str[i];
			j = i;
			cnt = 1;
			while (str[++j])
			{
				if (str[j] == str[i])
				{
					++cnt;
					str[j] = '_';
				}
			}
			printf( ? "%d%c, " : "%d%c\n", cnt, c);
		}
	}
}

/* ___42_\0*/

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("\n");
		return (1);
	}
	count_alpha(argv[1]);
	return (0);
}
