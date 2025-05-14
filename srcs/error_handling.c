/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:24:03 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/05/05 22:48:55 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

//Puts an error message to standard erro.
int	err_msg(char *input, char *str, int err_code)
{
	ft_putstr_fd("cub3d: Error", 2);
	if (input)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(input, 2);
	}
	if (str)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
	}
	ft_putstr_fd("\n", 2);
	return (err_code);
}

//Similar to err_msg but used for textures checking.
//There we have RGB color values, instead of char arguments.
int	err_msg_rgb_val(int input, char *str, int err_code)
{
	ft_putstr_fd("cub3d: Error: ", 2);
	ft_putnbr_fd(input, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (err_code);
}
