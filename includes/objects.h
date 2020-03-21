/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:55:54 by dboyer            #+#    #+#             */
/*   Updated: 2020/03/12 17:05:32 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
#define	OBJECTS_H
#include "vector.h"

/*********************************************************************/
/** 							COLOR								**/
/*********************************************************************/
typedef struct s_color
{
	int r;
	int g;
	int b;
	struct s_color (*add)(struct s_color*, struct s_color);
	struct s_color (*add_light)(struct s_color*, struct s_color, double);
	struct s_color (*add_color)(struct s_color*, struct s_color);

}				t_color;

t_color ft_color(int r, int g, int b);
t_color ft_add_light(t_color *color, t_color light_color, double light_ratio);
t_color ft_add_color(t_color *color1, t_color color2);


/*********************************************************************/
/** 							IMAGE								**/
/*********************************************************************/
typedef struct	s_image
{
	void	*img_ptr;
	char	*img_data;
	int		size_line;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}				t_image;

/*********************************************************************/
/** 							WINDOW								**/
/*********************************************************************/

typedef struct	s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	t_image		img;
	void		(*draw)(struct s_window *, t_vector point, t_color color);
	void		(*clear)(struct s_window *);
}				t_window;

t_window		ft_window(int win_size[2], int img_size[2], char *name);
t_image			ft_image(t_window window, int img_size[2]);
void			put_pixel(t_window *window, t_vector point, t_color color);
void			ft_clear_image(t_window *window);


/*********************************************************************/
/** 							RECTANGLE							**/
/*********************************************************************/

typedef struct s_rectangle
{
	double width;
	double height;
	t_color color;
	t_vector coordinate;
	void (*show)(struct s_rectangle*, t_window);
}	t_rectangle;

t_rectangle ft_rectangle(double width, double height, t_vector coordinate, t_color);
void ft_show_rectangle(t_rectangle *rect, t_window window);


/*********************************************************************/
/** 							MAP							**/
/*********************************************************************/

typedef struct s_map
{
	int nx;
	int ny;
	char **content;
	double cube_width;
	double cube_height;
	size_t width;
	size_t height;
	t_color color;
	t_window window;
	t_vector coordinate;
	void (*clear)(struct s_map *);
}	t_map;

t_map ft_minimap(char **map, size_t width, size_t height, t_vector coordinate);
void ft_clear_map(t_map *map);


/*********************************************************************/
/** 							CHARACTER							**/
/*********************************************************************/

typedef struct s_character
{
	t_vector coordinate;
	t_map map;
	t_color color;
	double fov;
	double orientation;
}	t_character;

t_character ft_character(t_vector coordinate, double orientation, t_map map);


/*********************************************************************/
/** 							TEXTURE								**/
/*********************************************************************/

typedef struct s_texture
{
	void	*img_ptr;
	char	*img_data;
	int		size_line;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}	t_texture;

t_texture ft_texture(void *mlx_ptr, char *path);

/*********************************************************************/
/** 							GAME								**/
/*********************************************************************/

typedef struct s_game
{
	t_window 	window;
	t_map		map;
	t_character character;
	t_texture wall_texture_N;
	t_texture wall_texture_S;
	t_texture wall_texture_O;
	t_texture wall_texture_E;
	t_texture actual_text;
	double cam_dist;
	void (*map_show)(struct s_game *);
	void (*character_move)(struct s_game*, int);
	void (*cast_ray)(struct s_game*);
	void (*character_rotate)(struct s_game*, int);
	void (*character_show)(struct s_game *);
}	t_game;

t_game  ft_game(char **map, int win_size[2]);
void    ft_map_show(t_game *game);
void	ft_character_show(t_game *game);
void	ft_character_move(t_game *game, int move);
void	ft_cast_ray(t_game *game);
void	ft_character_rotate(t_game *game, int rotation);


#endif
