/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:22:22 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 16:28:35 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	ft_vec_direction(t_vector *point, t_vector origin)
{
	t_vector diff;

	diff = point->sub(point, origin);
	return (diff.normalise(&diff));
}
