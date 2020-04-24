/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 09:11:41 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/22 14:52:12 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int is_texture_line(char *line)
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

int ft_check_one_texture(char *path, char *orientation)
{
    char *line;
    char *message_error;
    char *status;

    status = ft_strjoin("Check texture\t\t", orientation);
    if ((line = ft_tag_line(path, orientation, 2)) && is_texture_line(line))
    {
        ft_display_process_status(status, "ok");
        free(line);
        free(status);
        return (1);
    }
    message_error = ft_strjoin("No valid texture found for ", orientation);
    ft_display_process_status(status, "error");
    ft_display_error(message_error, __func__);
    free(message_error);
    free(status);
    return (0);
}

void ft_check_texture(char *path){
    static char *charcode[5] = { "NO", "SO", "WE", "EA", "S"};
    int i;

    i = 0;
    while( i < 5 ){
        if (!ft_check_one_texture(path, charcode[i]))
            exit(0);
        i++;
    }
}
