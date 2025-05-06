/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:00:35 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/05/06 19:08:13 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	ft_exit(t_game *game, int code)
{
	if (!game)
		exit(code);
	if (game->mlx_window && game->mlx_connection)
		mlx_destroy_window(game->mlx_window, game->mlx_connection);
	if (game->mlx_connection)
	{
		mlx_destroy_display(game->mlx_connection);
		mlx_loop_end(game->mlx_connection);
		free(game->mlx_connection);
	}
	free_data(game);////////
	exit(code);
}

int	exit_game(t_game *game)
{
	ft_exit(game, 0);
	return (0);
}
