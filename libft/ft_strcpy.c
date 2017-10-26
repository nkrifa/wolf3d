/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiodier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:12:54 by afiodier          #+#    #+#             */
/*   Updated: 2016/11/08 17:15:48 by afiodier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	if (src)
	{
		while (src[i] != 0)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = src[i];
	}
	return (dest);
}
