/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_extension_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 09:36:20 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/22 10:24:49 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int ft_test_extension_path(char *path, char *extension){
    char *last_point;
    
    last_point = ft_strrchr(path, '.');
    if (last_point && ft_str_isequal(last_point, extension) && ft_isexist(path)){
        return (1);
    }
    return (0);
}
