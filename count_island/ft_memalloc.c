#include "island.h"

void	*ft_memalloc(size_t size)
{
	size_t			cnt;
	unsigned char	*mem;

	cnt = 0;
	mem = (void *)0;
	if (size)
	{
		mem = (unsigned char *)malloc(size);
		if (mem)
		{
			while (cnt < size)
				mem[cnt++] = 0;
		}
	}
	return (mem);
}
