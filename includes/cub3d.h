/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:17:42 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/05 14:06:25 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
#define MINI_RT_H

#include "../lib/libft/includes/libft.h"
#include "get_next_line.h"
#include <math.h>
#include "../minilib/mlx.h"
#include <stdio.h>
#include "objects.h"

#define GAME_NAME "cub3d"
#define RIGHT 124
#define LEFT 123
#define DOWN 125
#define UP 126
#define KEY_A 12
#define KEY_Z 13
#define STEP 5
#define ROTATION 10
#define WIN_HEIGHT 800
#define WIN_WIDTH 800
#define WIN_CENTER (WIN_WIDTH / 2)
#define BLOCK_SIZE (WIN_HEIGHT / 2)
#define CAM_DIST 35
#define FOV 60

int         ft_search_character(t_map *map, t_character *character);
t_vector    ft_check_map(t_game *game, t_vector coordinate);
void        ft_trace_line(t_vector onset, t_vector offset, t_window window, t_color color);
double      ft_degree_to_rad(double angle);
#endif
