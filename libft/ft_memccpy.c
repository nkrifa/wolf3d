/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiodier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:47:09 by afiodier          #+#    #+#             */
/*   Updated: 2016/11/08 16:47:12 by afiodier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*sc;
	char	*dst;

	i = 0;
	dst = (char*)dest;
	sc = (char*)src;
	if (n == 0)
		return (NULL);
	while (i < n && sc[i] != (char)c)
	{
		dst[i] = sc[i];
		i++;
	}
	if (i < n)
	{
		dst[i] = sc[i];
		i++;
		return ((void*)&dst[i]);
	}
	return (NULL);
}
