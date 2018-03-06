#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "island.h"

void	count_island_hlp(char **map, int i, int j, int filler)
{
	if (i >= 0 && j >= 0 && map[i] && map[i][j])
	{
		if (map[i][j] == 'X')
		{
			map[i][j] = filler;
			count_island_hlp(map, i, j + 1, filler);
			count_island_hlp(map, i, j - 1, filler);
			count_island_hlp(map, i + 1, j, filler);
			count_island_hlp(map, i - 1, j, filler);
		}
	}
}

void	count_island(char **map)
{
	int		i;
	int		j;
	char	filler;

	i = 0;
	filler = '0';
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'X')
			{
				count_island_hlp(map, i, j, filler);
				++filler;
			}
			++j;
		}
		++i;
	}
}

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
	count_island(map);
	cnt = 0;
	printf("\n\n");
	while (map[cnt])
		printf("%s\n", map[cnt++]);
	free_ptr_arr((void ***)&map);
	return (0);
}
