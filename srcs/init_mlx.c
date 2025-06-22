/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:08:26 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/06/10 22:38:54 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	init_texture_img(t_game *game, t_img_data *image, char *path)
{
	init_clean_img_data(image);
	image->img = mlx_xpm_file_to_image(game->mlx_connection, path,
			&game->tex_info.size, &game->tex_info.size);
	if (image->img == NULL)
		ft_exit(game, err_msg("mlx", ERR_MLX_IMG, 1));
	image->addr = (char *)mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	return ;
}

static void	init_img_data(t_game *game)
{
	game->img_data.img = mlx_new_image(game->mlx_connection, WIDTH, HEIGHT);
	if (!game->img_data.img)
		err_exit("mlx_new_image failure");
	game->img_data.addr = mlx_get_data_addr(game->img_data.img,
			&game->img_data.bits_per_pixel,
			&game->img_data.line_length, &game->img_data.endian);
	if (!game->img_data.addr)
		err_exit("mlx_get_data_addr failure");
}

void	init_mlx_data(t_game *game)
{
	game->mlx_connection = mlx_init();
	if (!game->mlx_connection)
		err_exit("Failed to initialize mlx");
	game->mlx_window = mlx_new_window(game->mlx_connection,
			WIDTH, HEIGHT, "Cub3D");
	if (!game->mlx_window)
		err_exit("Failed to create mlx window");
	init_img_data(game);
	mlx_put_image_to_window(game->mlx_connection,
		game->mlx_window, game->img_data.img, 0, 0);
	return ;
}
