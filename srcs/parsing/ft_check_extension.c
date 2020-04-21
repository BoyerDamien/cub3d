/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 17:02:30 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/21 17:35:18 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int ft_check_extension(char *filename)
{
    char **file_splitted;
    int result;
    int i;

    i = 0;
    result = 0;
    file_splitted = ft_split(filename, '.');
    while (file_splitted && file_splitted[i])
        i++;
    if (i == 2 && ft_strncmp(file_splitted[1], "cub", 3) == 0\
    && ft_strncmp(file_splitted[1], "cub", ft_strlen(file_splitted[1])) == 0)
    {
        ft_display_process_status("Extension .cub","ok");
        result = 1;
    }
    else
        ft_display_process_status("Extension .cub","error");
    ft_split_clean(file_splitted);
    return (result);
}