/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:01:15 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/05/20 21:16:10 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../inc/cub3D.h"

//Check if player direction in player struct,
//is nort ('N') or south ('S').
//For 'N':
//-- sets player vector on (0, 1).
//-- sets camera vector on (-0.66, 0) - also player FOV.
//For 'S':
//-- sets player vector on (0, -1).
//-- sets camera vector on (0.66, 0) - also player FOV.
static void	set_ns_dir(t_player *player)
{
	if (player->dir == 83)
	{
		player->x = 0;
		player->y = 1;
		player->fov_x = -0.66;
		player->fov_y = 0;
	}
	else if (player->dir == 78)
	{
		player->x = 0;
		player->y = -1;
		player->fov_x = 0.66;
		player->fov_y = 0;
	}
	else
		return ;
}

//Check if player direction in player struct,
//is west ('W') or east ('E').
//For 'W':
//-- sets player vector on (-1, 0).
//-- sets camera vector on (0, -0.66) - also player FOV.
//For 'S':
//-- sets player vector on (1, 0).
//-- sets camera vector on (0, 0.66) - also player FOV.
static void	set_we_dir(t_player *player)
{
	if (player->dir == 87)
	{
		player->x = -1;
		player->y = 0;
		player->fov_x = 0;
		player->fov_y = -0.66;
	}
	else if (player->dir == 69)
	{
		player->x = 1;
		player->y = 0;
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
	set_ns_dir(game->player);
	set_we_dir(game->player);
}
