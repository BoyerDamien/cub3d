/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 18:31:17 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/15 18:45:15 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_line(char *line)
{
	int i;

	i = 0;
	while (*line)
	{
		if (ft_isalpha(*line))
			i++;
		line++;
	}
	return (!(i > 1));
}