/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:12:13 by dtanski           #+#    #+#             */
/*   Updated: 2025/04/21 15:07:32 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	go_up(t_game *game)
{
	game->player_y++;
}
void	go_down(t_game *game)
{
	game->player_y--;
}
void	go_right(t_game *game)
{
	game->player_x++;
}
void	go_left(t_game *game)
{
	game->player_x--;
}

void	turn_left(t_game *game)
{
	// TODO
}
void	turn_right(t_game *game)
{
	// TODO
}