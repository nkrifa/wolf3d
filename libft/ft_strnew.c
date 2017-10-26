/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiodier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:14:52 by afiodier          #+#    #+#             */
/*   Updated: 2016/11/08 17:16:17 by afiodier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*dest;

	if (!(dest = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(dest, size + 1);
	return (dest);
}
