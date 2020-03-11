/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:17:22 by dboyer            #+#    #+#             */
/*   Updated: 2020/01/23 17:17:58 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_element	*ft_new_element(void *content)
{
	t_element *new;

	if (!(new = (t_element *)malloc(sizeof(t_element))))
		return (NULL);
	new->content = content;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}
