/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 17:51:41 by dtanski           #+#    #+#             */
/*   Updated: 2025/04/20 21:21:59 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

/*

*/



static void	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx_connection, game->mlx_window);
	clean(); // TODO
}

static void	handle_keypress(int	keycode, t_game *game)
{
	if (keycode == KEY_W)
		go_up(game);
	else if (keycode == KEY_S)
		go_down(game);
	else if (keycode == KEY_A)
		go_left(game);
	else if (keycode == KEY_D)
		go_right(game);
	else if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_ARROW_LEFT)
		turn_left(game);
	else if (keycode == KEY_ARROW_RIGHT)
		turn_right(game);
	return (0);
}

// void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)
void	setup_hooks(t_game *game)
{
	mlx_hook(game->mlx_window, ON_KEYDOWN, 1L << 0, handle_keypress, game);
	mlx_hook(game->mlx_window, ON_DESTROY, 0, close_game, game);
}



