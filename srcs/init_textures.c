/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:55:16 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/05/26 19:26:13 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"


static void	init_texture_img(t_game *game, t_img_data *image, char *path)
{
	init_clean_img(image);
	image->img = mlx_xpm_file_to_image(game->mlx_connection, *path, 
			&game->tex_info.size, &game->tex_info.size);
	if (image->img == NULL)
		ft_exit(game, err_msg("mlx", ERR_MLX_IMG, 1));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	return;
}

static int	*xpm_to_img(t_game *game, char *path)
{
	t_img_data	tmp;
	int			*buff;
	int			x;
	int			y;

	init_texture_img(game, &tmp, path);
	buff = ft_calloc(1,
			sizeof * buff * game->tex_info.size * game->tex_info.size);
	if (!buff)
		ft_exit(game, err_msg(NULL, ERR_MALLOC, 1));
	y = 0;
	while (y < game->tex_info.size)
	{
		x = 0;
		while (x < game->tex_info.size)
		{
			buff[y * game->tex_info.size + x]
				= tmp.addr[y * game->tex_info.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(game->mlx_connection, tmp.img);
	return (buff);
}

//Puts textures data into a t_game struct.
void	init_textures(t_game *game)
{
	game->textures = ft_calloc(5, sizeof * game->textures);
	if (!game->textures)
		ft_exit(game, err_msg(NULL, ERR_MALLOC, 1));
	game->textures[NORTH] = xpm_to_img(game, game->tex_info.north);///////
	game->textures[SOUTH] = xpm_to_img(game, game->tex_info.south);
	game->textures[EAST] = xpm_to_img(game, game->tex_info.east);
	game->textures[WEST] = xpm_to_img(game, game->tex_info.west);
}

//Initializes t_tex_info struct data.
void	init_tex_info(t_tex_info *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->west = NULL;
	textures->east = NULL;
	textures->floor = 0;
	textures->ceiling = 0;
	textures->hex_floor = 0x0;
	textures->hex_ceiling = 0x0;
	textures->size = TEX_SIZE;
	textures->index = 0;
	textures->step = 0.0;
	textures->pos = 0.0;
	textures->x = 0;
	textures->y = 0;
}
