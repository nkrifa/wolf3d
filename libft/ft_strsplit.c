/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiodier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:34:24 by afiodier          #+#    #+#             */
/*   Updated: 2016/11/10 19:34:27 by afiodier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strcpy_s(char *src, int lettre)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(dest = (char *)malloc(sizeof(char) + (lettre + 1))))
		return (NULL);
	while (i < lettre)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static	int		ft_nbmot(char *s, char c)
{
	int		i;
	int		nbmot;

	i = 0;
	nbmot = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			nbmot++;
		if (!(s[i - 1] != c) && (s[i] != c) && i != 0)
			nbmot++;
		i++;
	}
	return (nbmot);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nbmot;
	int		i;
	int		lettre;

	if (!(s && (tab = (char**)malloc(sizeof(char*)
	* ft_nbmot((char*)s, c) + 1))))
		return (NULL);
	nbmot = 0;
	i = -1;
	while (s[++i])
	{
		if ((i == 0 && (s[i] != c))
			|| (!(s[i - 1] != c) && (s[i] != c) && s[i] != 0))
		{
			lettre = 0;
			while ((s[i + lettre] != c) && s[i + lettre] != 0)
				lettre++;
			if (!(tab[nbmot] = (char *)malloc(sizeof(char) * (lettre + 1))))
				return (NULL);
			tab[nbmot++] = ft_strcpy_s((char*)s + i, lettre);
		}
	}
	tab[ft_nbmot((char*)s, c)] = 0;
	return (tab);
}
