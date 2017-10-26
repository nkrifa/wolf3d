/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiodier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:13:34 by afiodier          #+#    #+#             */
/*   Updated: 2016/11/08 17:16:03 by afiodier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *dest;

	if (s1 && s2)
	{
		dest = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (!dest)
			return (NULL);
		ft_strcpy(dest, s1);
		ft_strcpy(&dest[ft_strlen(s1)], s2);
		return (dest);
	}
	return (NULL);
}
