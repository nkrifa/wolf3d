/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiodier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:14:36 by afiodier          #+#    #+#             */
/*   Updated: 2016/11/08 17:16:10 by afiodier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t y;

	i = 0;
	y = 0;
	while (dest[i] != 0)
		i++;
	while (n && src[y])
	{
		dest[i + y] = src[y];
		n--;
		y++;
	}
	dest[i + y] = 0;
	return (dest);
}
