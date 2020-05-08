/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 12:07:05 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/08 17:50:13 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
