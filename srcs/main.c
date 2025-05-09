/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:08:32 by dtanski           #+#    #+#             */
/*   Updated: 2025/05/09 22:08:31 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	game_loop(t_game *game)
{
	float		fraction;
	float		start_x;
	int			i;
	t_point		*player_coord;

	player_coord = malloc(sizeof(t_point));
	if (!player_coord)
		return (1);
	player_coord->x = game->player->x;
	player_coord->y = game->player->y;
	fraction = PI / 3 / WIDTH;
	start_x = game->player->angle - PI / 6;
	i = 0;
	clear_image(game);
	draw_square(player_coord, 10, 0x00FF00, game);
	draw_map(game);
	while (i < WIDTH)
	{
		draw_line(game->player, game, start_x, i);
		start_x += fraction;
		i++;
	}
	mlx_put_image_to_window(game->mlx_connection, game->mlx_window, game->img_data->img, 0, 0);
	return (0);
}

// We're doing few things here:
// - File verification. 
// - If the file is ok, we can parse the data to work on them later.
// - Then we're reading the file and saving data in proper struct.
// - Map validation.
// - Textures valisation.
// - Player initializaition.
static int	parse_args(t_game *game, char *argv[])
{
	if (check_file(argv[1], true) == FAILURE)
		ft_exit(game, FAILURE);
	parse_data(argv[1], game);
	if (get_file_data(game, game->map_info.file) == FAILURE)
		return (free_data(game));
	CO DALEJ?
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	printf("%d\n",argc);
	if (argc != 2 /* || ft_strcmp(argv[1], ".cub")*/)
	{
		perror("Wrong arguments number");
		exit(EXIT_FAILURE);
	}
	game = malloc(sizeof(t_game));
	if (!game)
		err_exit("Failed to allocate memory for game");
	data_init(argv[1], game);
	if (parse_args(&game, argv) != 0)//tutaj dodaję początek parsowania i sprawdzania mapy.
		return (1);
	// if (!map_is_valid(game->map_buffer))
	// {
	// 	perror("Wrong map");
	// 	exit(EXIT_FAILURE);
	// }
	setup_hooks(game);
	mlx_loop_hook(game->mlx_connection, game_loop, game);
	mlx_loop(game->mlx_connection);
}