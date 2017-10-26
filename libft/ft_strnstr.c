/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiodier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:14:57 by afiodier          #+#    #+#             */
/*   Updated: 2016/11/08 17:16:18 by afiodier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *here, const char *find, size_t len)
{
	int		i;
	int		c;
	char	*dest;

	i = 0;
	dest = (char*)here;
	if (find[i] == 0)
		return (dest);
	while (dest[i] != '\0')
	{
		c = 0;
		while (dest[c + i] == find[c] && i < (int)len)
		{
			c++;
			if (c == (int)ft_strlen(find))
			{
				if (c + i <= (int)len)
					return (&dest[i]);
				else
					return (NULL);
			}
		}
		i++;
	}
	return (0);
}
