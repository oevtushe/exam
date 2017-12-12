/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_primes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 08:22:54 by oevtushe          #+#    #+#             */
/*   Updated: 2017/11/28 08:48:17 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	init_map(char *map, int hm)
{
	int i;

	i = -1;
	while (++i <= hm)
		map[i] = 1;
}

char	*ft_primes(int hm)
{
	int p;
	int i;
	char *map;

	map = (char*)malloc(sizeof(char) * (hm + 1));
	init_map(map, hm);
	p = 2;
	while (p * p <= hm)
	{
		i = p * p;
		if (map[i])
		{
			while (i <= hm)
			{
				map[i] = 0;
				i += p;
			}
		}
		++p;
	}
	return (map);
}

int		main(void)
{
	int i;
	int hm;
	char *primes;

	i = 1;
	hm = 1000;
	primes = ft_primes(hm);
	++hm;
	while (++i < hm)
		if (primes[i])
			printf("%d\n", i);
	return (0);
}
