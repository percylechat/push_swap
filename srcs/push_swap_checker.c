/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budal-bi <budal-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 19:57:11 by budal-bi          #+#    #+#             */
/*   Updated: 2021/03/19 20:01:53 by budal-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**WARNING GNL leak: reste not free?
*/

int		dispatch(char *str, t_pil *p)
{
	int		i;

	i = 0;
	if (str[0] == 's')
		i = dispatch_s(str, p);
	else if (str[0] == 'r')
		i = dispatch_r(str, p);
	else if (str[0] == 'p')
		i = dispatch_p(str, p);
	else
		i = -1;
	if (i == -1)
		i = ft_error_free_st("Error\n", p);
	return (i);
}

void	ft_checker(int *pile_a, int len_a)
{
	char	*line;
	t_pil	p[2];
	int		res;
	int		i;

	i = 1;
	start_piles(p, pile_a, len_a);
	if (check_is_ordered(p, 0) == 1)
		return ;
	while (i == 1)
	{
		if ((res = get_next_line(0, &line)) != -1)
		{
			print_pile(p);
			if (dispatch(line, p) == -1)
				return ;
			free(line);
			check_is_ordered(p, 1);
		}
	}
}

int		check_same(int j, int *pile_a)
{
	int		k;

	k = 0;
	while (k < j)
	{
		if (pile_a[k] == pile_a[j])
			return (1);
		k++;
	}
	return (0);
}

int		ft_check_doubles(int *pile_a, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		if (check_same(j, pile_a) == 1)
			return (-1);
		j++;
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	int		i;
	int		*pile_a;

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
	ft_checker(pile_a, i);
}
