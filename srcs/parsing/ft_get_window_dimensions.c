/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_window_dimensions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 19:00:32 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/07 09:06:48 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector ft_get_window_dimensions(char *path){
	char *line;
	int height;
	int width;

	line = ft_tag_line(path, "R");
	width = ft_atoi(ft_move_until(line, "is", ft_isdigit));
	height = ft_atoi((ft_move_until(ft_move_until(line, "not", ft_isdigit), "is", ft_isdigit)));
	free(line);
	return (ft_vector(width, height, 0));
}