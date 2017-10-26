/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiodier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:15:07 by afiodier          #+#    #+#             */
/*   Updated: 2016/11/08 17:16:41 by afiodier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *meule_de_foin, const char *aiguille)
{
	int		i;
	int		c;
	char	*dest;

	i = 0;
	dest = (char*)meule_de_foin;
	if (aiguille[i] == 0)
		return (dest);
	while (dest[i] != '\0')
	{
		c = 0;
		while (dest[c + i] == aiguille[c])
		{
			c++;
			if (aiguille[c] == '\0')
				return (&dest[i]);
		}
		i++;
	}
	return (0);
}
