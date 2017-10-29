void	ft_encoder(t_env *meta, int xx, int yy, char *tab)
{
	double	y;
	double	x;

	y = -1;
	tab = ft_strsplit(meta->line, ' ');
	if (!(meta->map.tab = (t_data**)malloc(sizeof(t_data)
		* (yy + 1))))
		exit(0);
	while (++y < yy && (x = -1))
	{
		if (!(meta->map.tab[(int)y] = (t_data*)malloc(sizeof(t_data)
			* xx + 1)))
			exit(0);
		while (++x < xx)
			meta->map.tab[y][x] = (double)ft_atoi(tab[((int)y * xx + (int)x)]);
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
		ft_strcpy(&dest[ss1 + ss2], " ");
		free(*s1);
		free(s2);
		return (dest);
	}
	return (NULL);
}

void	ft_partcing(t_env *e, int fd)
{
	char	*line;
	char	**tab;
	char *laligne;
	int		temp;
	int		i;
	int x;
	int y;

	y = 0;
	i = 0;
	laligne = ft_strnew(1);
	line = NULL;
	while (get_next_line(fd, &line) && !(temp = 0))
	{
		laligne = ft_strjoin1(&laligne, line);
		if (++y <= 1)
		{
			tab = ft_strsplit(line, ' ');
			x = 0;
			while (*tab++ != '\0')
				x++;
		}
	}
	while (laligne[i++] != '\0')
		if (laligne[i] != laligne[i + 1])
			laligne[i] == ' ' ? temp++ : 0;
	temp != (y * x) ? exit(write(1, NORME, 30))
	: ft_encoder(e, x, y, laligne);
}
