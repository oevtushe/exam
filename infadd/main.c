/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:53:29 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/28 15:46:37 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infadd.h"

/*
** Function finds complement to ten of given number in string
*/

static char	*complement10(char *val)
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

/*
** Function swaps arguments if length of second string > length
** of first (signs doesn't count).
*/

static void	stat1(char **s1, char **s2)
{
	char *tmp;

	if (((*s1)[0] == '-' && ft_strlen(&(*s1)[1]) < ft_strlen(*s2)) ||
			((*s2)[0] == '-' && ft_strlen(*s1) < ft_strlen(&(*s2)[1])))
	{
		tmp = *s2;
		*s2 = *s1;
		*s1 = tmp;
	}
}

static void	handle_res(char **res, char *comp, char v1_sign)
{
	size_t	dif;
	char	*tmp;

	dif = ft_strlen(comp) - ft_strlen(*res);
	if (!dif)
	{
		tmp = *res;
		*res = complement10(*res);
		free(tmp);
		tr_lzeroes(res);
		if (v1_sign && (*res)[0] != '0')
			prefix_add(res, '-');
	}
	else
	{
		prefix_del(res, 1);
		tr_lzeroes(res);
		if (!v1_sign && (*res)[0] != '0')
			prefix_add(res, '-');
	}
}

/*
** Statements:
** 		1. v1 length >= v2 length
** 		2. if res length == comp length then |v1| > |v2|
** 		3. if res length != comp length then |v1| < |v2|
** 		4. if v1 < 0 and v2 > 0 and (2) then result < 0
**		5. if v1 > 0 and v2 < 0 and (3) then result > 0
*/

char	*inf_add(char *v1, char *v2)
{
	char	*res;
	char	*comp;

	if (v1[0] == '-' && v2[0] == '-')
	{
		res = add_values(&v1[1], &v2[1]);
		prefix_add(&res, '-');
	}
	else if (v1[0] == '-' || v2[0] == '-')
	{
		stat1(&v1, &v2);
		if (v1[0] == '-')
		{
			comp = complement10(&v1[1]);
			res = add_values(comp, v2);
		}
		else
		{
			comp = complement10(v1);
			res = add_values(comp, &v2[1]);
		}
		handle_res(&res, comp, v1[0] == '-' ? 1 : 0);
		free(comp);
	}
	else
		res = add_values(v1, v2);
	return (res);
}

int		main(int argc, char **argv)
{
	char	*str;
	if (argc != 3)
		return (1);
	str = inf_add(argv[1], argv[2]);
	ft_putstr(str);
	ft_putstr("\n");
	free(str);
	return (0);
}
