/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:45:02 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/28 13:57:35 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infadd.h"

int		ft_strcmp(char *str1, char *str2)
{
	while ((unsigned char)*str1 == (unsigned char)*str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
