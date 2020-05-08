/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:16:59 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 16:28:35 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	ft_vec_add(t_vector *vec1, t_vector vec2)
{
	t_vector new;

	new = ft_vector(0,0,0);
	new.x = vec1->x + vec2.x;
	new.y = vec1->y + vec2.y;
	new.z = vec1->z + vec2.z;
	return (new);
}

