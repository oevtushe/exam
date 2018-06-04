/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:46:28 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/04 11:48:15 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inf_mult.h"

void	*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*mem;

	i = 0;
	mem = (unsigned char*)malloc(sizeof(char) * size);
	while (i < size)
		mem[i++] = 0;
	return (mem);
}
