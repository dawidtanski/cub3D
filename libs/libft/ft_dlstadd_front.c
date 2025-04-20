/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:42:10 by dtanski           #+#    #+#             */
/*   Updated: 2025/01/07 14:51:29 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_front(t_dlist **list, t_dlist *new)
{
	new->next = *list;
	new->previous = NULL;
	if (*list)
		(*list)->previous = new;
	*list = new;
}