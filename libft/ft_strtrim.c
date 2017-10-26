/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiodier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:15:24 by afiodier          #+#    #+#             */
/*   Updated: 2016/11/08 17:15:29 by afiodier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		end;
	char	*dest;

	if (!(s))
		return (NULL);
	end = ft_strlen(s) - 1;
	start = 0;
	i = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (!s[start])
		return (ft_strnew(1));
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	if (!(dest = (char*)malloc(sizeof(char) * (end - start) + 2)))
		return (NULL);
	while (start <= end)
	{
		dest[i++] = s[start++];
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strtrip(char const *s, char c)
{
	int		i;
	int		start;
	int		end;
	char	*dest;

	if (!(s))
		return (NULL);
	end = ft_strlen(s) - 1;
	start = 0;
	i = 0;
	while (s[start] == c)
		start++;
	if (!s[start])
		return (ft_strnew(1));
	while (s[end] == c)
		end--;
	if (!(dest = (char*)malloc(sizeof(char) * (end - start) + 2)))
		return (NULL);
	while (start <= end)
	{
		dest[i++] = s[start++];
	}
	dest[i] = 0;
	return (dest);
}
