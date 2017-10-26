/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorielle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiodier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 20:42:48 by afiodier          #+#    #+#             */
/*   Updated: 2016/11/23 20:42:51 by afiodier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_factorielle(int nb)
{
	int i;
	int result;

	result = 1;
	i = 1;
	if (nb > 12)
		return (0);
	while (i < nb)
		result *= i;
	return (result);
}
