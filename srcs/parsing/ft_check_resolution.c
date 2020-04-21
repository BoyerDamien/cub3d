/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_resolution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 18:04:04 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/21 19:23:37 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int is_resolution_line(char *line){
    while(*line && !ft_isalpha(*line))
        line++;
    if (*line == 'R' && *(line + 1) == ' ')
        return(1);
    return (0);
}

static int test_size(char *line){
    char **line_splitted;
    int i;

    i = 0;
    line_splitted = ft_split(line, ' ');
    while (line_splitted && line_splitted[i])
        i++;
    if (i == 3)
    {
        i--;
        while ( i  > 0 )
        {
            if (ft_atoi((const char *)line_splitted[i]) <= 0)
            {
                ft_split_clean(line_splitted);
                return (0);
            }
            i--;
        }
        ft_display_process_status("Check resolution", "ok");
        ft_split_clean(line_splitted);
        return (1);
    }
    ft_split_clean(line_splitted);
    return (0);
}

int ft_check_resolution(char *path)
{
    int fd;
    char *line;

    if ((fd = open(path, O_RDONLY)) != -1){
        while(get_next_line(fd, &line) == 1)
        {
            if (is_resolution_line(line) && test_size(line)){
                free(line);
                close(fd);
                return (1);
            }
            free(line);
        }
    }
    close(fd);
    ft_display_process_status("Check resolution", "error");
    ft_display_error("No valid resolution line found", __func__);
    exit(EXIT_FAILURE);
    return (0);
}