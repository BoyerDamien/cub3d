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
}				t_window;

t_window		ft_window(int win_size[2], int img_size[2], char *name);
t_image			ft_image(t_window window, int img_size[2]);
void			put_pixel(t_window *window, t_vector point, t_color color);


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
/** 							CHARACTER							**/
/*********************************************************************/

typedef struct s_character
{
	t_vector coordinate;
	t_color color;
	double fov;
	double cube_width;
	double cube_height;
	void (*show)(struct s_character*, t_window);
	void (*move)(struct s_character*, int);

}	t_character;

t_character ft_character(t_vector coordinate, double fov, double width, double height);
void ft_character_show(t_character *character, t_window window);
void ft_character_move(t_character *character, int move);

/*********************************************************************/
/** 							MAP							**/
/*********************************************************************/

typedef struct s_map
{
	char **content;
	int nx;
	int ny;
	t_window window;
	t_character character;
	size_t width;
	size_t height;
	t_color color;
	t_vector coordinate;
	double cube_width;
	double cube_height;

	void (*clear)(struct s_map *);
	void (*show)(struct s_map *, t_window);
}	t_map;

t_map ft_minimap(char **map, size_t width, size_t height, t_vector coordinate);
void ft_clear_map(t_map *map);
void ft_map_show(t_map *map, t_window window);


#endif
