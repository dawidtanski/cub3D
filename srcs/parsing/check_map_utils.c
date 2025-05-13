/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:18:07 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/05/13 21:36:57 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

//Checking if all chars in line are '1'. If yes - we have
//top or bottom line of the map.
static int	chck_top_bottom(char **map_tab, int i, int j)
{
	if (!map_tab || !map_tab[i] || !map_tab[j])
		return (FAILURE);
	while (to_skip(map_tab[i][j]))
		j++;
	while (map_tab[i][j])
	{
		if (map_tab[i][j] != 49)
			return (FAILURE);
		j++;
	}
	return (SUCCESS);
}

//Checking map sides. But first checks top - should be all '1'
//and then check lines below (first and last char needs to be '1).
//Last line has to be all '1' - bottom of the map.
int	chck_map_sides(t_map_info *map, char **map_tab)
{
	int	i;
	int	j;

	if (chck_top_bottom(map_tab, 0, 0) == FAILURE)
		return (FAILURE);
	i = 1;
	while (i < (map->height - 1))
	{
		j = ft_strlen(map_tab[i]) - 1;
		if (map_tab[i][j] != 49)
			return (FAILURE);
		i++;
	}
	if (chck_top_bottom(map_tab, i, 0) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
