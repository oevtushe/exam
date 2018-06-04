/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inf_mult.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:09:10 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/04 16:44:29 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INF_MULT_H
# define INF_MULT_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>


char	*ft_strnew(size_t len);
int		ft_strcmp(const char *str1, const char *str2);
void	ft_putstr(char *str);
size_t	ft_strlen(char *str);
void	*ft_memalloc(size_t size);
void	swap_st(size_t *v1, size_t *v2);
void	swap_args(char **str1, char **str2);
char	*mult_values(char *str1, char *str2, size_t len1, size_t len2);
void	prefix_add(char **str, char prefix);

#endif
