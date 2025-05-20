/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:10:22 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/05/20 21:22:00 by pjedrycz         ###   ########.fr       */
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
	game->player->dir = '0';
	while (map_tab[i] != NULL)
	{
		j = 0;
		while (map_tab[i][j])
		{
			while (to_skip(game->map[i][j]))
				j++;
			if (!(ft_strchr("10NSEW", map_tab[i][j])))
				return (err_msg(game->map_info.path, ERR_INV_LETTER, FAILURE));
			if (ft_strchr("NSEW", map_tab[i][j]) && game->player->dir != '0')
				return (err_msg(game->map_info.path, ERR_NUM_PLAYER, FAILURE));
			if (ft_strchr("NSEW", map_tab[i][j]) && game->player->dir == '0')
				game->player->dir = map_tab[i][j];
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

//Check player position - takes player coordinates.
//Check player surrounding. First - length of upper
//and lower lines. Then checking if top, bottom, left and right
//surrounding tabs, are whitespaces.
static int	val_player_pos(t_game *game, char **map_tab)
{
	int	i;
	int	j;

	i = (int)game->player->y;
	j = (int)game->player->x;
	if (ft_strlen(map_tab[i - 1]) < (size_t)j
		|| ft_strlen(map_tab[i + 1]) < (size_t)j
		|| is_a_white_spc(map_tab[i][j - 1]) == SUCCESS
		|| is_a_white_spc(map_tab[i][j + 1]) == SUCCESS
		|| is_a_white_spc(map_tab[i - 1][j]) == SUCCESS
		|| is_a_white_spc(map_tab[i + 1][j]) == SUCCESS)
		return (FAILURE);
	return (SUCCESS);	
}

//Iterates thru whole map to check find player position.
//If finds "NSEW" - sets player position here.
//Last thing - verify player surroundings.
static int	chck_player_pos(t_game *game, char **map_tab)
{
	int	i;
	int	j;

	if (game->player->dir == '0')
		return (err_msg(game->map_info.path, ERR_PLAYER_DIR, FAILURE));
	i = 0;
	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j])
		{
			if (ft_strchr("NSEW", map_tab[i][j]))
			{
				game->player->x = (float)j + 0.5;
				game->player->y = (float)i + 0.5;
				map_tab[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (val_player_pos(game, map_tab) == FAILURE)
		return (err_msg(game->map_info.path, ERR_PLAYER_POS, FAILURE));
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
	if (chck_player_pos(game, map_tab) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
