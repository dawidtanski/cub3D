/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:43:52 by dtanski           #+#    #+#             */
/*   Updated: 2025/01/07 14:30:18 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dlstclear(t_dlist **list, void (*del)(void*))
{
	t_dlist *tmp;

	if (list)
		return ;
	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		ft_lstdelone(tmp, del);
	}
	*list = NULL;
}