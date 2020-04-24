/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_resolution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 18:04:04 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/22 12:10:27 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int test_size(char *line)
{
    char **line_splitted;

    line_splitted = ft_split(line, ' ');

    if (ft_atoi((const char *)line_splitted[1]) <= 0 || ft_atoi((const char *)line_splitted[2]) <= 0)
    {
        ft_split_clean(line_splitted);
        return (0);
    }

    ft_display_process_status("Check resolution\t", "ok");
    ft_split_clean(line_splitted);
    return (1);
}

int ft_check_resolution(char *path)
{
    char *line;

    if ((line = ft_tag_line(path, "R", 3)) && test_size(line))
    {
        free(line);
        return (1);
    }
    ft_display_process_status("Check resolution", "error");
    ft_display_error("No valid resolution line found", __func__);
    exit(EXIT_FAILURE);
    return (0);
}