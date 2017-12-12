/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 07:12:00 by oevtushe          #+#    #+#             */
/*   Updated: 2017/12/12 09:10:16 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		ft_strlen_spec(char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
		{
			++len;
			while (*str == ' ' || *str == '\t')
				str++;
		}
		else
		{
			++len;
			str++;
		}
	}
	return (len);
}

int		ft_is_ws(char c)
{
	if (c != ' ' && c != '\t' && c != '\0')
		return (1);
	return (0);
}

void	init_middle(char *str, char *res, int *i, int *j)
{
	while (str[*i])
	{
		if (str[*i] == ' ' || str[*i] == '\t')
		{
			res[(*j)++] = str[(*i)++];
			while (str[*i] == ' ' || str[*i] == '\t')
			{
				++(*i);
			}
		}
		else
			res[(*j)++] = str[(*i)++];

	}
}

char	*rostring(char *str)
{
	int		i;
	int		j;
	int		start;
	int		end;
	char	*res;

	i = 0;
	j = 0;
	while (str[i] && !ft_is_ws(str[i]))
		++i;
	start = i;
	while (ft_is_ws(str[i]))
		++i;
	end = i;
	while (str[i] == ' ' || str[i] == '\t')
		++i;
	res = (char*)malloc(sizeof(char) * (ft_strlen_spec(&str[i]) + (end - start) + 2));
	init_middle(str, res, &i, &j);
	if (j && (str[start] != ' ' || str[start] != '\t'))
		res[j++] = ' ';
	while (start < end)
		res[j++] = str[start++];
	res[j] = '\0';
	return (res);
}

int		main(int argc, char **argv)
{
	char	c;
	char	*str;

	c = '\n';
	if (argc != 2)
	{
		write(1, &c, 1);
		return (1);
	}
	str = rostring(argv[1]);
	while (*str)
		write(1, str++, 1);
	write(1, &c, 1);
	return (0);
}
