#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "island.h"

int		main(int argc, char **argv)
{
	int fd;
	int	cnt;
	char **map;

	if (argc != 2)
		return (1);
	cnt = 0;
	fd = open(argv[1], O_RDONLY);
	map = read_map(fd);
	while (map[cnt])
		printf("%s\n", map[cnt++]);
	free_ptr_arr((void ***)&map);
	return (0);
}
