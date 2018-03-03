#include "island.h"

void	free_ptr_arr(void ***arr)
{
	size_t cnt;

	cnt = 0;
	if (arr && *arr)
	{
		while ((*arr)[cnt])
			free((*arr)[cnt++]);
		free(*arr);
	}
}
