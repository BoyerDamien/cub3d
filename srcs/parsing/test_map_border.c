/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_border.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 15:19:35 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/07 09:06:48 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_valid_neighbour(t_element *element, int index, t_list *memory)
{
    char *content;

    if (element && index >= 0)
    {
        content = (char *)(element->content);
        if (index < (int)ft_strlen(content) && ft_cinset(content[index], "1D"))
        {
            memory->append(memory, &element->index);
            memory->append(memory, &index);
            return (1);
        }
    }
    return (0);
}

t_element *back_element(t_list *memory, t_list *map)
{
    t_element *element;

    element = (memory->last)->previous;
    return (map->get(map, *((int *)(element->content))));
}

int back_index(t_list *memory)
{
    int index;

    index = *((int *)(memory->last->content));
    memory->remove(memory, (memory->last)->previous);
    memory->remove(memory, memory->last);
    return (index);
}

int test_border(t_element *element, int n_index, t_list *map, t_list *memory)
{
    char *content;
    int index;

    index = n_index;
    content = (char *)element->content;
    if (ft_cinset(content[index], "1X"))
    {
        content[index] = 'X';
        if (is_valid_neighbour(element, index + 1, memory))
            return (test_border(element, index + 1, map, memory));
        if (is_valid_neighbour(element, index - 1, memory))
            return (test_border(element, index - 1, map, memory));
        if (element->next && is_valid_neighbour(element->next, index, memory))
            return (test_border(element->next, index, map, memory));
        if (element->previous && is_valid_neighbour(element->previous, index, memory))
            return (test_border(element->previous, index, map, memory));
    }
    if (content[index] == 'X' && memory->size > 2)
        return (test_border(back_element(memory, map), back_index(memory), map, memory));
    if (content[index] == 'D' && memory->size > 2)
        return (1);
    return (0);
}

int test_map_border(t_list *map)
{
    t_element *element;
    t_list memory;
    int result;
    int i;

    i = 0;
    memory = ft_list();
    element = map->first;
    while (((char *)element->content)[i] != '1')
        i++;
    ((char *)element->content)[i] = 'D';
    if (test_border(element, i + 1, map, &memory))
    {
        ft_display_process_status("Map border", "ok");
        result = 1;
    }
    else
    {
        ft_display_process_status("Map border", "error");
        ft_display_error("Your map is not closed", __func__);
        result = 0;
    }
    memory.clear(&memory);
    return (result);
}