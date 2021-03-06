/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_message.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 17:03:15 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 15:44:43 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_display_message(char *message)
{
	ft_printf("\n##################################################\n");
	ft_printf("\t\t%s\n", message);
	ft_printf("##################################################\n");
}
