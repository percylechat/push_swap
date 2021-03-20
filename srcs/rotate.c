/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budal-bi <budal-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:53:35 by budal-bi          #+#    #+#             */
/*   Updated: 2021/03/20 18:55:56 by budal-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(t_pil *p)
{
	int		buf;
	int		i;

	i = 0;
	if (p->len_b < 3)
	{
		if (p->len_b == 2)
			swap(p, 1);
		return ;
	}
	buf = p->pile_b[i];
	while (i < p->len_b - 1)
	{
		p->pile_b[i] = p->pile_b[i + 1];
		i++;
	}
	p->pile_b[p->len_b - 1] = buf;
}

void	rotate_a(t_pil *p)
{
	int		buf;
	int		i;

	i = 0;
	if (p->len_a < 3)
	{
		if (p->len_a == 2)
			swap(p, 0);
		return ;
	}
	buf = p->pile_a[i];
	while (i < p->len_a - 1)
	{
		p->pile_a[i] = p->pile_a[i + 1];
		i++;
	}
	p->pile_a[p->len_a - 1] = buf;
}

void	rrotate_b(t_pil *p)
{
	int		buf;
	int		i;

	i = p->len_b - 1;
	if (p->len_b < 3)
	{
		if (p->len_b == 2)
			swap(p, 1);
		return ;
	}
	buf = p->pile_b[i];
	while (i > 0)
	{
		p->pile_b[i] = p->pile_b[i - 1];
		i--;
	}
	p->pile_b[0] = buf;
}

void	rrotate_a(t_pil *p)
{
	int		buf;
	int		i;

	i = p->len_a - 1;
	if (p->len_a < 3)
	{
		if (p->len_a == 2)
			swap(p, 0);
		return ;
	}
	buf = p->pile_a[i];
	while (i > 0)
	{
		p->pile_a[i] = p->pile_a[i - 1];
		i--;
	}
	p->pile_a[0] = buf;
}

int		dispatch_r(char *str, t_pil *p)
{
	if (str[1] == 'a' && str[2] == '\0')
		rotate_a(p);
	else if (str[1] == 'b' && str[2] == '\0')
		rotate_b(p);
	else if (str[1] == 'r' && str[2] == '\0')
	{
		rotate_a(p);
		rotate_b(p);
	}
	else if (str[1] == 'r' && str[2] == 'a' && str[3] == '\0')
		rrotate_a(p);
	else if (str[1] == 'r' && str[2] == 'b' && str[3] == '\0')
		rrotate_b(p);
	else if (str[1] == 'r' && str[2] == 'r' && str[3] == '\0')
	{
		rrotate_a(p);
		rrotate_b(p);
	}
	else
		return (-1);
	return (1);
}
