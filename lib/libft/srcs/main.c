/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:06:05 by dboyer            #+#    #+#             */
/*   Updated: 2020/02/03 12:15:26 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/libft.h"

void test(t_element *element)
{
	ft_printf("%s\n", element->content);
}

int	main(void)
{
	t_list list = ft_list();
	ft_add_back(&list, "test");
	ft_add_back(&list, "test2");
	ft_add_back(&list, "test3");
	ft_printf("%d\n", list.size);
	ft_list_iter(list.first, &test);
	t_list concat = ft_concat(list, list);
	ft_printf("%d\n", concat.size);
	ft_list_iter(concat.first, &test);
	ft_clear(&concat);
	ft_clear(&list);
	ft_printf("%d\n", list.size);
	return (0);
}
