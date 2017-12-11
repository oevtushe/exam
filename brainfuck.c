#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*g_bytes;
char	*g_str;

void	resize(int new_size, int old_size)
{
	int		i;
	char	*tmp;

	tmp = malloc(sizeof(char) * new_size);
	i = -1;
	while (++i < old_size)
	{
		tmp[i] = g_bytes[i];
	}
	free(g_bytes);
	g_bytes = tmp;
}

void	opers(char c, int *bc, int *bs)
{
	if (c == '>')
	{
		(*bc)++;
		if (*bc >= *bs)
		{
			resize(2 * *bs, *bs);
			*bs *= 2;
			g_bytes[*bc] = 0;
		}
	}
	else if (c == '<')
		(*bc)--;
	else if (c == '+')
		g_bytes[*bc]++;
	else if (c == '-')
		g_bytes[*bc]--;
	else if (c == '.')
		write(1, &g_bytes[*bc], 1);
}

int		rec(int *bs, int *bc, int i) 
{
	int returned;

	returned = 0;
	while (g_str[++i] != ']')
	{
		if (g_str[i] == '[')
		{
			if (g_bytes[*bc] != 0)
			{
				if((returned = rec(bs, bc, i)))
					i = returned;
				else
					--i;
			}
		}
		else
			opers(g_str[i], bc, bs);
	}
	if (g_bytes[*bc] == 0)
		return (i);
	return (0);
}

char	*reformat(char *old)
{
	char	*reformated;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = -1;
	len = 0;
	while (old[len] != '\0')
		++len;
	reformated = malloc(sizeof(char) * (len + 2 + 1));
	reformated[i] = '[';
	reformated[len + 1] = ']';
	reformated[len + 2] = '\0';
	while (old[++j] != '\0')
		reformated[++i] = old[j];
	return (reformated);
}

int		main(int args, char **argv)
{
	int bc;
	int bs;

	bc = 1;
	bs = 2;
	if (args == 2)
	{
		g_bytes = malloc(sizeof(char) * 2);
		g_bytes[0] = 0;
		g_bytes[1] = 0;
		g_str = reformat(argv[1]);
		rec(&bs, &bc, -1);
	}
	return (0);
}
