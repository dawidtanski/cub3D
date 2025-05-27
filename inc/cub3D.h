/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:09:27 by dtanski           #+#    #+#             */
/*   Updated: 2025/05/27 22:43:45 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define	WIDTH	1280
# define	HEIGHT	720
# define	PI		3.14159265359
# define	DEBUG	1
# define	BLOCK 64
# define 	TEX_SIZE 64//chyba, ze to to samo co BLOCK?


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
# define ERR_MALLOC "Error: memory allocation failed."
# define ERR_TEX_INVALID "Error: invalid textures."
# define ERR_INVALID_MAP "Error: wrong map file, please check data format."
# define ERR_FLOOR_CEILING "Error: wrong RGB values for floor or ceiling colors"
# define ERR_COLOR_CEILING "Error: wrong RGB values for ceiling color"
# define ERR_COLOR_FLOOR "Error: wrong RGB values for floor color"
# define ERR_MAP_MISSING "Error: map is missing. Please provide valid map file."
# define ERR_MAP_WALLS "Error: map walls are missing. Please check your map file."
# define ERR_MAP_ORDER "Error: map shluld be last in your map file."
# define ERR_MAP_SIZE "Error: map is too small."
# define ERR_INV_LETTER "Error: invalid letter in map file."
# define ERR_NUM_PLAYER "Error: you can have only one player on the map."
# define ERR_PLAYER_DIR "Error: can't find player poition. Needs N, S, E or W chars."
# define ERR_PLAYER_POS "Error: wrong player position."
# define ERR_TEX_MISSING "Error: some textures are missing."
# define ERR_COLOR_MISSING "Error: flor or ceiling color is missing."
# define ERR_TEX_RGB_VAL "Error: invalid RGB value. Should be from 0 to 255."
# define ERR_MLX_IMG "Error: failed to initialize mlx image."

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
	float	fov_x;
	float	fov_y;
	char	dir;
	t_game	*game;
}				t_player;

typedef struct	s_img_data
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;

typedef struct s_map_info
{
	int			fd;
	int			line_count;
	char		*path;
	char		**file;
	int			height;
	int			width;
	int			index_end_of_map;
}	t_map_info;

typedef struct s_tex_info
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_tex_info;

typedef struct s_game
{
	void		*mlx_connection;
	void		*mlx_window;
	t_img_data	img_data;
	t_player	player;
	char		**map_buffer;
	int			**textures;
	int			**texture_pxl;
	t_tex_info	tex_info;
	t_map_info	map_info;
	char		**map;
}	t_game;

// Filling a pixel with color
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);

// Setting up hooks
void	setup_hooks(t_game *game);

// Initialize data
void	data_init(char *map_path, t_game *game);
void	init_textures(t_game *game);
void	init_tex_info(t_tex_info *textures);
void	init_clean_img(t_img_data *img);

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

//error_handling.c
int		err_msg(char *input, char *str, int err_code);
int		err_msg_rgb_val(int input, char *str, int err_code);

//Parsing
////check_args.c
int		check_file(char *arg, bool cub);
////parse_data.c
void	parse_data(char *path, t_game *game);
////get_file_data.c
int		get_file_data(t_game *game, char **map);
////get_textures_color.c
int		get_textures_color(t_game *game, t_tex_info *textures, char *line, int i);
////create_map.c
int		create_map(t_game *game, char **file, int i);
////parsing_utils.c
size_t	find_len(t_map_info *map, int i);
bool	to_skip(char c);
int		is_a_white_spc(char c);
////check_map_utils.c
int		chck_map_sides(t_map_info *map, char **map_tab);
////check_map.c
int		chck_map(t_game *game, char **map_tab);
////check_textures.c
int		val_textures(t_game *game, t_tex_info *textures);
////set_player_dir.c
void	set_player_dir(t_game *game);

//Exiting the game
////exit.c
void	ft_exit(t_game *game, int code);
int		exit_game(t_game *game);
////free_data.c
void	free_tab(void **tab);
int		free_data(t_game *game);

#endif