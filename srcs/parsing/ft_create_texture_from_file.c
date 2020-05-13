/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_texture_from_file.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 19:29:48 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 15:43:09 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	ft_create_texture_from_file(char *path, char *charcode,\
							t_window *window)
{
	char		*line;
	t_texture	texture;
	char		*n_path;

	line = ft_tag_line(path, charcode);
	n_path = ft_move_until(line, "is", ft_isspace);
	n_path = ft_move_until(n_path, "not", ft_isspace);
	texture = ft_texture(window->mlx_ptr, n_path);
	free(line);
	return (texture);
}
