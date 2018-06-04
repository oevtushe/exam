/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:41:23 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/04 16:43:36 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inf_mult.h"

static char	*make_string_n_free(int **arr, size_t size)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	last;

	i = 0;
	j = 0;
	last = size - 1;
	while (i < last && !(*arr)[i])
		++i;
	str = ft_strnew(size - i);
	while (i < size)
		str[j++] = (*arr)[i++] + '0';
	free(*arr);
	return (str);
}

static	void	val_normalize(int *arr, size_t size)
{
	size_t	i;
	int		carry;

	i = size;
	carry = 0;
	while (i--)
	{
		arr[i] += carry;
		if (arr[i] > 9)
		{
			carry = arr[i] / 10;
			arr[i] = arr[i] % 10;
		}
		else
			carry = 0;
	}
	if (carry)
		arr[0] += carry;
}

char	*mult_values(char *str1, char *str2, size_t len1, size_t len2)
{
	int		*res;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	res_size;

	i = len1;
	j = len2;
	res_size = i + j;
	k = res_size;
	res = (int*)ft_memalloc(sizeof(int) * res_size);
	while (j--)
	{
		i = len1;
		while (i--)
			res[--k] += (str1[i] - '0') * (str2[j] - '0');
		k = res_size - (len2 - j);
		if (j && j % 26512000 == 0)
			val_normalize(res, res_size);
	}
	val_normalize(res, res_size);
	return (make_string_n_free(&res, res_size));
}
