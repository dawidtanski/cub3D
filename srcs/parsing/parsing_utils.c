/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:32:02 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/05/09 21:56:10 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

//Skips tabs and spaces.
bool	to_skip(char c)
{
	if ((c == 32 || c == 9 || c == 13
		|| c == 11 || c == 12))
		return (true);
	else
		return (false);
}

//Looking for a biggest value of map length.
size_t	find_len(t_map_info *map, int i)
{
	size_t len;

	len = ft_strlen(map->file[i]);
	while (map->file[i])
	{
		if (ft_strlen(map->file[i]) > len)
			len = ft_strlen(map->file[i]);
		i++;
	}
	return (len);
}
