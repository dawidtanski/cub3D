/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:08:32 by dtanski           #+#    #+#             */
/*   Updated: 2025/04/21 15:32:11 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	draw_square(int x, int y, int size, int color, t_game *game)
{
	for (i = 0, i < size; i++)
		my_mlx_pixel_put(game->img_data, x, y, color);
}

int	draw_loop(t_game *game)
{
	draw_square()
}

int	main(int argc, char *argv)
{
	t_game	*game;

	if (argc != 2 || ft_strcmp(argv[1], ".cub"))
	{
		perror("Wrong arguments number");
		exit(EXIT_FAILURE);
	}
	data_init(game);
	if (!map_is_valid(game->map_buffer))
	{
		perror("Wrong map");
		exit(EXIT_FAILURE);
	}
	game->mlx_connection = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx_connection, WIDTH, HEIGHT, "Cub3D");
	load_map(argv[1], game);
	mlx_loop(game->mlx_connection);
}