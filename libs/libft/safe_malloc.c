/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:07:05 by dtanski           #+#    #+#             */
/*   Updated: 2025/06/12 15:30:19 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*safe_malloc(size_t	size)
{
	void	*ret;

	ret = malloc(size);
	if (ret == NULL)
		err_exit("Mallocing failed");
	return (ret);
}
