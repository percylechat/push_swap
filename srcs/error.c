/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budal-bi <budal-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:53:07 by budal-bi          #+#    #+#             */
/*   Updated: 2021/03/20 19:01:05 by budal-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (-1);
}

int		ft_error_free(char *str, int *pile)
{
	write(2, str, ft_strlen(str));
	free(pile);
	return (-1);
}

int		ft_error_free_st(char *str, t_pil *p)
{
	write(2, str, ft_strlen(str));
	free(p->pile_a);
	free(p->pile_b);
	return (-1);
}

int		ft_isdigit_complete(char *str)
{
	int	j;
	int	res;

	j = 0;
	res = 0;
	while (str[j])
	{
		res += ft_isdigit(str[j]);
		j++;
	}
	return (res);
}

int		check_size(char *str)
{
	if (str[0] != '-' && ft_strlen(str) > 10)
		return (-1);
	if (str[0] == '-' && ft_strlen(str) > 11)
		return (-1);
	if (str[0] != '-' && ft_strlen(str) == 10)
	{
		if (ft_strcmp(str, "2147483647") > 0)
			return (-1);
	}
	if (str[0] == '-' && ft_strlen(str) == 11)
	{
		if (ft_strcmp(str, "-2147483647") > 0)
			return (-1);
	}
	return (1);
}
