/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_border.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 15:19:35 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/11 19:48:43 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int is_valid_neighbour(t_element *element, int index, t_list *memory, char *neighbour)
{
	char *content;

	if (element)
	{
		content = (char *)(element->content);
		if (index < (int)ft_strlen(content) && ft_cinset(content[index], neighbour))
		{
			if (content[index] != 'D')
			{
				memory->append(memory, &element->index);
				memory->append(memory, &index);
			}
			return (1);
		}
	}
	return (0);
}

static t_element *back_element(t_list *memory, t_list *map)
{
	t_element *element;

	element = (memory->last)->previous;
	return (map->get(map, *((int *)(element->content))));
}

static int back_index(t_list *memory)
{
	int index;

	index = *((int *)(memory->last->content));
	memory->remove(memory, (memory->last)->previous);
	memory->remove(memory, memory->last);
	return (index);
}

static int test_border(t_element *element, int n_index, t_list *map, t_list *memory)
{
	char *content;
	int index;
	char *neighbour;

	index = n_index;
	content = (char *)element->content;
	neighbour = memory->size == 2 ? "1" : "1D";

	content[index] = content[index] == 'D' ? 'D' : 'X';
	if (content[index] && is_valid_neighbour(element, index + 1, memory, neighbour))
		return (test_border(element, index + 1, map, memory));
	if (index > 0 && is_valid_neighbour(element, index - 1, memory, neighbour))
		return (test_border(element, index - 1, map, memory));
	if (element->next && is_valid_neighbour(element->next, index, memory, neighbour))
		return (test_border(element->next, index, map, memory));
	if (element->previous && is_valid_neighbour(element->previous, index, memory, neighbour))
		return (test_border(element->previous, index, map, memory));
	if (memory->size >= 2 && content[index] == 'X')
		return (test_border(back_element(memory, map), back_index(memory), map, memory));
	if (memory->size >= 2 && content[index] == 'D')
		return (1);
	return (0);
}

void print(t_element *element)
{
	ft_printf("%s\n", (char *)element->content);
}

t_element *find_onset_element(t_element *element)
{
	char *content;
	int i;

	i = 0;
	if (element)
	{
		content = (char *)element->content;
		while (content[i])
		{
			if (ft_cinset(content[i], "NSEW"))
				return (element);
			i++;
		}
	}
	return (find_onset_element(element->next));
}
static void clear_map(t_element *element)
{
	int i;
	char *content;

	i = 0;
	content = (char *)element->content;
	while (content[i])
	{
		if (ft_cinset(content[i], "DX"))
			content[i] = '1';
		i++;
	}
}

static int check_right(t_list *map, t_element *element, t_list *memory)
{
	int i;
	int j;
	char *content;

	i = 0;
	j = 0;
	content = (char *)element->content;
	while (content[i] && !ft_cinset(content[i], "NSEW"))
		i++;
	while (content[i])
	{
		printf("content = %s -- i = %d\n", content, i);
		if (content[i] == '1')
			j = i;
		i++;
	}
	if (j > 0 && content[j] == '1')
	{
		content[j] = 'D';
		return (test_border(element, j, map, memory));
	}
	printf("content = %s -- j = %d\n", content, j);
	return (0);
}

static int check_left(t_list *map, t_element *element, t_list *memory)
{
	int i;
	char *content;

	i = 0;
	content = (char *)element->content;
	while (content[i])
	{
		if (content[i] == '1')
		{
			printf("content = %s -- i = %d\n", content, i);
			content[i] = 'D';
			return (test_border(element, i, map, memory));
		}
		i++;
	}
	return (0);
}

static int is_closed(t_list *map, t_element *element, t_list *memory)
{
	int result;

	result = 0;
	result += check_right(map, element, memory);
	map->iter(map->first, clear_map);
	memory->clear(memory);
	result += check_left(map, element, memory);
	map->iter(map->first, clear_map);
	memory->clear(memory);
	return (result == 2);
}

int test_map_border(t_list *map)
{
	t_element *element;
	t_list memory;
	int result;
	int i;
	int j;

	i = 0;
	j = 0;
	memory = ft_list();
	element = find_onset_element(map->first);
	if (is_closed(map, element, &memory))
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
	map->iter(map->first, print);
	return (result);
}