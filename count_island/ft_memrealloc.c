#include "island.h"

void	ft_memrealloc(void **mem, size_t old_size, size_t new_size)
{
	size_t			cnt;
	unsigned char	*ma;

	cnt = 0;
	ma = (unsigned char *)ft_memalloc(new_size);
	if (ma)
	{
		while (cnt < old_size && cnt < new_size)
		{
			ma[cnt] = (*((unsigned char **)mem))[cnt];
			++cnt;
		}
		free(*mem);
		*mem = ma;
	}
}
