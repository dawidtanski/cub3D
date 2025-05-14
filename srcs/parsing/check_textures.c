/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 21:39:37 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/05/14 22:13:46 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"


//Validates RGB values array.
//Values must be from 0 to 255.
static int	val_rgb(int *rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (err_msg_rgb_val(rgb[i], ERR_TEX_RGB_VAL, FAILURE));
		i++;
	}
	return (SUCCESS);
}

//Takes RGB array, separates values for R, G and B,
//conferts decimal values for hex.
//R byte is moved 16 bits.
//G byte is moved 8 bits.
//B byte stays on it's place.
static unsigned long	rgb_to_hex(int *rgb_tab)
{
	unsigned long	res;
	int				r;
	int				g;
	int				b;

	r = rgb_tab[0];
	g = rgb_tab[1];
	b = rgb_tab[2];
	res = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (res);
}

//Start textures validation process.
//First check if paths to all textures are correct.
//Check colors for ceiling and floor.
//Starts to validate textures files and RGB values for floor and ceiling.
int	val_textures(t_game *game, t_tex_info *textures)
{
	if (!textures->north || !textures->south || !textures->west
		|| !textures->east)
		return (err_msg(game->map_info.path, ERR_TEX_MISSING, FAILURE));
	if (!textures->floor || !textures->ceiling)
		return (err_msg(game->map_info.path, ERR_COLOR_MISSING, FAILURE));
	if (check_file(textures->north, false) == FAILURE
		|| check_file(textures->south, false) == FAILURE
		|| check_file(textures->west, false) == FAILURE
		|| check_file(textures->east, false) == FAILURE
		|| val_rgb(textures->floor) == FAILURE
		|| val_rgb(textures->ceiling) == FAILURE)
		return (FAILURE);
	textures->hex_floor = rgb_to_hex(textures->floor);
	textures->hex_ceiling = rgb_to_hex(textures->ceiling);
	return (SUCCESS);
}
