/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budal-bi <budal-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:33:29 by budal-bi          #+#    #+#             */
/*   Updated: 2020/02/06 16:32:05 by budal-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_run(char *reste, char *buffer, char **line)
{
	int		bs;
	char	*temp;
	char	*sub;

	bs = ft_chrlen_gnl(buffer, '\n');
	free(reste);
	if (bs == 0)
	{
		reste = ft_substr_gnl(buffer, bs + 1, (ft_chrlen_gnl(&buffer[bs + 1], '\0')));
		if (!(*line = malloc(1)))
			return (NULL);
		*line[0] = '\0';
	}
	else if (bs != -1 && bs != 0)
	{
		reste = ft_substr_gnl(buffer, bs + 1, (ft_chrlen_gnl(&buffer[bs + 1], '\0')));
		temp = ft_strdup_gnl(*line);
		sub = ft_substr_gnl(buffer, 0, bs);
		*line = ft_strjoin_gnl(temp, sub);
		free(temp);
		free(sub);
	}
	else
		reste = ft_strdup_gnl(buffer);
	return (reste);
}

char	*ulti_run(char *reste, char **line, int bs)
{
	char	*temp;
	char	*temp1;

	temp = ft_strdup_gnl(*line);
	temp1 = ft_substr_gnl(reste, 0, bs);
	free(*line);
	*line = ft_strjoin_gnl(temp, temp1);
	free(temp);
	temp = ft_substr_gnl(reste, bs + 1, (ft_chrlen_gnl(&reste[bs + 1], '\0')));
	free(reste);
	reste = ft_strdup_gnl(temp);
	free(temp1);
	free(temp);
	return (reste);
}

char	*ft_run_end(char *reste, char **line)
{
	int		bs;
	char	*temp;

	bs = ft_chrlen_gnl(reste, '\n');
	if (bs == 0)
	{
		temp = ft_substr_gnl(reste, bs + 1, (ft_chrlen_gnl(&reste[bs + 1], '\0')));
		free(reste);
		reste = ft_strdup_gnl(temp);
		*line = malloc(1);
		*line[0] = '\0';
		free(temp);
	}
	else if (bs != -1 && bs != 0)
		reste = ulti_run(reste, line, bs);
	else
	{
		temp = ft_strdup_gnl(*line);
		free(*line);
		*line = ft_strjoin_gnl(temp, reste);
		free(reste);
		reste = NULL;
		free(temp);
	}
	return (reste);
}

char	*ft_check_reste(char *reste)
{
	if (!reste)
	{
		reste = malloc(1);
		reste[0] = '\0';
	}
	return (reste);
}

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	int			res;
	static char	*reste = NULL;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !(read(fd, reste, 0) == 0) ||
		!(buffer = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	*line = NULL;
	reste = ft_check_reste(reste);
	while ((res = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[res] = '\0';
		buffer = new_buffer(buffer, reste);
		reste = ft_run(reste, buffer, line);
		if (ft_chrlen_gnl(buffer, '\n') != -1)
		{
			free(buffer);
			return (1);
		}
	}
	free(buffer);
	while ((reste = ft_run_end(reste, line)) != NULL)
		return (1);
	free(reste);
	return (0);
}
