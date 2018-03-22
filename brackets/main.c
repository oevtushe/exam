/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:48:34 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/22 18:16:23 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(const char *str)
{
	size_t	len;

	if (str)
	{
		len = 0;
		while (str[len])
			++len;
		write(1, str, len);
	}
}

int		itrptr(char c)
{
	int res;

	res = 0;
	if (c == '(')
		res = 1;
	else if (c == ')')
		res = -1;
	else if (c == '[')
		res = 2;
	else if (c == ']')
		res = -2;
	else if (c == '{')
		res = 3;
	else if (c == '}')
		res = -3;
	return (res);
}

int		check_close(int *arr, int len)
{
	int i;
	int	res;
	int bracket;

	i = 0;
	res = 0;
	bracket = arr[i++];
	while (i < len && arr[i] == 0)
		++i;
	if (arr[i] == -bracket)
	{
		arr[0] = 0;
		arr[i] = 0;
		res = 1;
	}
	return (res);
}

int		brackets(char *line, int len)
{
	int i;
	int	arr[len];

	i = -1;
	while(++i < len)
		arr[i] = itrptr(line[i]);
	while (i--)
		if (arr[i] > 0)
			if (!check_close(&arr[i], len - i))
				return (0);
	while (++i < len)
		if (arr[i] != 0)
			return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	int len;
	int	i;

	if (argc < 2)
	{
		ft_putstr("\n");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		len = 0;
		while (argv[i][len])
			++len;
		if (brackets(argv[i], len))
			ft_putstr("OK\n");
		else
			ft_putstr("Error\n");
		++i;
	}
	return (0);
}
