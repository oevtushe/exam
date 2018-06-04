/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:44:03 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/04 16:44:48 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inf_mult.h"

void	prefix_add(char **str, char prefix)
{
	size_t	i;
	char	*new_str;
	size_t	new_size;

	i = 0;
	new_size = ft_strlen(*str) + 1;
	new_str = ft_strnew(new_size);
	new_str[i++] = prefix;
	while (i < new_size)
	{
		new_str[i] = (*str)[i - 1];
		++i;
	}
	free(*str);
	*str = new_str;
}
