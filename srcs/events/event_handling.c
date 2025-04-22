/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 17:51:41 by dtanski           #+#    #+#             */
/*   Updated: 2025/04/22 16:11:15 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

/*

*/



static void	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx_connection, game->mlx_window);
	// clean(); // TODO
}

static void	move_player(t_player *player, int keycode)
{
	int	speed;
	float	angle_speed;
	float	cos_angle;
	float	sin_angle;

	speed = 3;
	angle_speed = 0.03;
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	if (keycode == KEY_ARROW_LEFT)
		player->angle -= angle_speed;
	if (keycode == KEY_ARROW_RIGHT)
		player->angle += angle_speed;
	if (keycode == KEY_W)
	{
		player->x += cos_angle * speed;
		player->y += sin_angle * speed;
	}
	if (keycode == KEY_S)
	{
		player->x -= cos_angle * speed;
		player->y -= sin_angle * speed;
	}
	if (keycode == KEY_A)
	{
		player->x += sin_angle * speed;
		player->y -= cos_angle * speed;
	}
	if (keycode == KEY_A)
	{
		player->x -= sin_angle * speed;
		player->y += cos_angle * speed;
	}
	if (keycode == KEY_ESC)
		close_game(player->game);
}

static int	handle_keypress(int	keycode, t_player	*player)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A || keycode == KEY_D || keycode == KEY_ESC || keycode == KEY_ARROW_LEFT || keycode == KEY_ARROW_RIGHT)
		move_player(player, keycode);
	return (0);
}

/*	if (keycode == KEY_W)
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
	return (0);*/

// void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)
void	setup_hooks(t_game *game)
{
	mlx_hook(game->mlx_window, ON_KEYDOWN, 1L << 0, handle_keypress, game);
	mlx_hook(game->mlx_window, ON_DESTROY, 0, handle_keypress, game);
}



