/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiodier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:13:12 by afiodier          #+#    #+#             */
/*   Updated: 2016/11/08 17:15:54 by afiodier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*des;
	int		i;

	if (!(des = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1))))
		return (0);
	i = -1;
	while (s[++i])
		des[i] = s[i];
	des[i] = 0;
	return (des);
}
