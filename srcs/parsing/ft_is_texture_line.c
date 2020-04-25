/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_texture_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 15:44:48 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/25 15:45:00 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int ft_is_texture_line(char *line)
{
    char **line_splitted;

    line_splitted = ft_split(line, ' ');
    if (ft_check_extension(line_splitted[1], ".xpm"))
    {
        ft_split_clean(line_splitted);
        return (1);
    }
    ft_split_clean(line_splitted);
    return (0);
}