/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isequal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 09:38:57 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 15:54:12 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_str_isequal(char *str1, char *str2)
{
	if (str1 && str2)
	{
		if (ft_strncmp(str1, str2, ft_strlen(str1)) == 0 && \
				ft_strncmp(str1, str2, ft_strlen(str2)) == 0)
			return (1);
	}
	return (0);
}
