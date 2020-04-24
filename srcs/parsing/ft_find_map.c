/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 15:43:23 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/24 17:52:17 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int is_map(char *line)
{
    line = ft_move_until(line, "not", ft_isspace);
    return (line && ft_isdigit(*line) ? 1 : 0);
}

static void print(t_element *element)
{
    printf("|%s| \n", (char *)(element->content));
}

static int apply_test(t_list *map)
{
    if (test_map_border(map) && test_map_content(map))
    {
        ft_printf("\nMap: \n\n");
        map->iter(map->first, print);
        return (1);
    }
    return (0);
}

void ft_find_map(char *path)
{
    char *line;
    int fd;
    t_list map;
    int result;

    result = 0;
    map = ft_list();
    ft_display_message("Check map...");
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
    result = apply_test(&map) ? 1 : 0;
    map.clear(&map);
    close(fd);
    free(line);
    if (!result)
        exit(EXIT_FAILURE);
}