/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isexist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 17:40:03 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/21 17:53:41 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int ft_isexist(char *path)
{
    int fd;
    int result;

    fd = open(path, O_RDONLY);
    result = 0;
    if (fd == -1 )
        ft_display_process_status("File path", "error");
    else{
        ft_display_process_status("File path", "ok");
        result = 1;
    }
    close(fd);
    return (result);
}