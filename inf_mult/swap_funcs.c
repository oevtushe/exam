/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:39:34 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/04 16:39:48 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inf_mult.h"

void	swap_args(char **str1, char **str2)
{
	char *str3;

	str3 = *str1;
	*str1 = *str2;
	*str2 = str3;
}

void	swap_st(size_t *v1, size_t *v2)
{
	size_t v3;

	v3 = *v1;
	*v1 = *v2;
	*v2 = v3;
}
