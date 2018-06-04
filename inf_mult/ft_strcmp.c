/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:03:28 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/04 11:09:44 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *str1, const char *str2)
{
	while ((unsigned char)*str1 == (unsigned char)*str2)
	{
		++str1;
		++str2;
	}
	return (*str1 - *str2);
}
