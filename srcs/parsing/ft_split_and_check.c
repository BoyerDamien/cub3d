/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_and_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 11:00:45 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/22 11:07:29 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int ft_split_and_check(char *str, int c, char *charcode, int n){
    char **str_splitted;
    int result;
    int i;

    i = 0;
    str_splitted = ft_split(str, c);
    while (str_splitted && str_splitted[i])
        i++;
    result = i == n && ft_str_isequal(str_splitted[0], charcode) ? 1 : 0;
    ft_split_clean(str_splitted);
    return (result);
}