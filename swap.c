#include "push_swap.h"

int swap(t_pil *p, int c)
{
    int buf;

	write(1, "job", 3);
	if (c == 0 || c == 2)
    {
		if (p->len_a < 2 && c == 0)
        	return (-1);
		else if (p->len_a < 2 && c == 2)
			c = 1;
		buf = p->pile_a[1];
		printf("buf:%d", buf);
		p->pile_a[1] = p->pile_a[0];
		p->pile_a[0] = buf;
	}
	else if (c == 1 || c == 2)
    {
		if (p->len_b < 2)
        	return (-1);
		buf = p->pile_b[1];
		p->pile_b[1] = p->pile_b[0];
		p->pile_b[0] = buf;
	}
    return (1);
}

int	dispatch_s(char *str, t_pil *p)
{
	int i;

	i = 0;
	write(1, "vv", 2);
	// printf("char:%c\n", str[1])
	if (str[1] == 'a' && str[2] == '\n')
		swap(p, 0);
	else if (str[1] == 'b' && str[2] == '\n')
		swap(p, 1);
	else if (str[1] == 's' && str[2] == '\n')
		swap(p, 2);	
	else
		return (-1);
	return (1);
}