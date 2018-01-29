#include <stdio.h>
#include <string.h>

char	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

void	mnm(const char *str, size_t i, int *bm, int *alp)
{
	size_t	j;
	int		cur_cnt;

	j = i;
	cur_cnt = 1;
	while (str[++j])
	{
		if (ft_tolower(str[j]) == ft_tolower(str[i]))
		{
			bm[j] = 0;
			++cur_cnt;
		}
	}
	if (*alp)
		printf(", ");
	printf("%d%c", cur_cnt, ft_tolower(str[i]));
	*alp = 1;
}

void	count_alpha_hlp(const char *str, size_t len)
{
	size_t	i;
	char	c;
	int		bm[len];
	int		alp;

	i = len;
	alp = 0;
	while (i--)
	{
		c = str[i];
		bm[i] = ((c >= 'a' && c <= 'z') 
				|| (c >= 'A' && c <= 'Z')) ? 1 : 0;
	}
	i = 0;
	while (i < len)
	{
		if (bm[i])
			mnm(str, i, bm, &alp);
		++i;
	}
	printf("\n");
}

void	count_alpha(const char *str)
{
	size_t len;

	len = 0;
	while (str[len])
		++len;
	count_alpha_hlp(str, len);
}

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
