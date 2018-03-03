#include "island.h"

char	**read_map(int fd)
{
	char	**map;
	int		ms;
	int		cnt;
	char	*tmp;
	size_t	sc;

	ms = 10;
	cnt = 0;
	sc = sizeof(char *);
	map = (char **)ft_memalloc((ms * sc) + sc);
	while ((tmp = read_line(fd))[0] != '\0')
	{
		if (cnt >= ms)
		{
			ft_memrealloc((void **)&map, ms * sc, (ms * sc * 2) + sc);
			ms *= 2;
		}
		map[cnt++] = tmp;
	}
	if (cnt < ms)
		ft_memrealloc((void **)&map, cnt * sc, (cnt + 1) * sc);
	free(tmp);
	return (map);
}
