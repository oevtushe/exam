#ifndef ISLAND_H
# define ISLAND_H

# include <string.h>
# include <stdlib.h>

char	*read_line(int fd);
char	**read_map(int fd);
int		is_valid_map(char **map);
void	free_ptr_arr(void ***arr);

/*
** Tools
*/

char	*ft_strnew(size_t len);
void	*ft_memalloc(size_t size);
void	ft_memrealloc(void **mem, size_t old_len, size_t new_len);

#endif
