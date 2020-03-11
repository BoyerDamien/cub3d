/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_normalise.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:07:51 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/11 16:17:37 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

t_vector ft_vec_normalise(t_vector *vec)
{
	t_vector new;

	new = vec->div_scalar(vec, vec->length(vec));
	return (new);
}
