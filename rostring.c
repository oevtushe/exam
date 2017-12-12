/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 07:12:00 by oevtushe          #+#    #+#             */
/*   Updated: 2017/12/12 07:57:11 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str++)
		++len;
	return (len);
}

void	ft_putstr(char *str)
{
	if (str)
		while (*str)
			write(1, str++, 1);
}

int		ft_is_ws(char c)
{
	if (c != ' ' && c != '\t' && c != '\0')
		return (1);
	return (0);
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
	res = (char*)malloc(sizeof(char) * (ft_strlen(&str[i]) + (end - start) + 2));
	while (str[i])
		res[j++] = str[i++];
	res[j++] = ' ';
	while (start < end)
		res[j++] = str[start++];
	res[j] = '\0';
	return (res);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("\n");
		return (1);
	}
	ft_putstr(rostring(argv[1]));
	ft_putstr("\n");
	return (0);
}
