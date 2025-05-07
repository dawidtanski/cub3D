/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:26:03 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/05/07 22:32:06 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

//Using get_next_line to read all the lines from the map file
//and to count numbers of lines.
static int	get_lns_num(char *path)
{
	int		fd;
	char	*line;
	int		lns_num;

	lns_num = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		err_msg(path, strerror(errno), errno);
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			lns_num++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (lns_num);
}

//Reads every lines from file. Allocates memory to new tab.
//Copy lines into new tab.
//Frees all allocated memory and closes the tab.
static void	fill_tab(int row, int col, int i, t_game *game)
{
	char	*line;

	line = get_next_line(game->map_info.fd);
	while (line != NULL)
	{
		game->map_info.file[row] = ft_calloc(ft_strlen(line) + 1,
				sizeof(char));
		if (!game->map_info.file[row])
		{
			err_msg(NULL, ERR_MALLOC, 0);
			return (free_tab((void **)game->map_info.file));
		}
		while (line[i] != '\0')
			game->map_info.file[row][col++] = line[i++];
		game->map_info.file[row++][col] = '\0';
		col = 0;
		i = 0;
		free(line);
		line = get_next_line(game->map_info.fd);
	}
	game->map_info.file[row] = NULL;
	
}

//Start process of parsing the data into game struct.
//Puts information of map file to map_info struct.
void	parse_data(char *path, t_game *game)
{
	int		row;
	int		i;
	size_t	col;

	row = 0;
	i = 0;
	col = 0;
	game->map_info.line_count = get_lns_num(path);
	game->map_info.path = path;
	game->map_info.file = ft_calloc(game->map_info.line_count + 1,
			sizeof(char *));
	if (!(game->map_info.file))
	{
		err_msg(NULL, ERR_MALLOC, 0);
		return ;
	}
	game->map_info.fd = open(path, O_RDONLY);
	if (game->map_info.fd < 0)
		err_msg(path, strerror(errno), FAILURE);
	else
	{
		fill_tab(row, col, i, game);
		close(game->map_info.fd);
	}
}
