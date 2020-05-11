/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 15:07:07 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/10 11:01:11 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void ft_convert_map(t_element *element){
    int i;
    char *content;

    i = 0;
    content = (char *)element->content;
    while (content[i])
    {
        if (content[i] == ' ')
            content[i] = '0';
        i++;
    }
}