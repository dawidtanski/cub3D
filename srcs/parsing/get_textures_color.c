/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:55:37 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/05/09 16:56:57 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

//Looging for digits in the string. 
//False if found a digit and true if not. 
static bool found_no_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			return (false);
		i++;
	}
	return (true);	
}

//Covert string data to int values of R ,G and B.
//Checking if coversion is valid - if is -1 or is no digit - fail.
static int	get_rgb_arr(char **rgb_before, int *rgb_after)
{
	int	i;

	i = -1;
	while (rgb_before[++i])
	{
		rgb_after[i] = ft_atoi(rgb_before[i]);
		if (rgb_after[i] == -1 || found_no_digit(rgb_before[i]) == true)
		{
			free_tab((void **)rgb_before);
			free(rgb_after);
			return (0);
		}
	}
	free_tab((void **)rgb_before);
	return (rgb_after);
}

//Extracts RGB colors informations. 
//Checking if we have exact 2 colors in the file 
//(each value for R, G and B parameters).
//Allocates memory for RGB array.
static int	set_colors(char *line)
{
	char	**rgb_before;
	int		**rgb_after;
	int		cnt;

	rgb_before = ft_split(line, 44);
	cnt = 0;
	while (rgb_before[cnt])
		cnt++;
	if (cnt != 3)
	{
		free_tab((void **)rgb_before);
		return (0);
	}
	rgb_after = malloc(sizeof(int) * 3);
	if (!rgb_after)
	{
		err_msg(NULL, ERR_MALLOC, 0);
		return (0);
	}
	return (get_rgb_arr(rgb_before, rgb_after));
}

//Checking if we need to add color foe ceiling ('C') or floor ('F').
//If helper function returns NULL, prints the error.
int	get_textures_color(t_game *game, t_tex_info *textures, char *line, int i)
{
	if (line[i + 1] && ft_isprint(line[i + 1]))
		return (err_msg(game->map_info.path, ERR_FLOOR_CEILING, ERROR));
	if (!textures->ceiling && line[i] == 67)
	{
		textures->ceiling = set_colors(line + i + 1);
		if (textures->ceiling == 0)
			return (err_msg(game->map_info.path, ERR_COLOR_CEILING, ERROR));
	}
	else if (!textures->floor && line[i] == 70)
	{
		textures->floor = set_colors(line + i + 1);
		if (textures->floor == 0)
			return (err_msg(game->map_info.path, ERR_COLOR_FLOOR, ERROR));
	}
	else
		return (err_msg(game->map_info.path, ERR_FLOOR_CEILING, ERROR));
	return (SUCCESS);
}
