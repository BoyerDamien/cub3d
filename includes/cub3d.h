/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:17:42 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/21 19:12:19 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
#define MINI_RT_H

#define GAME_NAME "cub3d"
#define RIGHT 65363
#define LEFT 65361
#define DOWN 65364
#define UP 65362
#define KEY_A 97
#define KEY_Z 122
#define STEP 0.5
#define ROTATION 5
#define WIN_HEIGHT 100
#define WIN_WIDTH 100
#define WIN_CENTER (WIN_WIDTH / 2)
#define BLOCK_SIZE (WIN_HEIGHT / 10)
#define LIGHT_RATIO 0.2
#define FOV 60
#define MINIMAP_X (WIN_WIDTH * 0.01)
#define MINIMAP_Y (WIN_HEIGHT * 0.01)
#define MINIMAP_WIDTH (WIN_WIDTH / 4)
#define MINIMAP_HEIGHT (WIN_HEIGHT / 4)
#define GROUND_COLOR ft_color(0, 255, 0)
#define CEILING_COLOR ft_color(0, 0, 255)

#include <math.h>
#include <stdio.h>
#include "../lib/get_next_line/get_next_line.h"
#include "../lib/libft/includes/libft.h"
#include "../minilibx-linux/mlx.h"
#include "objects.h"

int         ft_search_character(t_map *map, t_character *character);

t_vector    ft_check_map(t_game *game, t_vector coordinate);

void        ft_trace_line(t_vector onset, t_vector offset, t_window window, t_color color);
void        ft_draw_ground(t_vector onset, t_vector offset, t_game *game, t_color color);
void        ft_draw_wall(t_vector onset, t_vector offset, t_game *game, double l_ratio);
void        find_obstacles(t_map *map, int x, int y);
void        ft_choose_texture(t_vector point, t_game *game);
void        ft_display_message(char *message);
void        ft_display_process_status(char *process, char *status);
void        ft_display_error(char *message, const char *fun_name);

int         ft_check_resolution(char *path);
int         ft_check_extension(char *filename);
int         ft_isexist(char *path);

double      ft_degree_to_rad(double angle);
double      ft_map_value(double val, double min1, double max1, double max2);


#endif
