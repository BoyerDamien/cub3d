/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 10:51:52 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/15 10:52:18 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline int	is_color(int c)
{
	return (ft_isdigit(c) || c == '-');
}

static inline int	is_correct(int color)
{
	return (color >= 0 && color <= 255);
}

static inline int	test_color_line(char *line, int n)
{
	if (line && *line && n < 3)
	{
		if (!is_color(*line))
			line = ft_move_until(line, "is", is_color);
		if (!is_color(*line) || !(is_correct(ft_atoi(line))))
			return (0);
		else
		{
			line = ft_move_until(line, "not", is_color);
			return (test_color_line(line, n + 1));
		}
	}
	return (!line && n == 3);
}

static inline int	ft_check_one_color(char *path, char *charcode)
{
	char *line;
	char *message;

	message = ft_strjoin("Check color\t\t", charcode);
	if ((line = ft_tag_line(path, charcode)) && test_color_line(line, 0))
	{
		ft_display_process_status(message, "ok");
		free(message);
		free(line);
		return (1);
	}
	ft_display_process_status(message, "error");
	ft_display_error("No valid color was found", __func__);
	free(message);
	free(line);
	return (0);
}

void				ft_check_color(char *path)
{
	static char *charcode[2] = {"F", "C"};
	int			i;

	i = 0;
	while (i < 2)
	{
		if (!ft_check_one_color(path, charcode[i]))
			exit(0);
		i++;
	}
}
