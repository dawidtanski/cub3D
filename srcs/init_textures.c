/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:55:16 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/06/10 22:58:50 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	*xpm_to_img(t_game *game, char *path, int x, int y)
{
	t_img_data	tmp;
	int			*buff;
	int			*pixel_data;

	init_texture_img(game, &tmp, path);
	buff = ft_calloc(1, sizeof(int) * game->tex_info.size
			* game->tex_info.size);
	if (!buff)
		ft_exit(game, err_msg(NULL, ERR_MALLOC, 1));
	pixel_data = (int *)tmp.addr;
	y = 0;
	while (y < game->tex_info.size)
	{
		x = 0;
		while (x < game->tex_info.size)
		{
			buff[y * game->tex_info.size + x]
				= pixel_data[y * game->tex_info.size + x];
			x++;
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
	game->textures[NORTH] = xpm_to_img(game, game->tex_info.north, 0, 0);
	game->textures[SOUTH] = xpm_to_img(game, game->tex_info.south, 0, 0);
	game->textures[EAST] = xpm_to_img(game, game->tex_info.east, 0, 0);
	game->textures[WEST] = xpm_to_img(game, game->tex_info.west, 0, 0);
}
