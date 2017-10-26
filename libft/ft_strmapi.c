/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiodier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:14:26 by afiodier          #+#    #+#             */
/*   Updated: 2016/11/08 17:16:07 by afiodier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	i = 0;
	if (s)
	{
		if (!(dest = ft_strnew(ft_strlen(s))))
			return (NULL);
		while (s[i] != 0)
		{
			dest[i] = f(i, (char)s[i]);
			i++;
		}
		dest[i] = 0;
		return (dest);
	}
	return (NULL);
}
