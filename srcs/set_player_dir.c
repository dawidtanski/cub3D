/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:01:15 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/06/10 23:33:13 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	set_ns_dir(t_player *player)
{
	if (player->dir == 'S')
	{
		player->angle = PI / 2;
		player->fov_x = -0.66;
		player->fov_y = 0;
	}
	else if (player->dir == 'N')
	{
		player->angle = 3 * PI / 2;
		player->fov_x = 0.66;
		player->fov_y = 0;
	}
	else
		return ;
}

static void	set_we_dir(t_player *player)
{
	if (player->dir == 'W')
	{
		player->angle = PI;
		player->fov_x = 0;
		player->fov_y = -0.66;
	}
	else if (player->dir == 'E')
	{
		player->angle = 0;
		player->fov_x = 0;
		player->fov_y = 0.66;
	}
	else
		return ;
}

//Initializes process of setting up player direction.
//First for north and south, and then for west and east.
void	set_player_dir(t_game *game)
{
	set_ns_dir(&game->player);
	set_we_dir(&game->player);
}
