/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budal-bi <budal-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:33:17 by budal-bi          #+#    #+#             */
/*   Updated: 2020/02/04 15:45:10 by budal-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*dest;

	i = ft_chrlen_gnl(s1, '\0') + ft_chrlen_gnl(s2, '\0');
	j = 0;
	k = 0;
	if (!(dest = malloc(sizeof(char) * i + 1)))
		return (NULL);
	while (s1[j])
	{
		dest[j] = s1[j];
		j++;
	}
	while (s2[k])
		dest[j++] = s2[k++];
	dest[j] = '\0';
	return (dest);
}

char	*ft_strdup_gnl(const char *src)
{
	char	*dest;
	int		j;
	int		i;

	i = 0;
	if (!src)
	{
		dest = malloc(1);
		dest[0] = '\0';
		return (dest);
	}
	else
		j = ft_chrlen_gnl(src, '\0');
	if (!(dest = malloc(sizeof(char) * (j + 1))))
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_chrlen_gnl(const char *s, char c)
{
	int		i;

	i = 0;
	if (!s || s == NULL)
		return (-1);
	if (c == '\0')
	{
		while (s[i])
			i++;
		return (i);
	}
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_substr_gnl(char const *s, int start, int len)
{
	int		i;
	int		l;
	char	*dest;

	i = (s) ? ft_chrlen_gnl(s, '\0') : 0;
	l = 0;
	if (!s || start > i)
	{
		if (!(dest = malloc(1)))
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while ((l < len) && s[start])
		dest[l++] = s[start++];
	dest[l] = '\0';
	return (dest);
}

char	*new_buffer(char *buffer, char *reste)
{
	char *temp;

	if (reste[0] != '\0')
	{
		temp = ft_strdup_gnl(buffer);
		free(buffer);
		buffer = ft_strjoin_gnl(reste, temp);
		free(temp);
		reste[0] = '\0';
	}
	return (buffer);
}
