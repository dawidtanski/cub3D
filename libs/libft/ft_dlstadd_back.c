/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:51:41 by dtanski           #+#    #+#             */
/*   Updated: 2025/01/07 15:01:28 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_dlist **list, t_dlist *new)
{
	t_dlist *last;

	if (!*list)
	{
		ft_dlstadd_front(list, new);
		return ;
	}
	last = ft_dlstlast(*list);
	last->next = new;
	new->previous = last;
	new->next = NULL;
}