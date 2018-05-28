/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infadd.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:47:17 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/28 15:45:10 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFADD_H
# define INFADD_H

# include <stdlib.h>

size_t	ft_strlen(char *str);
char	*ft_strnew(size_t size);
int		ft_strcmp(char *str1, char *str2);
void	ft_putstr(char *str);

char	*add_values(char *v1, char *v2);
void	tr_lzeroes(char **res);
void	prefix_del(char **str, size_t n);
void	prefix_add(char **str, char prefix);

#endif
