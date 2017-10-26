/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiodier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 02:34:05 by afiodier          #+#    #+#             */
/*   Updated: 2016/11/15 02:34:07 by afiodier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*back;

	if (!(back = f(lst)))
		return (NULL);
	new = back;
	while (lst->next)
	{
		lst = lst->next;
		if (!(back->next = f(lst)))
			return (NULL);
		back = back->next;
	}
	return (new);
}
