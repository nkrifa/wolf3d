/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiodier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:56:29 by afiodier          #+#    #+#             */
/*   Updated: 2016/11/08 16:56:41 by afiodier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sun;
	unsigned char	*sde;

	i = 0;
	sun = (unsigned char*)s1;
	sde = (unsigned char*)s2;
	while (i < n)
	{
		if (sun[i] != sde[i])
			return (sun[i] - sde[i]);
		i++;
	}
	return (0);
}
