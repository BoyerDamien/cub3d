/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:17:42 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/15 18:31:45 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define GAME_NAME "cub3d"
# define RIGHT 100
# define LEFT 97
# define DOWN 115
# define UP 119
# define KEY_A 65361
# define KEY_Z 65363
# define ESCAPE 65307
# define STEP 0.3
# define ROTATION 3
# define LIGHT_RATIO 0.1
# define FOV 66
# include <math.h>
# include <stdio.h>
# include "libft/includes/libft.h"
# include "minilibx-linux/mlx.h"
# include "lib_ft_list/includes/ft_list.h"
# include "ft_vector/includes/ft_vector.h"
# include "objects.h"

void		ft_trace_column(t_vector onset, t_vector offset, t_window *window,\
t_color color);
void		ft_draw_ground(t_vector onset, t_vector offset, t_game *game,\
t_color color);
void		ft_draw_wall(t_vector onset, t_vector offset, t_game *game,\
double l_ratio);
void		ft_draw_ceil(t_vector onset, t_vector offset, t_game *game,\
t_color color);
void		ft_choose_texture(t_ray *ray, t_game *game, double dist);
void		ft_display_message(char *message);
void		ft_display_process_status(char *process, char *status);
void		ft_display_error(char *message, const char *fun_name);
void		ft_check_texture(char *path);
void		ft_check_color(char *path);
void		ft_test_map(char *path);
void		ft_convert_map(t_element *element);
void		ft_draw_sprite(t_sprite *sprite, t_game *game);
void		ft_write_bmp_file(t_game *game);
void		ft_check_character(char *path);
void		ft_add_sprite(t_list *list, t_sprite *sprite);

int			ft_check_resolution(char *path);
int			ft_check_extension(char *filename, char *extension);
int			ft_isexist(char *path);
int			ft_test_extension_path(char *path, char *extension);
int			ft_str_isequal(char *str1, char *str2);
int			ft_split_and_check(char *str, int c, char *charcode);
int			test_map_border(t_list *map);
int			test_map_content(t_list *map);
int			ft_is_texture_line(char *line);
int			ft_search_character(t_map *map, t_character *character);
int			ft_is_wall(t_game *game, int x, int y);
int			ft_is_sprite(t_game *game, int x, int y);
int			ft_backtrack(t_element *element, int n_index,\
							t_list *map, t_list *memory);
int			ft_map_is_closed(t_list *map, t_element *element, t_list *memory);
int			ft_check_line(char *line);

char		*ft_move_until(char *str, char *bool, int (*f)(int c));
char		*ft_tag_line(char *path, char *charcode);
char		**ft_map_list_to_char(char *path);

double		ft_degree_to_rad(double angle);
double		ft_perp_dist(t_game *game, t_ray *ray);

t_vector	ft_get_window_dimensions(char *path);

t_texture	ft_create_texture_from_file(char *path, char *charcode,\
t_window *window);
t_color		ft_get_color(char *path, char *charcode);
t_list		ft_get_map(char *path);

#endif
