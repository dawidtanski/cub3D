/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:09:27 by dtanski           #+#    #+#             */
/*   Updated: 2025/04/22 16:15:34 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB_3D_H

# define	WIDTH	1280
# define	HEIGHT	720
# define	PI		3.14159265359


# include "../libs/libft/libft.h"
# include "./key_alias.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>	
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_game t_game;

typedef struct	s_player
{
	float	x;
	float	y;
	float	angle;
	t_game	*game;
}				t_player;

typedef struct	s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;

struct s_game
{
	void		*mlx_connection;
	void		*mlx_window;
	t_img_data	*img_data;
	t_player	*player;
	char		**map_buffer;

};
// Filling a pixel with color
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);

// Function to move player
// void	go_up(t_game *game);
// void	go_down(t_game *game);
// void	go_right(t_game *game);
// void	go_left(t_game *game);
// void	turn_left(t_game *game);
// void	turn_right(t_game *game);

// Setting up hooks
void	setup_hooks(t_game *game);

// Initialize data
void	data_init(char *map_path, t_game *game);

#endif