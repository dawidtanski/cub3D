/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_alias.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 17:54:50 by dtanski           #+#    #+#             */
/*   Updated: 2025/04/21 07:16:58 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Keycodes for MLX
#define KEY_ESC			53
#define KEY_W			13
#define KEY_A			0
#define KEY_S			1
#define KEY_D			2
#define KEY_ARROW_UP	126
#define KEY_ARROW_DOWN	125
#define KEY_ARROW_LEFT	123
#define KEY_ARROW_RIGHT	124

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