/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:08:34 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/05/07 21:22:40 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

//Free memory for any array.
void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

//Frees memory used for struct with texture informations.
static void	free_tex_info(t_tex_info *textures)
{
	if (textures->north)
		free(textures->north);
	if (textures->south)
		free(textures->south);
	if (textures->west)
		free(textures->west);
	if (textures->east)
		free(textures->east);
	if (textures->floor)
		free(textures->floor);
	if (textures->ceiling)
		free(textures->ceiling);
}

//Frees memory used in struct with game data (s_game).
static void	free_map(t_game *game)
{
	if (game->map_info.fd > 0)
		close(game->map_info.fd);
	if (game->map_info.file)
		free_tab((void **)game->map_info.file);
	if (game->map)
		free_tab((void **)game->map);
}

//Initialize process of freeing memory for all game map data type
int	free_data(t_game *game)
{
	if (game->textures)
		free_tab((void **)game->textures);
	if (game->texture_pxl)
		free_tab((void **)game->texture_pxl);
	free_tex_info(&game->tex_info);
	free_map(game);
	return (FAILURE);
}
