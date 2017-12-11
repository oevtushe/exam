#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	get_hex(int nb)
{
	if (nb < 10)
		return (nb + '0');
	else
	{
		nb -= 10;
		return (nb + 'a');
	}
}

void	put_hex_loop(int nb, int *vals, int *idx)
{
	char	frst;
	char	scd;
	int		i;

	i = 0;
	while (nb > 0)
	{
		frst = get_hex(nb % 16);
		scd = get_hex((nb /= 16) % 16);
		vals[(*idx)++] = (scd > '9' ? ((scd + 10) - 'a') * 16 :
			(scd - '0') * 16) + (frst > '9' ? (frst + 10) - 'a' : (frst - '0'));
		ft_putchar(scd);
		ft_putchar(frst);
		if ((i += 2) == 4)
			ft_putchar(' ');
		nb /= 16;
	}
	while (i < 8)
	{
		ft_putchar('0');
		ft_putchar('0');
		vals[(*idx)++] = 0;
		if ((i += 2) == 4)
			ft_putchar(' ');
	}
}

void	print_dots(int *vals, int *idx)
{
	int j;
	
	ft_putchar(' ');
	j = -1;
	while (++j < *idx)
	{
		if (vals[j] >= 32 && vals[j] <= 127)
			ft_putchar(vals[j]);
		else
			ft_putchar('.');
	}
	ft_putchar('\n');
	*idx = 0;
}

void	print_memory(int *tab, int size)
{
	int i;
	int j;
	int	vals[16];
	int idx;

	i = 0;
	idx = 0;
	size /= sizeof(int);
	while (++i <= size)
	{
		put_hex_loop(tab[i - 1], vals, &idx);
		if (i != size && i % 4 == 0)
			print_dots(vals, &idx);
		else if (i != size)
			ft_putchar(' ');
	}
	i--;
	while (i++ % 4 != 0)
	{
		j = -1;
		while (++j < 10)
			ft_putchar(' ');
	}
	print_dots(vals, &idx);
}

int		main(void)
{
	int	tab[1] = {43245622};
	print_memory(tab, sizeof(tab));
	return (0);

