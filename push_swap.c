#include "push_swap.h"

int	dispatch(char *str, t_pil *p)
{
	int i;

	i = 0;
	write(1, "bebe", 4);
	printf("str:%s\n", str);
	if (str[0] == 's')
		i = dispatch_s(str, p);
	else if (str[0] == 'r')
		i = dispatch_r(str, p);
	else if (str[0] == 'p')
		i = dispatch_p(str, p);
	else
		i = -1;
	if (i == -1)
		i = ft_error_free_st("Error: Unknown command\n", p);
	return (i);
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

	i = 0;
	while (i < p->len_a)
		printf("spot:%d nb:%d\n", i, p->pile_a[i++]);
}

void	ft_checker(int *pile_a, int len_a)
{
	// char *line;
	char *line = "rra\n";
	t_pil p[2];
	int res;

	start_piles(p, pile_a, len_a);
	// while (get_next_line(&line) > 0)
	// {
		// res = get_next_line(&line);
		// printf("gnl:%s %d", line, res);
		print_pile(p);
		if (dispatch(line, p) == -1)
			return ;
		print_pile(p);
	// }
}


int    main(int argc, char *argv[])
{
    int i;
    int *pile_a;
    int buf;

    i = 1;
    if (argc == 1)
        return (-1);
    if (!(pile_a = malloc(sizeof(int) * argc - 1)))
        return (ft_error("Error: no space for memory allocation\n"));
    while (i < argc)
    {
        if (ft_isdigit_complete(argv[i]) == 0)
            return (ft_error("Error: all arguments must be integrers\n"));
        else if (check_size(argv[i]) == -1)
            return (ft_error("Error: arguments must fit into integrers\n"));
        pile_a[i - 1] = ft_atoi(argv[i]);
        i++;
    }
	i--;
    ft_checker(pile_a, i);
}