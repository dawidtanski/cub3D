/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:08:32 by dtanski           #+#    #+#             */
/*   Updated: 2025/04/22 16:47:59 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#define BLOCK 64

static void	draw_square(int x, int y, int size, int color, t_game *game)
{
	for (int i = 0; i < size; i++)
		my_mlx_pixel_put(game->img_data, x + i, y, color);
	for (int i = 0; i < size; i++)
		my_mlx_pixel_put(game->img_data, x, y + i, color);
	for (int i = 0; i < size; i++)
		my_mlx_pixel_put(game->img_data, x + size, y + i, color);
	for (int i = 0; i < size; i++)
		my_mlx_pixel_put(game->img_data, x + i, y + size, color);
}


static void	draw_map(t_game *game)
{
	char **map = game->map_buffer;
	int color = 0x0000FF;

	for (int y = 0; map[y]; y++)
	{
		for (int x = 0; map[y][x]; x++)
		{
			if (map[y][x] == '1')
			draw_square(x * BLOCK, y * BLOCK, BLOCK, color, game);
		}
	}

}

void	clear_image(t_game *game)
{
	for (int y = 0; y < HEIGHT; y++)
		for(int x = 0; x < WIDTH; x++)
			my_mlx_pixel_put(game->img_data, x, y, 0);
}

static int	game_loop(t_game *game)
{
	clear_image(game);
	draw_square(game->player->x,game->player->y, 10, 0x00FF00, game);
	draw_map(game);

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