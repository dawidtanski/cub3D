/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:08:32 by dtanski           #+#    #+#             */
/*   Updated: 2025/05/01 11:15:10 by dtanski          ###   ########.fr       */
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
	// if (!map_is_valid(game->map_buffer))
	// {
	// 	perror("Wrong map");
	// 	exit(EXIT_FAILURE);
	// }
	setup_hooks(game);
	mlx_loop_hook(game->mlx_connection, game_loop, game);
	mlx_loop(game->mlx_connection);
}