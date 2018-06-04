/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 10:05:05 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/04 16:47:46 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inf_mult.h"

static char	*inf_mult(char *str1, char *str2)
{
	size_t	len1;
	size_t	len2;
	int		pref1;
	int		pref2;
	char	*res;

	pref1 = 0;
	pref2 = 0;
	if (str1[0] == '-')
		pref1 = 1;
	if (str2[0] == '-')
		pref2 = 1;
	len1 = ft_strlen(&str1[pref1]);
	len2 = ft_strlen(&str2[pref2]);
	if (len1 < len2)
	{
		swap_args(&str1, &str2);
		swap_st(&len1, &len2);
	}
	res = mult_values(&str1[pref1], &str2[pref2], len1, len2);
	if ((pref1 && !pref2) || (pref2 && !pref1))
		prefix_add(&res, '-');
	return (res);
}

int			main(int argc, char **argv)
{
	char *str;

	if (argc != 3)
		return (1);
	str = inf_mult(argv[1], argv[2]);
	ft_putstr(str);
	ft_putstr("\n");
	free(str);
	return (0);
}
