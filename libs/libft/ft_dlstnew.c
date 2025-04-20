/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:13:06 by dtanski           #+#    #+#             */
/*   Updated: 2025/01/06 17:50:40 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist *ft_dlstnew(void *data)
{
	t_dlist *node;

	node = malloc(sizeof(t_dlist));
	if (!node)
		return ;
	node->content = data;
	node->previous = NULL;
	node->next = NULL;
	return (node);
}