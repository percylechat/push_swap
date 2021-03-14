#include "push_swap.h"

int	inc_pil_a(t_pil *p)
{
	int *buf;
	int i;

	i = 0;
	if (!(buf = malloc(sizeof(int) * p->len_a)))
		return (-1);
	while (i < p->len_a)
		buf[i] = p->pile_a[i++];
	free(p->pile_a);
	if (!(p->pile_a = malloc(sizeof(int) * p->len_a + 1)))
		return (-1);
	i = 0;
	p->pile_a[i] = p->pile_b[i++];
	while (i != p->len_a)
		p->pile_a[i] = buf[i - 1];
	p->len_a++;
	free(buf);
}

int	inc_pil_b(t_pil *p)
{
	int *buf;
	int i;

	i = 0;
	if (!(buf = malloc(sizeof(int) * p->len_b)))
		return (-1);
	while (i < p->len_b)
		buf[i] = p->pile_b[i++];
	free(p->pile_b);
	if (!(p->pile_b = malloc(sizeof(int) * p->len_b + 1)))
		return (-1);
	i = 0;
	p->pile_b[i] = p->pile_a[i++];
	while (i != p->len_b)
		p->pile_b[i] = buf[i - 1];
	p->len_b++;
	free(buf);
}

int	dec_pil_b(t_pil *p)
{
	int *buf;
	int i;

	i = 0;
	if (!(buf = malloc(sizeof(int) * p->len_b)))
		return (-1);
	while (i < p->len_b)
		buf[i] = p->pile_b[i++];
	free(p->pile_b);
	if (!(p->pile_b = malloc(sizeof(int) * p->len_b - 1)))
		return (-1);
	i = 0;
	while (i < p->len_b - 1)
		p->pile_b[i] = buf[i + 1];
	p->len_b--;
	free(buf);
}

int	dec_pil_a(t_pil *p)
{
	int *buf;
	int i;

	i = 0;
	if (!(buf = malloc(sizeof(int) * p->len_a)))
		return (-1);
	while (i < p->len_a)
		buf[i] = p->pile_a[i++];
	free(p->pile_a);
	if (!(p->pile_a = malloc(sizeof(int) * p->len_a - 1)))
		return (-1);
	i = 0;
	while (i < p->len_a - 1)
		p->pile_a[i] = buf[i + 1];
	p->len_a--;
	free(buf);
}