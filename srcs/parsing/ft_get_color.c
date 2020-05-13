/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 10:22:23 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 15:46:18 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color	ft_get_color(char *path, char *charcode)
{
	char	*line;
	char	*n_path;
	int		r;
	int		g;
	int		b;

	line = ft_tag_line(path, charcode);
	n_path = ft_move_until(line, "is", ft_isdigit);
	r = ft_atoi(n_path);
	n_path = ft_move_until(ft_move_until(n_path, "not", ft_isdigit),\
							"is", ft_isdigit);
	g = ft_atoi(n_path);
	n_path = ft_move_until(ft_move_until(n_path, "not", ft_isdigit),\
							"is", ft_isdigit);
	b = ft_atoi(n_path);
	free(line);
	return (ft_color(r, g, b));
}
