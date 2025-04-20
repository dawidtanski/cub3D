/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_after_another.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:03:08 by dtanski           #+#    #+#             */
/*   Updated: 2025/01/07 15:09:24 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_after_another(t_dlist *node, t_dlist *node_to_insert)
{
	node_to_insert->next = node->next;
	node_to_insert->previous = node;
	node->next = node_to_insert;
	if (node_to_insert->next)
		node_to_insert->next->previous = node_to_insert;
}