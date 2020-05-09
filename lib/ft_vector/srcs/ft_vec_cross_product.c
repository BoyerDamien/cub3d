/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_cross_product.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 10:48:10 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/09 13:49:53 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	ft_vec_cross_product(t_vector *vec1, t_vector vec2)
{
	t_vector result;

	result = ft_vector(0, 0, 0);
	result.x = vec1->y * vec2.z - vec1->z * vec2.y;
	result.y = vec1->z * vec2.x - vec1->x * vec2.z;
	result.z = vec1->x * vec2.y - vec1->y * vec2.x;
	return (result);
}
