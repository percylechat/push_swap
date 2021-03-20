/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budal-bi <budal-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:03:08 by budal-bi          #+#    #+#             */
/*   Updated: 2021/03/19 20:03:42 by budal-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_small(t_pil *p)
{
	if (p->len_a == 2 && p->pile_a[0] > p->pile_a[1])
		write(1, "sa\n", 3);
}

int		check_solved(t_pil *p)
{
	int i;

	i = 0;
	while (i < p->len_a - 1)
	{
		if (p->pile_a[i] > p->pile_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_solver(int *pile_a, int i)
{
	t_pil p[2];

	start_piles(p, pile_a, i);
	if (check_solved(p) == 1)
		return ;
	if (i < 4)
		solve_small(p);
}

int		main(int argc, char *argv[])
{
	int i;
	int *pile_a;

	i = 1;
	if (argc == 1)
		return (-1);
	if (!(pile_a = malloc(sizeof(int) * argc - 1)))
		return (ft_error("Error\n"));
	while (i < argc)
	{
		if (ft_isdigit_complete(argv[i]) == 0)
			return (ft_error_free("Error\n", pile_a));
		else if (check_size(argv[i]) == -1)
			return (ft_error_free("Error\n", pile_a));
		pile_a[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	i--;
	if (ft_check_doubles(pile_a, i) == -1)
		return (ft_error_free("Error\n", pile_a));
	ft_solver(pile_a, i);
}
