/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiodier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:14:33 by afiodier          #+#    #+#             */
/*   Updated: 2016/11/25 18:14:34 by afiodier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst1;
	char	*src1;

	dst1 = (char*)dst;
	src1 = (char*)src;
	if (src1 < dst1)
	{
		dst1 += (len - 1);
		src1 += (len - 1);
		while (len--)
			*dst1-- = *src1--;
		return (dst);
	}
	while (len--)
		*dst1++ = *src1++;
	return (dst);
}
