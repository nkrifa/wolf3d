/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <nkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:17:35 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/30 02:28:41 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_encoder(t_env *e, int xx, int yy, char *tab)
{
	int		y;
	int		x;

	y = -1;
	if (!(e->map.tab = (int**)malloc(sizeof(int*)
		* (yy + 1))))
		exit(0);
	while (++y < yy && (x = -1))
	{
		if (!(e->map.tab[(int)y] = (int*)malloc(sizeof(int)
			* xx + 1)))
			exit(0);
		while (++x < xx)
		{
			if (y == yy - 1 || y == 0 || x == 0 || x == xx - 1)
				e->map.tab[y][x] = 1;
			else
				e->map.tab[y][x] = tab[((int)y * xx + (int)x)] - 48;
		}
	}
	free(tab);
}

char	*ft_strjoin1(char **s1, char *s2)
{
	char	*dest;
	int		ss1;
	int		ss2;

	ss1 = ft_strlen(*s1);
	ss2 = ft_strlen(s2);
	if (*s1 && s2)
	{
		dest = ft_strnew(ss1 + ss2 + 1);
		if (!dest)
			return (NULL);
		ft_strcpy(dest, *s1);
		ft_strcpy(&dest[ss1], s2);
		free(*s1);
		return (dest);
	}
	return (NULL);
}

void	ft_parcing(t_env *e, int fd)
{
	char	*laligne;
	char	*line;
	int		i;
	int		x;
	int		y;

	y = 0;
	x = 0;
	(fd > 0) ? 0 : exit(write(2, "bad namefile\n", 13));
	laligne = ft_strnew(1);
	line = NULL;
	while (get_next_line(fd, &line) && !(i = 0))
	{
		laligne = ft_strjoin1(&laligne, line);
		if (++y <= 1)
			while (line[x] != '\0')
				x++;
		free(line);
	}
	i = ft_strlen(laligne);
	(i != (y * x) && i < 9) ? exit(write(1, "yolo", 4))
		: ft_encoder(e, x, y, laligne);
	close(fd);
}
