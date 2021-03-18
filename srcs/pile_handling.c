#include "push_swap.h"

int	ft_ko(t_pil *p, int c)
{
	if (c == 0)
		return (0);
	write(1, "KO\n", 3);
	free(p->pile_a);
	if (p->len_b > 0)
		free(p->pile_b);
	return (-1);
}

int	check_is_ordered(t_pil *p, int c)
{
	int i;

	i = 0;
	if (p->len_b > 0)
		return (ft_ko(p, c));
	while (i < p->len_a - 1)
	{
		if (p->pile_a[i] > p->pile_a[i + 1])
			return (ft_ko(p, c));
		i++;
	}
	write(1, "OK\n", 3);
	free(p->pile_a);
	return (1);
}

void	start_piles(t_pil *p, int *pile_a, int len_a)
{
	int i;

	i = 0;
	p->len_a = len_a;
	p->len_b = 0;
	p->pile_b = NULL;
	if (!(p->pile_a = malloc(sizeof(int) * p->len_a)))
		return ;
	while (i < p->len_a)
	{
		p->pile_a[i] = pile_a[i];
		i++;
	}
	free(pile_a);
}

void	print_pile(t_pil *p)
{
	int i;
	char *res;

	i = 0;
	while (i < p->len_a)
	{
		res = ft_itoa(i);
		write(1, "\nspot: ", 7);
		write(1, &res, ft_strlen(res));
		free (res);
		write(1, " nb_a: ", 7);
		res = ft_itoa(p->pile_a[i]);
		write(1, &res , ft_strlen(res));
		free (res);
		i++;
	}
	i = 0;
	while (i < p->len_b)
	{
		write(1, "\nspot: ", 7);
		res = ft_itoa(i);
		write(1, &res, ft_strlen(res));
		free (res);
		write(1, " nb_b: ", 7);
		res = ft_itoa(p->pile_b[i]);
		write(1, &res, ft_strlen(res));
		free (res);
		i++;
	}
		// printf("spot:%d nb:%d\n", i, p->pile_a[i++]);
}
