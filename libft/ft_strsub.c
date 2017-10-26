/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiodier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:15:16 by afiodier          #+#    #+#             */
/*   Updated: 2016/11/08 17:16:42 by afiodier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *dest;

	if (s)
	{
		if (!(dest = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		if (!(dest = ft_strncpy(dest, &s[start], len)))
			return (NULL);
		dest[len] = 0;
		return (dest);
	}
	return (NULL);
}
