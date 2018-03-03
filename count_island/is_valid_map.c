#include "island.h"

static int	is_valid_line(char *line)
{
	int		is_valid;
	size_t	cnt;

	cnt = 0;
	is_valid = 0;
	while (line[cnt])
	{
		if (line[cnt] != '.' && line[cnt] != 'X')
			break ;
		++cnt;
	}
	if (!line[cnt] && cnt)
		is_valid = 1;
	return (is_valid);
}

int		is_valid_map(char **map)
{
	int		cnt;
	int		prev;
	int		cur;
	int		hv_len;
	int		hv_line;

	cnt = 0;
	prev = -1;
	hv_len = 0;
	hv_line = 0;
	while (map[cnt])
	{
		cur = strlen(map[cnt]);
		hv_line = is_valid_line(map[cnt]);
		if ((prev != -1 && prev != cur) || !hv_line)
			break ;
		prev = cur;
		++cnt;
	}
	if (!map[cnt] && cnt && hv_line)
		hv_len= 1;
	return (hv_len);
}
