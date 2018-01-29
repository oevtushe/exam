/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 08:51:59 by oevtushe          #+#    #+#             */
/*   Updated: 2017/11/28 09:26:25 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*dec_to_hex(int nb)
{
	char *hex;


}

void	print_memory(const void *addr, size_t size)
{
	char *arr;

	arr = (char*)addr;
}

int		main(void)
{
	int tab[10];
	printf("%lu\n", sizeof(tab));
	return (0);
}
