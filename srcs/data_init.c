/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:14:04 by dtanski           #+#    #+#             */
/*   Updated: 2025/04/21 15:12:43 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	load_map(char *map_path, t_game *game)
{
	int		fd;
	int		i;
	int		line_count;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		err_exit("Error opening map file");
	line_count = 0;
	while (line = get_next_line(fd) != NULL)
	{
		free(line);
		line_count++;
	}
	close(fd);
	game->map_buffer = malloc(sizeof(char *) * (line_count + 1));
	if (!game->map_buffer)
		err_exit("Error allocating memory for map");
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		err_exit("Error opening map file");
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
		game->map_buffer[i++] = line;
	game->map_buffer[i] = NULL;
	close(fd);
}

void	init_data(char *map_path, t_game *game)
{
	// For testing
	game->player_x = WIDTH / 2;
	game->player_y = HEIGHT / 2;

	load_map(map_path, game);
	game->img_data = NULL;
}