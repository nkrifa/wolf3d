/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiodier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:56:52 by afiodier          #+#    #+#             */
/*   Updated: 2016/11/08 16:56:54 by afiodier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*dst;
	char	*sc;

	i = 0;
	dst = (char*)dest;
	sc = (char*)src;
	while (i < (int)n)
	{
		dst[i] = sc[i];
		i++;
	}
	return (dest);
}
