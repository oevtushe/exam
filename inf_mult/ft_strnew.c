/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:05:52 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/04 11:10:01 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inf_mult.h"

char	*ft_strnew(size_t len)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * (len + 1));
	str[len] = 0;
	while (len--)
		str[len] = 0;
	return (str);
}
