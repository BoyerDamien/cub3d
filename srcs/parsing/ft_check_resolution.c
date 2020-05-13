/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_resolution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 18:04:04 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 15:40:06 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	test_size(char *line, int n)
{
	if (line && *line && n < 2)
	{
		if (!ft_isdigit(*line))
			line = ft_move_until(line, "is", ft_isdigit);
		if (!ft_isdigit(*line) || !(ft_atoi(line) > 0))
			return (0);
		if (ft_isdigit(*line))
		{
			line = ft_move_until(line, "not", ft_isdigit);
			line = ft_move_until(line, "is", ft_isdigit);
			return (test_size(line, n + 1));
		}
	}
	return (!line && n == 2);
}

int			ft_check_resolution(char *path)
{
	char *line;

	if ((line = ft_tag_line(path, "R")) && test_size(line, 0))
	{
		free(line);
		return (1);
	}
	ft_display_process_status("Check resolution", "error");
	ft_display_error("No valid resolution line found", __func__);
	exit(EXIT_FAILURE);
	return (0);
}
