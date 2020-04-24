/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isequal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 09:38:57 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/22 10:23:48 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int ft_str_isequal(char *str1, char *str2 ){
    if (ft_strncmp(str1, str2, ft_strlen(str1)) == 0 && \
    ft_strncmp(str1, str2, ft_strlen(str2)) == 0)
    return (1);
    return (0);
}