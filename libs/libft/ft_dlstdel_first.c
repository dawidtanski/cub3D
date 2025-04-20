/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:39:38 by dtanski           #+#    #+#             */
/*   Updated: 2025/01/07 14:41:07 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdel_first(t_dlist **list, void (*del)(void*))
{
	t_dlist *tmp;

	if (!list || !(*list))
		return ;
	tmp = *list;
	*list = (*list)->next;
	if (*list)
		(*list)->previous = NULL;
	tmp->next = NULL;
	del(tmp->content);
	free(tmp);
}