/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:07:10 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/05/09 22:05:07 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

//Looking for the first line of map in map file. 
//Count how many lines map have - height.
//Saves last map index.
static int	cnt_map_lns(t_game *game, char **file, int i)
{
	size_t	indx;
	size_t	j;

	indx = i;
	while (file[i])
	{
		j = 0;
		while (to_skip(file[i][j]))
			j++;
		if (file[i][j] != 49)
			break;
		i++;
	}
	game->map_info.index_end_of_map = i;
	return (i - indx);

}



//Using helper function to find map width.
//Base on that allocates memory for each map line,
//and copying all values to memory.
//Finishes with NULL at the end.
static int	get_map_tab(t_map_info *map_info, char **map_tab, int indx)
{
	size_t	i;
	size_t	j;

	map_info->width = find_len(map_info, indx);
	i = 0;
	while (i < map_info->height)
	{
		j = 0;
		map_tab[i] = malloc(sizeof(char) * (map_info->width + 1));
		if (!map_tab[i])
			return (err_msg(NULL, ERR_MALLOC, FAILURE));
		while (map_info->file[indx][j] && map_info->file[indx][j] != '\n')
		{
			map_tab[i][j] == map_info->file[indx][j];
			j++;
		}
		while (j < map_info->width)
			map_tab[i][j++] = '\0';
		i++;
		indx++;
	}
	map_tab[i] = NULL;
	return (SUCCESS);
}

//Checking height of the map.
//Allocates memory for map data array.
//Copying map elements to new array.
static int	get_map_info(t_game *game, char **file, int i)
{
	game->map_info.height = cnt_map_lns(game, file, i);
	game->map = malloc(sizeof(char *) * (game->map_info.height + 1));
	if (!game->map)
		return (err_msg(NULL, ERR_MALLOC, FAILURE));
	if (get_map_tab(&game->map_info, game->map, i) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

//Helper function to change some spaces into a walls.
//Skip whitespaces at the begining of map file.
static void	spc_to_wall(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (game->map[i])
	{
		j= 0;
		while (to_skip(game->map[i][j]))
			j++;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 32
				&& j != game->map[i][ft_strlen(game->map[i]) - 1])
				game->map[i][j] = 49;
		}
		i++;
	}
}

//Initializes game map creation.
//Start processes of changing signs into a map elements.
//If evything is ok, returns SUCCESS.
int	create_map(t_game *game, char **file, int i)
{
	if (get_map_info(game, file, i) == FAILURE)
		return (FAILURE);
	spc_to_wall(game);
	return (SUCCESS);	
}
