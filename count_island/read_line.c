#include <unistd.h>
#include "island.h"

char	*read_line(int fd)
{
	int		pos;
	char	c;
	int		buff_size;
	char	*buffer;

	pos = 0;
	buff_size = 100;
	buffer = ft_strnew(buff_size);
	while (read(fd, &c, 1) > 0 && c != '\n')
	{
		if (pos >= buff_size)
		{
			ft_memrealloc((void **)&buffer, buff_size, (buff_size * 2) + 1);
			buff_size *= 2;
		}
		buffer[pos++] = c;
	}
	if (pos < buff_size)
		ft_memrealloc((void **)&buffer, pos, pos + 1);
	return (buffer);
}
