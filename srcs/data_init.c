/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:14:04 by dtanski           #+#    #+#             */
/*   Updated: 2025/06/11 18:10:28 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	init_player_data(t_player *player)
{
	player->x = 0.0;
	player->y = 0.0;
	player->angle = 0.0;
	player->fov_x = 0.0;
	player->fov_y = 0.0;
	player->dir = '\0';
}

static void	init_point_data(t_point *point)
{
	point->y = 0.0;
	point->x = 0.0;
}

static void	init_tex_info(t_tex_info *tex_info)
{
	tex_info->north = NULL;
	tex_info->south = NULL;
	tex_info->west = NULL;
	tex_info->east = NULL;
	tex_info->floor = NULL;
	tex_info->ceiling = NULL;
	tex_info->hex_floor = 0;
	tex_info->hex_ceiling = 0;
	tex_info->size = 0;
	tex_info->index = 0;
	tex_info->step = 0;
	tex_info->pos = 0;
	tex_info->x = 0;
	tex_info->y = 0;
}

static void	init_map_info(t_map_info *map_info)
{
	map_info->fd = 0;
	map_info->line_count = 0;
	map_info->path = NULL;
	map_info->file = NULL;
	map_info->height = 0;
	map_info->width = 0;
	map_info->index_end_of_map = 0;
}

void	data_init(t_game *game)
{
	game->mlx_connection = NULL;
	game->mlx_window = NULL;
	init_clean_img_data(&game->img_data);
	init_player_data(&game->player);
	init_point_data(&game->point);
	game->textures = NULL;
	game->texture_pxl = NULL;
	init_tex_info(&game->tex_info);
	init_map_info(&game->map_info);
	init_move_comp(&game->player.move_comp);
	game->map = NULL;
	game->player.game = game;
}
