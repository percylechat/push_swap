#include "push_swap.h"

void	push_a(t_pil *p)
{
	int er;

	er = 0;
	if (p->len_b == 0)
		return ;
	er = inc_pil_a(p);
	er = dec_pil_b(p);
}

void	push_b(t_pil *p)
{
	int er;

	er = 0;
	if (p->len_a == 0)
		return ;
	er = inc_pil_b(p);
	er = dec_pil_a(p);
}

int	dispatch_p(char *str, t_pil *p)
{
	if (str[1] == 'a' && str[2] == '\n')
		push_a(p);
	else if (str[1] == 'b' && str[2] == '\n')
		push_b(p);
	else
		return (-1);
	return (1);
}