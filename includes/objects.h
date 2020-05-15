/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:55:54 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/15 18:36:57 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef OBJECTS_H
#	define OBJECTS_H
#	include "ft_vector/includes/ft_vector.h"

/*
**									COLOR
*/
typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
	struct s_color	(*add)(struct s_color *, struct s_color);
	struct s_color	(*add_light)(struct s_color *, struct s_color, double);
	struct s_color	(*add_color)(struct s_color *, struct s_color);

}					t_color;

t_color				ft_color(int r, int g, int b);
t_color				ft_add_light(t_color *color, t_color light_color,\
double light_ratio);
t_color				ft_add_color(t_color *color1, t_color color2);

/*
**									IMAGE
*/
typedef struct		s_image
{
	void			*img_ptr;
	char			*img_data;
	int				size_line;
	int				bpp;
	int				endian;
	int				width;
	int				height;
}					t_image;

/*
** 									WINDOW
*/

typedef struct		s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				width;
	int				height;
	t_image			img;
	void			(*draw)(struct s_window *, t_vector point, t_color color);
	void			(*clear)(struct s_window *);
}					t_window;

t_window			ft_window(int width, int height, char *name);
t_image				ft_image(t_window window, int width, int height);
void				put_pixel(t_window *window, t_vector point, t_color color);
void				ft_clear_image(t_window *window);

/*
** 									RECTANGLE
*/
typedef struct		s_rectangle
{
	double			width;
	double			height;
	t_color			color;
	t_vector		coordinate;
	void			(*show)(struct s_rectangle *, t_window *);
}					t_rectangle;

t_rectangle			ft_rectangle(double width, double height,\
t_vector coordinate, t_color color);
void				ft_show_rectangle(t_rectangle *rect, t_window *window);

/*
** 										MAP
*/
typedef struct		s_map
{
	int				nx;
	int				ny;
	char			**content;
	double			cube_width;
	double			cube_height;
	size_t			width;
	size_t			height;
	t_color			color;
	t_window		window;
	t_vector		coordinate;
	void			(*clear)(struct s_map *);
}					t_map;

t_map				ft_minimap(char **map, size_t width, size_t height,\
t_vector coordinate);
void				ft_clear_map(t_map *map);

/*
** 									CHARACTER
*/

typedef struct		s_character
{
	t_vector		coordinate;
	t_map			map;
	t_color			color;
	t_vector		plane;
	t_vector		orientation;
	double			fov;
}					t_character;

t_character			ft_character(t_vector coordinate, double orientation,\
t_map map);

/*
** 									TEXTURE
*/

typedef struct		s_texture
{
	void			*img_ptr;
	char			*img_data;
	int				size_line;
	int				bpp;
	int				endian;
	int				width;
	int				height;
}					t_texture;

t_texture			ft_texture(void *mlx_ptr, char *path);

/*
** 									GAME
*/
typedef struct		s_game
{
	t_window		window;
	t_map			map;
	t_character		character;
	t_texture		wall_texture_n;
	t_texture		wall_texture_s;
	t_texture		wall_texture_o;
	t_texture		wall_texture_e;
	t_texture		actual_text;
	t_list			sprites;
	t_texture		sprite_texture;
	t_color			ceil_color;
	t_color			floor_color;
	double			*z_buffer;
	int				text_column;
	int				win_center;
	void			(*map_show)(struct s_game *);
	void			(*character_move)(struct s_game *, int);
	void			(*character_rotate)(struct s_game *, int);
	void			(*character_show)(struct s_game *);
	void			(*finish)(struct s_game *);
}					t_game;

t_game				ft_game(char *path);
void				ft_map_show(t_game *game);
void				ft_character_show(t_game *game);
void				ft_character_move(t_game *game, int move);
void				ft_character_rotate(t_game *game, int rotation);

/*
** 									RAY
*/
typedef struct		s_ray
{
	t_vector		point;
	t_vector		direction;
	t_vector		sidedist;
	t_vector		deltadist;
	t_vector		step;
	int				side;
	double			cam_coordinate;

	void			(*cast)(struct s_ray *, t_game *);
	void			(*update)(struct s_ray *, t_game *, int);
}					t_ray;

t_ray				ft_ray(t_game *game);
void				ft_cast_ray(t_game *game);

/*
** 									SPRITE
*/
typedef struct		s_sprite
{
	t_vector		sprite;
	t_vector		transform;
	t_vector		onset;
	t_vector		offset;
	t_vector		point;
	double			inv_det;
	double			ratio;
	int				screen_x;
	int				height;
	int				width;
}					t_sprite;

t_sprite			*ft_sprite(t_game *game, t_ray *ray);

/*
** 									BITMAP
*/
typedef struct		s_bmp_header
{
	int				file_size;
	int				unused;
	int				pixel_offset;
	int				header_size;
	int				image_width;
	int				image_height;
	short int		planes;
	short int		bpp;
}					t_bmp_header;

#	endif
