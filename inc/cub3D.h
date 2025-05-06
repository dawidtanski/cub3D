/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:09:27 by dtanski           #+#    #+#             */
/*   Updated: 2025/05/06 19:09:25 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB_3D_H

# define	WIDTH	1280
# define	HEIGHT	720
# define	PI		3.14159265359
# define	DEBUG	1
# define	BLOCK 64


# include "../libs/libft/libft.h"
# include "./key_alias.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>//////Czy na pewno możemy? Zdaje się, że tak bo false / true często już używaliśmy w naszych projektach.

//Error messages
# define ERR_FILE_IS_DIR "Is a directory. Please input a valid file name."
# define ERR_FILE_NOT_CUB "Is not a .cub file."
# define ERR_FILE_NOT_XPM "Is not a .xpm file."


//Helper values definitions (for parser) - enums

enum e_parse_summary
{
	SUCCESS = 0,
	FAILURE = 1,
	ERROR = 2,
	STOP = 3,
	CONTINUE = 4
};

enum e_textures_direction
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

//Structures

typedef struct s_game t_game;

typedef struct s_point
{
	float	y;
	float	x;
}			t_point;


typedef struct	s_player
{
	float	x;
	float	y;
	float	angle;
	t_game	*game;
}				t_player;

typedef struct	s_img_data
{
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

// Setting up hooks
void	setup_hooks(t_game *game);

// Initialize data
void	data_init(char *map_path, t_game *game);

// Map utils
int		is_wall(float x, float y, t_game *game);
float	distance(float x, float y);
float	fixed_dist(t_point *point1, t_point *point2, t_game *game);

// Event handling
int		touch(float px, float py, t_game *game);

// Drawing a map
void	draw_line(t_player *player, t_game *game, float start_x, int i);
void	draw_square(t_point	*point, int size, int color, t_game *game);
void	draw_map(t_game *game);

// Cleaning an image
void	clear_image(t_game *game);

//Parsing
////error_handling.c
int		err_msg(char *input, char *str, int err_code);
int		err_msg_rgb_val(int input, char *str, int err_code);
////check_args.c
int		check_file(char *arg, bool cub);
////exit.c
void	ft_exit(t_game *game, int code);
int		exit_game(t_game *game)

#endif