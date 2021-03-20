/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budal-bi <budal-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:04:03 by budal-bi          #+#    #+#             */
/*   Updated: 2021/03/20 19:02:58 by budal-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push_a(t_pil *p)
{
	int er;

	er = 0;
	if (p->len_b == 0)
		return (1);
	er = inc_pil_a(p);
	er += dec_pil_b(p);
	if (er != 2)
		return (ft_error_free_st("Error\n", p));
	return (1);
}

int		push_b(t_pil *p)
{
	int er;

	er = 0;
	if (p->len_a == 0)
		return (1);
	er = inc_pil_b(p);
	er = dec_pil_a(p);
	if (er != 2)
		return (ft_error_free_st("Error\n", p));
	return (1);
}

int		dispatch_p(char *str, t_pil *p)
{
	int i;

	i = 0;
	if (str[1] == 'a' && str[2] == '\0')
		i = push_a(p);
	else if (str[1] == 'b' && str[2] == '\0')
		i += push_b(p);
	else
		return (-1);
	return (i);
}
