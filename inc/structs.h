/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:47:43 by dtanski           #+#    #+#             */
/*   Updated: 2025/06/12 15:19:05 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_game	t_game;

typedef struct s_point
{
	float	y;
	float	x;
}			t_point;

typedef struct move_components
{
	float	cos_angle;
	float	sin_angle;
	float	new_x;
	float	new_y;
	int		speed;
}			t_mov_comp;

typedef struct s_player
{
	float		x;
	float		y;
	float		angle;
	float		fov_x;
	float		fov_y;
	char		dir;
	t_mov_comp	move_comp;
	t_game		*game;
}				t_player;

typedef struct s_img_data
{
	void	*img;
	char	*addr;
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

typedef struct s_draw_params
{
	int		screen_x;
	int		start_y;
	int		end_y;
	int		wall_direction;
	float	wall_x;
	float	wall_height;
	int		wall_start;
	int		wall_end;
	int		screen_x_coord;
	int		draw_start_y;
	int		draw_end_y;
	int		wall_hit_direction;
	float	wall_hit_x_ratio;
	float	wall_display_height;
	int		tex_x;
	int		tex_y;
	float	step;
	int		original_start_y;
	int		color;
}	t_d_params;

typedef struct s_raycaster_params
{
	float	ray_dir_x;
	float	ray_dir_y;
	float	pos_x;
	float	pos_y;
	int		map_x;
	int		map_y;
	float	delta_dist_x;
	float	delta_dist_y;
	int		step_x;
	int		step_y;
	float	side_dist_x;
	float	side_dist_y;
	int		side;
	int		hit;
	int		wall_direction;
	float	wall_x;
	float	corrected_dist;
	float	wall_height;
	int		start_y;
	int		end_y;
	float	perp_wall_dist;
}	t_ray_params;

struct s_game
{
	void			*mlx_connection;
	void			*mlx_window;
	t_img_data		img_data;
	t_player		player;
	t_point			point;
	int				**textures;
	int				**texture_pxl;
	t_tex_info		tex_info;
	t_map_info		map_info;
	char			**map;
	t_d_params		draw_params;
	t_ray_params	ray_params;	
};

typedef struct s_texture_calc_params
{
	int		tex_x_coord;
	float	tex_y_increment_step;
	int		original_screen_start_y;
	int		final_draw_start_y;
	int		final_draw_end_y;
}	t_texture_calc_params;
