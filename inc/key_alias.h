/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_alias.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 17:54:50 by dtanski           #+#    #+#             */
/*   Updated: 2025/04/22 13:51:04 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Keycodes for MLX
#define KEY_ESC			65307
#define KEY_W			119
#define KEY_A			97
#define KEY_S			115
#define KEY_D			100
#define KEY_ARROW_UP	65362
#define KEY_ARROW_DOWN	65364
#define KEY_ARROW_LEFT	65361
#define KEY_ARROW_RIGHT	65363

// Hooking events
enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};