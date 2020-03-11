/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_div_scalar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:16:59 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/11 16:17:37 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

t_vector	ft_vec_div_scalar(t_vector *vec1, double scalar)
{
	t_vector new;

	new = ft_vector(0, 0, 0);
	new.x = vec1->x / scalar;
	new.y = vec1->y / scalar;
	new.z = vec1->z / scalar;
	return (new);
}

