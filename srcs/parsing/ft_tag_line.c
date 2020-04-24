/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tag_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 11:32:24 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/22 12:52:06 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char *ft_tag_line(char *path, char *charcode, int n){
    int fd;
    char *line;
    
    if ((fd = open(path, O_RDONLY)) != -1){
        while (get_next_line(fd, &line) == 1){
            if (ft_split_and_check(line, ' ', charcode, n)){
                close(fd);
                return (line);
            }
            free(line);
        }
    }
    close(fd);
    return (NULL);
}