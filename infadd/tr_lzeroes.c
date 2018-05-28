/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tr_lzeroes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:59:08 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/28 13:59:19 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infadd.h"

/*
** Safe leading zeroes removing.
**
** Case when leading zeroe's has place:
** 		1. "10" "-16" => complement = 90,
** 			90 + 16 = 106, and by removing
** 			leading '1' we get "06".
**
** "Safe" has mean that if result is zero
** itself then we don't remove it.
*/

void	tr_lzeroes(char **res)
{
	int tz;
	int last;

	tz = 0;
	last = ft_strlen(*res) - 1;
	while (tz < last && (*res)[tz] == '0')
		++tz;
	if (tz)
		prefix_del(res, tz);
}
