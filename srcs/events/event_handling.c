/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 17:51:41 by dtanski           #+#    #+#             */
/*   Updated: 2025/04/30 10:56:32 by dtanski          ###   ########.fr       */
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
	float	new_x;
	float	new_y;

	speed = 3;
	angle_speed = 0.03;
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	new_x = player->x;
	new_y = player->y;
	if (keycode == KEY_ARROW_LEFT)
		player->angle -= angle_speed;
	if (keycode == KEY_ARROW_RIGHT)
		player->angle += angle_speed;
	if (keycode == KEY_W)
	{
		new_x += cos_angle * speed;
		new_y += sin_angle * speed;
	}
	if (keycode == KEY_S)
	{
		new_x -= cos_angle * speed;
		new_y -= sin_angle * speed;
	}
	if (keycode == KEY_A)
	{
		new_x -= sin_angle * speed;
		new_y += cos_angle * speed;
	}
	if (keycode == KEY_D)
	{
		new_x += sin_angle * speed;
		new_y -= cos_angle * speed;
	}
	if (!is_wall(new_x, new_y, player->game))
    {
        player->x = new_x; // Aktualizuj pozycję gracza tylko, jeśli nie ma kolizji
        player->y = new_y;
    }
	
	if (keycode == KEY_ESC)
		close_game(player->game);
}

static int	handle_keypress(int	keycode, t_game	*game)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A || keycode == KEY_D || keycode == KEY_ESC || keycode == KEY_ARROW_LEFT || keycode == KEY_ARROW_RIGHT)
		move_player(game->player, keycode);
	return (0);
}


// void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)
void	setup_hooks(t_game *game)
{
	mlx_hook(game->mlx_window, ON_KEYDOWN, 1L << 0, handle_keypress, game);
	mlx_hook(game->mlx_window, ON_DESTROY, 0, handle_keypress, game);
}

int	touch(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = px / BLOCK;
	y = py / BLOCK;
	// printf("Checking touch at x: %d, y: %d\n", x, y);

    // if (x < 0 || y < 0 || y >= map_height(game->map_buffer) || x >= map_width(game->map_buffer))
    // {
    //     printf("Out of bounds: x: %d, y: %d\n", x, y);
    //     return (1);
    // }
	if (game->map_buffer[y][x] == '1')
		return (1);
	return (0);
}

