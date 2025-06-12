/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:09:27 by dtanski           #+#    #+#             */
/*   Updated: 2025/06/12 16:16:59 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH	1280
# define HEIGHT	720
# define PI		3.14159265359
# define DEBUG	0
# define BLOCK 64
# define TEX_SIZE 64

# include "../libs/libft/libft.h"
# include "./key_alias.h"
# include "./err_msgs.h"
# include "./structs.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>

// Filling a pixel with color
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);

// Setting up hooks
void	setup_hooks(t_game *game);

// Initialize data
void	data_init(t_game *game);
void	init_textures(t_game *game);
void	init_clean_img_data(t_img_data *img);
void	init_mlx_data(t_game *game);
void	init_texture_img(t_game *game, t_img_data *image, char *path);
void	init_move_comp(t_mov_comp *move_comp);

// Map utils
int		is_wall(t_point point, t_game *game);
// int is_wall(float x, float y, t_game *game);
float	distance(float x, float y);
float	fixed_dist(t_point *point1, t_point *point2,
			float ray_angle, t_game *game);
//////////////
float	map_width(char **map);
float	map_height(char **map);
int		check_dist(t_point *point, int *map_x, int *map_y, t_game *game);

// Player movement
void	reset_mouse_position(t_game *game);
int		mouse_move(int x, int y, t_game *game);
void	update_player_direction(t_player *player);
void	rotate_player(t_player *player, int keycode);
void	move_player(t_player *player, int keycode);

// Drawing a map
void	draw_square(t_point	*point, int size, int color, t_game *game);
void	draw_full_square(t_point *point, int size, int color, t_game *game);
void	draw_map(t_game *game);
void	draw_textured_column(t_game *game, t_d_params *draw_params, int i);
void	draw_floor_ceiling(t_game *game, int x, int wall_start, int wall_end);

// Raycaster
void	draw_line(t_player *player, t_game *game, float start_x, int i);
void	prep_to_render(t_ray_params *ray_params);
void	prep_structs_and_dda(t_ray_params *ray_params,
			t_d_params *draw_params, float start_x, t_player *player);
void	calculate_step_and_side_dist(t_ray_params *ray_params);
void	calculate_wall_render_params(t_ray_params *ray_params,
			t_d_params	*draw_params, int screen_x);

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
int		get_textures_color(t_game *game, t_tex_info *textures,
			char *line, int i);
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
int		handle_exit_x(t_game *game);
////free_data.c
void	free_tab(void **tab);
int		free_data(t_game *game);

#endif