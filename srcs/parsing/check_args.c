/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:23:55 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/05/22 18:12:08 by pjedrycz         ###   ########.fr       */
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

// //Checking if given file is correct file type. 
// static bool is_corr_file_type(char *arg, char *f_type)
// {
// 	size_t	len;
// 	int		i;
// 	int		j;

// 	len = ft_strlen(arg);
// 	i = len - 4;
// 	j = 0;
// 	while (*arg && *f_type && (arg[i] == f_type[j]))
// 	{
// 		i++;
// 		j++;
// 	}
// 	if ((unsigned char)(arg[i]) - (unsigned char)(f_type[j]) == 0)
// 		return (true);
// 	else
// 		return (false);
// }

static bool	is_cub_file(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if ((arg[len - 3] != 'c' || arg[len - 2] != 'u'
			|| arg[len - 1] != 'b'
			|| arg[len - 4] != '.'))
		return (false);
	return (true);
}

static bool	is_xpm_file(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if ((arg[len - 3] != 'x' || arg[len - 2] != 'p'
			|| arg[len - 1] != 'm'
			|| arg[len - 4] != '.'))
		return (false);
	return (true);
}

//Checking if the map file is proper one. 
//Does file descriptor is valid also.
int	check_file(char *arg, bool cub)
{
	int	fd;

	if (is_dir(arg))
		return (err_msg(arg, ERR_FILE_IS_DIR, FAILURE));
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (err_msg(arg, strerror(errno), FAILURE));
	close(fd);
	if (cub && !is_cub_file(arg))
		return (err_msg(arg, ERR_FILE_NOT_CUB, FAILURE));
	if (!cub && !is_xpm_file(arg))
		return (err_msg(arg, ERR_FILE_NOT_XPM, FAILURE));
	return (SUCCESS);
}
