/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiodier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:13:49 by afiodier          #+#    #+#             */
/*   Updated: 2016/11/08 17:16:06 by afiodier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*dest;

	i = 0;
	if (s)
	{
		if (!(dest = ft_strnew(ft_strlen(s))))
			return (0);
		while (s[i] != 0)
		{
			dest[i] = f((char)s[i]);
			i++;
		}
		dest[i] = 0;
		return (dest);
	}
	return (NULL);
}
