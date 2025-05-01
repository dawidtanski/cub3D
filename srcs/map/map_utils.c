/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:55:23 by dtanski           #+#    #+#             */
/*   Updated: 2025/05/01 11:05:04 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static float	map_width(char **map)
{
	float	width;
	int		i;
	
	i = 0;
	width = ft_strlen(map[0]);
	while (ft_strlen(map[i]) > width)
	{
		width = ft_strlen(map[i]);
		i++;
	}
	return (width);
}

static float	map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return ((float)height);
}

int	is_wall(float x, float y, t_game *game)
{
	int	map_x; 
	int	map_y;

	map_x = (int)x / BLOCK;
	map_y = (int)y / BLOCK;
	if (map_x < 0 || map_y < 0 || map_x > map_width(game->map_buffer) || map_y > map_height(game->map_buffer))
		return (1);
	if (game->map_buffer[map_y][map_x] == '1')
		return (1);
	return (0);
}

// Obliczanie dystansu między 2 punktami
float	distance(float x, float y)
{
	return sqrt(x * x + y * y);
}

// Korekta perspektywy
float	fixed_dist(t_point *point1, t_point *point2, t_game *game)
{
	float	delta_x;
	float	delta_y;
	float	angle;
	float	fix_dist;

	delta_x = point2->x - point1->x;
	delta_y = point2->y - point1->y;
	angle = atan2((delta_y), delta_x) - game->player->angle;
	fix_dist = distance(delta_x, delta_y) * cos(angle);
	return (fix_dist);
}