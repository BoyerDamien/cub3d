/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_dot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:16:59 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 16:28:35 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

double	ft_vec_dot(t_vector *vec1, t_vector vec2)
{
	double result;

	result = 0.0;
	result += vec1->x * vec2.x;
	result += vec1->y * vec2.y;
	result += vec1->z * vec2.z;
	return (result);
}

