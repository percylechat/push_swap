/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budal-bi <budal-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:50:54 by budal-bi          #+#    #+#             */
/*   Updated: 2021/03/20 18:51:45 by budal-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pil *p, int c)
{
	int buf;

	if (c == 0 || c == 2)
	{
		if (p->len_a < 2 && c == 0)
			return ;
		else if (p->len_a < 2 && c == 2)
			c = 1;
		buf = p->pile_a[1];
		p->pile_a[1] = p->pile_a[0];
		p->pile_a[0] = buf;
	}
	else if (c == 1 || c == 2)
	{
		if (p->len_b < 2)
			return ;
		buf = p->pile_b[1];
		p->pile_b[1] = p->pile_b[0];
		p->pile_b[0] = buf;
	}
}

int		dispatch_s(char *str, t_pil *p)
{
	if (str[1] == 'a' && str[2] == '\0')
		swap(p, 0);
	else if (str[1] == 'b' && str[2] == '\0')
		swap(p, 1);
	else if (str[1] == 's' && str[2] == '\0')
		swap(p, 2);
	else
		return (-1);
	return (1);
}
