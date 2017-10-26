/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiodier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:00:49 by afiodier          #+#    #+#             */
/*   Updated: 2017/01/07 15:00:51 by afiodier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_if_n(char *dest)
{
	int				i;

	i = -1;
	while (++i <= BUFF_SIZE)
	{
		if (dest[i] == '\n')
			return (i);
	}
	return (BUFF_SIZE);
}

static char		*ft_strnjoin(char *s1, char *s2, int n)
{
	char			*dest;
	int				ss1;

	ss1 = ft_strlen(s1);
	dest = ft_strnew(ss1 + n);
	if (!dest)
		return (NULL);
	ft_strcpy(dest, s1);
	ft_strncpy(&dest[ss1], s2, n);
	ft_bzero(s1, ss1 + 1);
	free(s1);
	return (dest);
}

static int		ft_previously(t_gnl *point, char **line)
{
	int				start;
	int				end;

	if (point->buff[0])
	{
		start = ft_if_n(point->buff);
		end = ft_if_n(&point->buff[start + 1]);
		*line = ft_strnjoin(*line, &point->buff[start + 1], end);
		if (start + end < (int)ft_strlen(point->buff) - 1)
		{
			point->buff[start] = 'a';
			return (1);
		}
		return (0);
	}
	return (0);
}

static int		ft_reading(t_gnl *point, char **line)
{
	int				k;
	int				i;
	int				n;

	n = 0;
	k = 1;
	i = 0;
	*line = ft_strnew(0);
	if (ft_previously(point, line))
		return (1);
	while (1)
	{
		ft_bzero(point->buff, BUFF_SIZE + 1);
		k = read(point->fd, point->buff, BUFF_SIZE);
		if (k <= 0 && (int)ft_strlen(*line) == 0)
			return (k == -1 ? -1 : 0);
		else if (k <= 0 && (int)ft_strlen(*line) != 0)
			return (1);
		n = ft_if_n(point->buff);
		*line = ft_strnjoin(*line, point->buff, n);
		if (n < k)
			return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static	t_gnl	*first = 0;
	t_gnl			*point;

	if (!line || fd < 0)
		return (-1);
	if (first == NULL)
	{
		if (!(first = (t_gnl*)malloc(sizeof(struct s_gnl))))
			return (0);
		first->fd = fd;
		first->next = NULL;
	}
	point = first;
	while (point->fd != fd)
	{
		if (point->next == NULL)
		{
			if (!(point->next = (t_gnl*)malloc(sizeof(struct s_gnl))))
				return (0);
			point->next->next = NULL;
			point->next->fd = fd;
		}
		point = point->next;
	}
	return (ft_reading(point, line));
}
