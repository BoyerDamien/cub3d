/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_process_status.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 17:08:58 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 15:44:54 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_display_process_status(char *process, char *status)
{
	ft_printf("%s\t:\t\t\t[%s]\n", process, status);
}
