/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:26:09 by dtanski           #+#    #+#             */
/*   Updated: 2025/05/01 11:37:31 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

// void	draw_line(t_player *player, t_game *game, float start_x, int i)
// {
// 	t_point	*ray;
// 	float	cos_angle;
// 	float	sin_angle;
// 	float	dist;
// 	t_point	*player_pov;

// 	cos_angle = cos(start_x);
// 	sin_angle = sin(start_x);
// 	ray->y = player->y;
// 	ray->x = player->x;
// 	player_pov->y = player->y;
// 	player_pov->x = player->x;
// 	while (!touch(ray->x, ray->y, game))
// 	{
// 		if (DEBUG)
// 			my_mlx_pixel_put(game->img_data, ray->x, ray->y, 0xFF0000);
// 		ray->x += cos_angle;
// 		ray->y += sin_angle;
// 	}
// 	if (!DEBUG)
// 	{
// 		dist = fixed_dist(player_pov, ray, game);
// 		float	height = (BLOCK / dist) * (WIDTH / 2);
// 		while ((HEIGHT - height) / 2 < start_y + height)
// 		{
// 			my_mlx_pixel_put(game->img_data, i, start_y, 255);
// 			start_y++;
// 		}
// 	}
// }

void draw_line(t_player *player, t_game *game, float start_x, int i)
{
    float cos_angle;
    float sin_angle;
    t_point ray;
    t_point player_pov;

    cos_angle = cos(start_x);
    sin_angle = sin(start_x);

    // Ustawienie początkowych współrzędnych
    ray.x = player->x;
    ray.y = player->y;
    player_pov.x = player->x;
    player_pov.y = player->y;

    // Raycasting - przesuwanie promienia
    while (!touch(ray.x, ray.y, game))
    {
        if (DEBUG)
            my_mlx_pixel_put(game->img_data, ray.x, ray.y, 0xFF0000);
        ray.x += cos_angle;
        ray.y += sin_angle;
    }

    // Rysowanie kolumny w trybie raycastingu
    if (!DEBUG)
    {
        float dist = fixed_dist(&player_pov, &ray, game);
        float height = (BLOCK / dist) * (WIDTH / 2);
        int start_y = (HEIGHT - height) / 2;
        int end = start_y + height;

        while (start_y < end)
        {
            my_mlx_pixel_put(game->img_data, i, start_y, 255);
            start_y++;
        }
    }
}

// void	draw_line(t_player *player, t_game *game, float start_x, int i)
// {
// 	float	cos_angle;
// 	float	sin_angle;
// 	float	ray_x;
// 	float	ray_y;
// 	t_point	*ray;
// 	t_point	*player_pov;

// 	ray = malloc(sizeof(t_point));
// 	player_pov = malloc(sizeof(t_point));
// 	if (!ray || !player_pov)
// 		return ;
// 	cos_angle = cos(start_x);
// 	sin_angle = sin(start_x);
// 	ray_y = player->y;
// 	ray_x = player->x;
// 	player_pov->y = player->y;
// 	player_pov->x = player->x;
// 	while (!touch(ray_x, ray_y, game))
// 	{
// 		if (DEBUG)
// 			my_mlx_pixel_put(game->img_data, ray_x, ray_y, 0xFF0000);
// 		ray_x += cos_angle;
// 		ray_y += sin_angle;
// 	}
// 	if (!DEBUG)
// 	{
// 		float	dist = fixed_dist(player_pov, ray, game);
// 		float	height = (BLOCK / dist) * (WIDTH / 2);
// 		int	start_y = (HEIGHT - height) / 2;
// 		int	end = start_y + height;
// 		while (start_y < end)
// 		{
// 			my_mlx_pixel_put(game->img_data, i, start_y, 255);
// 			start_y++;
// 		}
// 	}
// }

void	draw_square(t_point	*point, int size, int color, t_game *game)
{
	int	x;
	int	y;
	int	i;

	y = point->y;
	x = point->x;
	i = -1;
	printf("Rysowanie bloku: map_x = %d, map_y = %d\n", x, y);
	printf("Współrzędne w pikselach: x = %f, y = %f, size = %d\n", point->x, point->y, BLOCK);
	while (++i < size)
		my_mlx_pixel_put(game->img_data, x + i, y, color);
	i = -1;
	while (++i < size)
		my_mlx_pixel_put(game->img_data, x, y + i, color);
	i = -1;
	while (++i < size)
		my_mlx_pixel_put(game->img_data, x + size, y + i, color);
	i = -1;
	while (++i < size)
		my_mlx_pixel_put(game->img_data, x + i, y + size, color);
}

// Wersja niekompletna do debugowania
void	draw_map(t_game *game)
{
	char	**map;
	int		color;
	int		y;
	int		x;
	t_point *point;

	point = malloc(sizeof(t_point));
	if (!point)
		return ;
	map = game->map_buffer;
	color = 0x0000FF;
	y = 0;

	while (map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if (map[y][x] == '1')
			{
				point->y = y * BLOCK;
				point->x = x * BLOCK;
				draw_square(point, BLOCK, color, game);
			}
			x++;
		}
		y++;
	}
}
