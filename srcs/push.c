/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budal-bi <budal-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:11:50 by budal-bi          #+#    #+#             */
/*   Updated: 2021/03/19 20:12:22 by budal-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**Prep error handling if malloc
*/

int	inc_pil_a(t_pil *p)
{
	int *buf;
	int i;

	i = 0;
	if (!(buf = malloc(sizeof(int) * p->len_a)))
		return (-1);
	while (i < p->len_a)
	{
		buf[i] = p->pile_a[i];
		i++;
	}
	free(p->pile_a);
	if (!(p->pile_a = malloc(sizeof(int) * p->len_a + 1)))
		return (-1);
	i = 0;
	p->pile_a[i] = p->pile_b[i];
	i++;
	while (i != p->len_a)
	{
		p->pile_a[i] = buf[i - 1];
		i++;
	}
	p->len_a++;
	free(buf);
	return (1);
}

int	inc_pil_b(t_pil *p)
{
	int *buf;
	int i;

	i = 0;
	if (!(buf = malloc(sizeof(int) * p->len_b)))
		return (-1);
	while (i < p->len_b)
	{
		buf[i] = p->pile_b[i];
		i++;
	}
	free(p->pile_b);
	if (!(p->pile_b = malloc(sizeof(int) * p->len_b + 1)))
		return (-1);
	i = 0;
	p->pile_b[i] = p->pile_a[i];
	i++;
	while (i != p->len_b)
	{
		p->pile_b[i] = buf[i - 1];
		i++;
	}
	p->len_b++;
	free(buf);
	return (1);
}

int	dec_pil_b(t_pil *p)
{
	int *buf;
	int i;

	i = 0;
	if (!(buf = malloc(sizeof(int) * p->len_b)))
		return (-1);
	while (i < p->len_b)
	{
		buf[i] = p->pile_b[i];
		i++;
	}
	free(p->pile_b);
	if (!(p->pile_b = malloc(sizeof(int) * p->len_b - 1)))
		return (-1);
	i = 0;
	while (i < p->len_b - 1)
	{
		p->pile_b[i] = buf[i + 1];
		i++;
	}
	p->len_b--;
	free(buf);
	return (1);
}

int	dec_pil_a(t_pil *p)
{
	int *buf;
	int i;

	i = 0;
	if (!(buf = malloc(sizeof(int) * p->len_a)))
		return (-1);
	while (i < p->len_a)
	{
		buf[i] = p->pile_a[i];
		i++;
	}
	free(p->pile_a);
	if (!(p->pile_a = malloc(sizeof(int) * p->len_a - 1)))
		return (-1);
	i = 0;
	while (i < p->len_a - 1)
	{
		p->pile_a[i] = buf[i + 1];
		i++;
	}
	p->len_a--;
	free(buf);
	return (1);
}
