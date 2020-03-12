/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:32:57 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/12 18:16:20 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void ft_character_move(t_character *character, int move)
{

	if (move == RIGHT)
		character->coordinate.x += STEP;
	else if (move == LEFT)
		character->coordinate.x -= STEP;
	else if (move == DOWN)
		character->coordinate.y += STEP;
	else if (move == UP)
		character->coordinate.y -= STEP;
}