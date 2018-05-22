#include <stdio.h>
#include "inf_add.h"

char	*complement10(char *val)
{
	size_t	len;
	char	*res;
	char	*tmp;

	len = ft_strlen(val);
	res = ft_strnew(len);
	while (len--)
		res[len] = '9' - val[len] + '0';
	tmp = res;
	res = add_values(res, "1");
	free(tmp);
	return (res);
}

void	negative_res(char **str)
{
	char	*res;

	res = complement10(*str);
	prefix_add(&res, '-');
	free(*str);
	*str = res;
}

/*
** -3 -4
*/

void	tr_lzeroes(char **res)
{
	int tz;

	while ((*res)[tz] == '0')
		++tz;
	if (tz)
		prefix_del(res, tz);
}

char	*inf_add(char *v1, char *v2)
{
	char	*res;
	char	*comp;
	int		tz;

	tz = 0;
	if (v1[0] == '-' && v2[0] == '-')
	{
		res = add_values(&v1[1], &v2[1]);
		prefix_add(&res, '-');
	}
	else if (v1[0] == '-' || v2[0] == '-')
	{
		if (v1[0] == '-')
		{
			comp = complement10(&v1[1]);
			res = add_values(comp, v2);
		}
		else
		{
			comp = complement10(&v2[1]);
			res = add_values(v1, comp);
		}
		if (ft_strlen(comp) == ft_strlen(res))
			negative_res(&res);
		else
			prefix_del(&res, 1);
		tr_lzeroes(&res);
	}
	else
		res = add_values(v1, v2);
	return (res);
}

/*
** 9112 - 9110
** 19 - 9
*/

int		main(int argc, char **argv)
{
	char	*str;
	if (argc != 3)
		return (1);
	str = inf_add(argv[1], argv[2]);
	printf("%s\n", str);
	free(str);
	return (0);
}
