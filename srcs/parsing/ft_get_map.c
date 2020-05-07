/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 11:48:07 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/07 09:06:48 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_map(char *line)
{
    line = ft_move_until(line, "not", ft_isspace);
    return (line && ft_isdigit(*line) ? 1 : 0);
}

t_list ft_get_map(char *path)
{
    char *line;
    int fd;
    t_list map;

    map = ft_list();
    line = NULL;
    if ((fd = open(path, O_RDONLY)) != -1)
    {
        while (get_next_line(fd, &line) == 1)
        {
            if (is_map(line))
                map.append(&map, line);
            else
                free(line);
        }
    }
    if (is_map(line))
        map.append(&map, line);
    else
        free(line);
    close(fd);
    map.iter(map.first, ft_convert_map);
    return (map);
}