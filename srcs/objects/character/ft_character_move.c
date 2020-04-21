/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:32:57 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/20 11:12:27 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"


t_vector move_right(t_game *game)
{
	double angle;
	t_vector move_vector;
	t_vector coordinate;

	coordinate = game->character.coordinate;
	angle = game->character.orientation - ft_degree_to_rad(90);
	move_vector = ft_vector(sin(angle), cos(angle), 0);
	return (coordinate.add(&coordinate, move_vector.mul_scalar(&move_vector, STEP)));
}

t_vector move_left(t_game *game)
{
	double angle;
	t_vector move_vector;
	t_vector coordinate;

	coordinate = game->character.coordinate;
	angle = game->character.orientation + ft_degree_to_rad(90);
	move_vector = ft_vector(sin(angle), cos(angle), 0);
	return (coordinate.add(&coordinate, move_vector.mul_scalar(&move_vector, STEP)));
}

t_vector move_up(t_game *game)
{
	double angle;
	t_vector move_vector;
	t_vector coordinate;

	coordinate = game->character.coordinate;
	angle = game->character.orientation;
	move_vector = ft_vector(sin(angle), cos(angle), 0);
	return (coordinate.add(&coordinate, move_vector.mul_scalar(&move_vector, STEP)));
}

t_vector move_down(t_game *game)
{
	double angle;
	t_vector move_vector;
	t_vector coordinate;

	coordinate = game->character.coordinate;
	angle = game->character.orientation;
	move_vector = ft_vector(sin(angle), cos(angle), 0);
	return (coordinate.sub(&coordinate, move_vector.mul_scalar(&move_vector, STEP)));
}

void ft_character_move(t_game *game, int move)
{
	t_vector new_coordinate;
	t_vector coordinate;

	coordinate = game->character.coordinate;
	if (move == RIGHT)
		coordinate = move_right(game);
	else if (move == LEFT)
		coordinate = move_left(game);
	else if (move == DOWN)
		coordinate = move_down(game);
	else if (move == UP)
		coordinate = move_up(game);
	new_coordinate = ft_check_map(game, coordinate);
	if (game->map.content[(int)new_coordinate.y][(int)new_coordinate.x] != '1')
		game->character.coordinate = coordinate;
}
