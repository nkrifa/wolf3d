/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiodier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:24:50 by afiodier          #+#    #+#             */
/*   Updated: 2016/11/08 16:24:53 by afiodier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		*ft_if_numbers(const char *str, int *tab)
{
	while (str[tab[0]] >= 9 && str[tab[0]] <= 13)
		tab[0]++;
	if (str[tab[0]] >= '0' && str[tab[0]] <= '9')
	{
		tab[1] = tab[1] * 10;
		tab[1] = tab[1] + (str[tab[0]] - '0') * tab[4];
		tab[3] = 1;
	}
	return (tab);
}

int				ft_atoi(const char *str)
{
	int tab[5];

	tab[1] = 0;
	tab[3] = 0;
	tab[0] = 0;
	tab[4] = 1;
	tab[2] = ft_strlen(str);
	while (tab[0] <= tab[2])
	{
		ft_if_numbers(str, tab);
		if ((str[tab[0]] == '-' || str[tab[0]] == '+') && tab[3] == 0)
		{
			if (str[tab[0]] == '-')
				tab[4] = -1;
			tab[3] = 1;
		}
		else if (((str[tab[0]] < '0' || str[tab[0]] > '9')
			&& str[tab[0]] != ' ') ||
			(str[tab[0]] == '-' && tab[3] == 0) ||
			(str[tab[0]] == ' ' && tab[3] == 1))
			tab[0] = tab[2];
		tab[0]++;
	}
	return (tab[1]);
}
