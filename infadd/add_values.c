/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:49:01 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/28 13:57:53 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infadd.h"

/*
** Function handle carry. 
**
** Given char array in each block contains sum
** of corresponding digits. Function takes carry and converts
** value to digit code in ASCII.
*/

static void	val_normalize(char **str, size_t len)
{
	int		i;
	int		carry;

	i = len;
	carry = 0;
	while (i--)
	{
		(*str)[i] += carry;
		if ((*str)[i] > 9)
		{
			(*str)[i] = (*str)[i] - 10 + '0';
			carry = 1;
		}
		else
		{
			(*str)[i] += '0';
			carry = 0;
		}
	}
	if (carry)
		prefix_add(str, '1');
}

/*
** Function sums given arguments
*/

char	*add_values(char *v1, char *v2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	res_size;
	char	*res;

	i = ft_strlen(v1);
	j = ft_strlen(v2);
	res_size = i > j ? i : j;
	k = res_size;
	res = ft_strnew(k);
	while (i--)
		res[--k] = v1[i] - '0';
	k = res_size;
	while (j--)
		res[--k] += v2[j] - '0';
	val_normalize(&res, res_size);
	return (res);
}
