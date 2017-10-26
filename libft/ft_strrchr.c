/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiodier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:15:02 by afiodier          #+#    #+#             */
/*   Updated: 2016/11/08 17:16:38 by afiodier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char*)s;
	while (dest[i] != 0)
		i++;
	while (dest[i] != c)
	{
		if (i == 0)
			return (0);
		i--;
	}
	return (&dest[i]);
}
