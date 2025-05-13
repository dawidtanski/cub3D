/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:10:22 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/05/13 22:44:16 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

//Checking if map is the last element in map file.
static int	chck_map_order(t_map_info *map)
{
	int	i;
	int	j;

	i = map->index_end_of_map;
	while (map->file[i])
	{
		j = 0;
		while (map->file[i][j])
		{
			if (!ft_isspace(map->file[i][j]))
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

//Check the map for all needed elements.
//Resets player position and then check all charcters (line by line)
//in map file. All elements needs to be there.
static int	chck_map_elem(t_game *game, char **map_tab)
{
	int	i;
	int	j;

	i = 0;
	game->player.dir = '0';
	while (map_tab[i] != NULL)
	{
		j = 0;
		while (map_tab[i][j])
		{
			while (to_skip(game->map[i][j]))
				j++;
			if (!(ft_strchr("10NSEW", map_tab[i][j])))
				return (err_msg(game->map_info.path, ERR_INV_LETTER, FAILURE));
			if (ft_strchr("NSEW", map_tab[i][j]) && game->player.dir != '0')
				return (err_msg(game->map_info.path, ERR_NUM_PLAYER, FAILURE));
			if (ft_strchr("NSEW", map_tab[i][j]) && game->player.dir == '0')
				game->player.dir = map_tab[i][j];
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

//Initializes whole process of map validation
int	chck_map(t_game *game, char **map_tab)
{
	if (!game->map)
		return (err_msg(game->map_info.path, ERR_MAP_MISSING, FAILURE));
	if (chck_map_order(&game->map_info) == FAILURE)
		return (err_msg(game->map_info.path, ERR_MAP_ORDER, FAILURE));
	if (chck_map_sides(&game->map_info, map_tab) == FAILURE)
		return (err_msg(game->map_info.path, ERR_MAP_WALLS, FAILURE));
	if (game->map_info.height < 3)
		return (err_msg(game->map_info.path, ERR_MAP_SIZE, FAILURE));
	if (chck_map_elem(game, map_tab) == FAILURE)
		return (FAILURE);
	/////Check player position

	return (SUCCESS);
}
