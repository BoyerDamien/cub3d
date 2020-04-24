/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 16:51:12 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/24 17:41:03 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void clean_map(t_element *element){
    int i;
    char *content;

    i = 0;
    if ( element ){
        content = ((char *)element->content);
        while (content[i]){
            content[i] = ft_cinset(content[i], "XD") ? '1' : content[i];
            i++;
        }
    }
    if (element->next)
        clean_map(element->next);
}

static int test_content(t_element *element){
    int i;
    char *content;

    i = 0;
    if (element){
        content = ((char *)element->content);
        while (content[i]){
            if (!ft_cinset(content[i], "NSEW012 "))
                return (0);
            i++;
        }
    }
    if (element->next)
        return (test_content(element->next));
    return (1);
}

int test_map_content(t_list *map)
{   
    clean_map(map->first);
    if (test_content(map->first)){
        ft_display_process_status("Map content", "ok");
        return (1);
    }
    else{
        ft_display_process_status("Map content", "error");
        ft_display_error("Your map contains a non valid character", __func__);
        return (0);
    }
}
