/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 09:11:41 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/07 09:06:48 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int ft_check_one_texture(char *path, char *orientation)
{
    char *line;
    char *message_error;
    char *status;

    status = ft_strjoin("Check texture\t\t", orientation);
    if ((line = ft_tag_line(path, orientation)) && ft_is_texture_line(line))
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
    while ( i < 5 ){
        if (!ft_check_one_texture(path, charcode[i]))
            exit(0);
        i++;
    }
}
