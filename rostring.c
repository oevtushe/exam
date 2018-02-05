/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 07:08:55 by oevtushe          #+#    #+#             */
/*   Updated: 2018/01/30 08:44:34 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(const char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		count_words(const char *str)
{
	int		wc;
	int		state;

	state = 0;
	wc = 0;
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
			state = 0;
		else if (!state)
		{
			state = 1;
			++wc;
		}
		++str;
	}
	return (wc);
}

char	*ft_strsub(const char *str, size_t start, size_t len)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (len + 1));
	res[len] = '\0';
	while (len--)
		res[len] = str[start + len];
	return (res);
}

char	**get_wa(const char *str)
{
	int		i;
	int		start;
	int		len;
	char	**wa;
	int		wa_idx;

	i = count_words(str);
	wa_idx = 0;
	wa = (char **)malloc(sizeof(char *) * (i + 1));
	wa[i] = (void*)0;
	i = -1;
	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			start = i;
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				++i;
			len = i-- - start;
			wa[wa_idx++] = ft_strsub(str, start, len);
		}
	}
	return (wa);
}

void	rostring(const char *str)
{
	int		idx;
	char	**wa;

	idx = 1;
	wa = get_wa(str);
	if (wa[idx] == NULL)
	{
		ft_putstr(wa[0]);
		ft_putstr("\n");
		return ;
	}
	while (wa[idx])
	{
		ft_putstr(wa[idx++]);
		ft_putstr(" ");
	}
	ft_putstr(wa[0]);
	ft_putstr("\n");
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc < 2)
	{
		ft_putstr("\n");
		return (1);
	}
	while (++i < argc)
	{
		rostring(argv[i]);
	}
	return (0);
}
