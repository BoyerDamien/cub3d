/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_dist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:29:36 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/09 13:44:12 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

double	ft_vec_dist(t_vector *vec1, t_vector vec2)
{
	t_vector diff;

	diff = vec1->sub(vec1, vec2);
	return (diff.length(&diff));
}
