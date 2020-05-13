/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_and_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 11:00:45 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 15:53:21 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_split_and_check(char *str, int c, char *charcode)
{
	char	**str_splitted;
	int		result;

	str_splitted = ft_split(str, c);
	result = ft_str_isequal(str_splitted[0], charcode);
	ft_split_clean(str_splitted);
	return (result);
}
