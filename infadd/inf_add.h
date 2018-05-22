#ifndef INF_ADD_H
# define INF_ADD_H

# include <stdlib.h>

char	*add_values(char *v1, char *v2);
size_t	ft_strlen(char *str);
char	*ft_strnew(size_t size);
void	prefix_del(char **str, size_t n);
void	prefix_add(char **str, char prefix);

#endif
