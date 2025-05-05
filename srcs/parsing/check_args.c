/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:23:55 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/05/05 22:52:42 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

//Checking if directory name was given instead of file name.
//Flag __O_DIRECTORY is a standard macro from fcntl.h library.
static bool	is_dir(char *arg)
{
	int		fd;
	bool	out;

	fd = open(arg, __O_DIRECTORY);
	out = false;
	if (fd >= 0)
	{
		close(fd);
		out = true;
	}
	return (out);
}







//CHecking if the map file is proper one. 
//Does file descriptor is valid also.

int	check_file(char *arg, bool cub)
{
	int	fd;

	if (is_dir(arg))
		return (err_msg(arg, ERR_FILE_IS_DIR, FAILURE));//////
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (err_msg(arg, strerror(errno), FAILURE));/////
	close(fd);
}