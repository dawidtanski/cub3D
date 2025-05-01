/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:14:04 by dtanski           #+#    #+#             */
/*   Updated: 2025/05/01 11:11:23 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
// Debugging
char	**get_map(void)
{
	char **map = malloc(sizeof(char *) * 11);
    map[0] = "111111111111111";
    map[1] = "100000000000001";
    map[2] = "100000000000001";
    map[3] = "100000100000001";
    map[4] = "100000000000001";
    map[5] = "100000010000001";
    map[6] = "100001000000001";
    map[7] = "100000000000001";
    map[8] = "100000000000001";
    map[9] = "111111111111111";
    map[10] = NULL;
    return (map);
}

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
	while ((line = get_next_line(fd)) != NULL)
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

void	data_init(char *map_path, t_game *game)
{

	//debug
	(void)map_path;
	// For testing purposes
	game->player = malloc(sizeof(t_player));
	if (!game->player)
	err_exit("Failed to allocate memory for game->player");
	game->player->x = WIDTH / 2;
	game->player->y = HEIGHT / 2;
	game->player->angle = PI / 2;

	game->img_data = malloc(sizeof(t_img_data));
	if (!game->img_data)
		err_exit("Failed to allocate memory for img_data");
	game->mlx_connection = mlx_init();
	if (!game->mlx_connection)
		err_exit("Failed to initialize mlx");
	game->mlx_window = mlx_new_window(game->mlx_connection, WIDTH, HEIGHT, "Cub3D");
	if (!game->mlx_window)
		err_exit("Failed to create mlx window");
	game->img_data->img = mlx_new_image(game->mlx_connection, WIDTH, HEIGHT);
	game->img_data->addr = mlx_get_data_addr(game->img_data->img, &game->img_data->bits_per_pixel, &game->img_data->line_length, &game->img_data->endian);
	// load_map(map_path, game);
	// Debuggig
	game->map_buffer = get_map();
	mlx_put_image_to_window(game->mlx_connection, game->mlx_window, game->img_data->img, 0, 0);
	game->player->game = game;

}