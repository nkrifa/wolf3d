/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiodier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:51:09 by afiodier          #+#    #+#             */
/*   Updated: 2016/11/15 18:16:08 by afiodier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_compt(int n)
{
	int		i;

	i = 0;
	while (n /= 10)
		i++;
	return (i);
}

static	char	*ft_printing(char *dest, int n, int i)
{
	while (n > 0)
	{
		dest[i--] = (n % 10) + '0';
		n = n / 10;
	}
	return (dest);
}

char			*ft_itoa(int n)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = ft_strnew(12)))
		return (NULL);
	if (n < 0)
	{
		dest[i++] = '-';
		if (n == -2147483648)
		{
			dest[i++] = '2';
			n = -147483648;
		}
		n = -n;
	}
	i = i + ft_compt(n);
	dest[i] = 0;
	if (n == 0)
		dest[i--] = (n % 10) + '0';
	dest = ft_printing(dest, n, i);
	return (dest);
}
