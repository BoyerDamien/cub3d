/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:25:44 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 16:30:55 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

static inline void init_method(t_vector *new)
{
	new->add = ft_vec_add;
	new->sub = ft_vec_sub;
	new->mul = ft_vec_mul;
	new->div = ft_vec_div;
	new->dot = ft_vec_dot;
	new->add_scalar = ft_vec_add_scalar;
	new->sub_scalar = ft_vec_sub_scalar;
	new->mul_scalar = ft_vec_mul_scalar;
	new->div_scalar = ft_vec_div_scalar;
	new->length = ft_vec_length;
	new->direction = ft_vec_direction;
	new->update = ft_vec_update;
	new->normalise = ft_vec_normalise;
	new->dist = ft_vec_dist;
}

t_vector	ft_vector(double x, double y, double z)
{
	t_vector new;

	new.x = x;
	new.y = y;
	new.z = z;
	init_method(&new);
	return (new);
}
