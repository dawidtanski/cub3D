/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:34:48 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/05/09 22:07:06 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

//Passing whitespaces and gets the token which is the
//information about file path.
//Allocates memory for file path.
static char	*get_textures_path(char *line, int i)
{
	int		len;
	int		j;
	char	*path;

	while (line[i] && (line[i] == 32 || line[i] == 9))
		i++;
	len = i;
	while (line[len] && (line[len] != 32 && line[len] != 9))
		len++;
	path = malloc(sizeof(char) * (len - i + 1));
	if (!path)
		return (NULL);
	j = 0;
	while (line[i] && (line[i] != 32 && line[i] != 9 && line[i] != 10))
		path[j++] = line[i++];
	path[j] = '\0';
	while (line[i] && (line[i] == 32 || line[i] == 9))
		i++;
	if (line[i] && line[i] != 10)
	{
		free(path);
		path = NULL;
	}
	return (path);	
}

//Looking for proper direction symbols ("NO", "SO", "WE", "EA")
//and checking if after symbol we have proper line close.
static int	get_textures_info(t_tex_info *textures, char *line, int i)
{
	if (line[i + 2] && ft_isprint(line[i + 2]))
		return (ERROR);
	if (line[i] == 78 && line[i + 1] == 79 && !(textures->north))
		textures->north = get_textures_path(line, i + 2);
	else if (line[i] == 83 && line[i + 1] == 79 && !(textures->south))
		textures->south = get_textures_path(line, i + 2);
	else if (line[i] == 87 && line[i + 1] == 69 && !(textures->west))
		textures->west = get_textures_path(line, i + 2);
	else if (line[i] == 69 && line[i + 1] == 65 && !(textures->east))
		textures->east = get_textures_path(line, i + 2);
	else
		return (ERROR);
	return (SUCCESS);
}

//Iterate the map file, passing the whitespaces to get
//to the data. Then check the tokens and initializes proper process
//for texture or colors. 
//Uses enums to send proper communication to main process.
static int	get_map_info(t_game *game, char **map, int i, int j)
{
	while (map[i][j] == 32 || map[i][j] == 9 || map[i][j] == 10)
		j++;
	if (ft_isprint(map[i][j]) && ft_isprint(map[i][j + 1]))
	{
		if (map[i][j + 1] && ft_isprint(map[i][j + 1])
			&& !ft_isdigit(map[i][j]))
		{
			if (get_textures_info(&game->tex_info, map[i], j) == ERROR)
				return (err_msg(game->map_info.path, ERR_TEX_INVALID, FAILURE));
			return (STOP);
		}
		else
		{
			if (get_textures_colors(game, &game->tex_info, map[i], j) == ERROR)
				return (FAILURE);
			return (STOP);
		}
	}
	else if (ft_isdigit(map[i][j]))
	{
		if (create_map(game, map, i) == FAILURE)
			return (err_msg(game->map_info.path, ERR_INVALID_MAP, FAILURE));
		return (SUCCESS);
	}
	return (CONTINUE);
}

//Initializes the proces of extracting data from the file.
//Using macros (BREAK, SUCCESS, FAILURE, CONTINUE) to stop the process
//or get the result right away.
int	get_file_data(t_game *game, char **map)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			result = get_map_info(game, map, i, j);
			if (result == STOP)
				break;
			else if (result == FAILURE)
				return (FAILURE);
			else if (result == SUCCESS)
				return (SUCCESS);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
