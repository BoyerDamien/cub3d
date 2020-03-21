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
#define STEP 0.7
#define ROTATION 7
#define WIN_HEIGHT 800
#define WIN_WIDTH 800
#define WIN_CENTER (WIN_WIDTH / 2)
#define BLOCK_SIZE (WIN_HEIGHT / 6)
#define LIGHT_RATIO 0.2
#define FOV 60
#define MINIMAP_X 50
#define MINIMAP_Y 50
#define MINIMAP_WIDTH 200
#define MINIMAP_HEIGHT 200
#define GROUND_COLOR ft_color(0, 255, 0)
#define CEILING_COLOR ft_color(0, 0, 255)

int         ft_search_character(t_map *map, t_character *character);

t_vector    ft_check_map(t_game *game, t_vector coordinate);

void        ft_trace_line(t_vector onset, t_vector offset, t_window window, t_color color);
void        ft_draw_ground(t_vector onset, t_vector offset, t_game game, t_color color);
void        ft_draw_wall(t_vector onset, t_vector offset, t_game game, double l_ratio);

double      ft_degree_to_rad(double angle);
double      ft_map_value(double val, double min1, double max1, double max2);
void        find_obstacles(t_map *map, int x, int y);

#endif
