/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 17:02:30 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/13 15:38:43 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_extension(char *filename, char *extension)
{
	int		result;
	char	*status;

	result = 0;
	status = ft_strjoin("Check ", filename);
	if (ft_test_extension_path(filename, extension))
	{
		ft_display_process_status(status, "ok");
		result = 1;
	}
	else
		ft_display_process_status(status, "error");
	free(status);
	return (result);
}
