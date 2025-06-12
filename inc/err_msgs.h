/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msgs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:35:46 by dtanski           #+#    #+#             */
/*   Updated: 2025/06/12 16:53:24 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_MSGS_H
# define ERR_MSGS_H

# define ERR_FILE_IS_DIR "Is a directory. Please input a valid file name."
# define ERR_FILE_NOT_CUB "Is not a .cub file."
# define ERR_FILE_NOT_XPM "Is not a .xpm file."
# define ERR_MALLOC "Memory allocation failed."
# define ERR_TEX_INVALID "Invalid textures."
# define ERR_INVALID_MAP "Wrong map file, please check data format."
# define ERR_FLOOR_CEILING "Wrong RGB values for floor or ceiling colors"
# define ERR_COLOR_CEILING "Wrong RGB values for ceiling color"
# define ERR_COLOR_FLOOR "Wrong RGB values for floor color"
# define ERR_MAP_MISSING "Map is missing. Provide valid map file."
# define ERR_MAP_WALLS "Map walls are missing. Check your map file."
# define ERR_MAP_ORDER "Map should be last in your map file."
# define ERR_MAP_SIZE "Map is too small."
# define ERR_INV_LETTER "Invalid letter in map file."
# define ERR_NUM_PLAYER "You can have only one player on the map."
# define ERR_PLAYER_DIR "Can't find player poition (N, S, E or W)."
# define ERR_PLAYER_POS "Wrong player position."
# define ERR_TEX_MISSING "Some textures are missing."
# define ERR_COLOR_MISSING "Floor or ceiling color is missing."
# define ERR_TEX_RGB_VAL "Invalid RGB value. Should be from 0 to 255."
# define ERR_MLX_IMG "Failed to initialize mlx image."

#endif