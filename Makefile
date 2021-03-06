# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/20 09:03:17 by dboyer            #+#    #+#              #
#    Updated: 2020/05/15 18:32:11 by dboyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    			=	cub3D

SRCS    			=	srcs/parsing/ft_display_message.c\
						srcs/parsing/ft_check_extension.c\
						srcs/parsing/ft_display_process_status.c\
						srcs/parsing/ft_display_error.c\
						srcs/parsing/ft_isexist.c\
						srcs/parsing/ft_check_resolution.c\
						srcs/parsing/ft_test_extension_path.c\
						srcs/parsing/ft_is_texture_line.c\
						srcs/parsing/ft_check_texture.c\
						srcs/parsing/ft_str_isequal.c\
						srcs/parsing/ft_split_and_check.c\
						srcs/parsing/ft_move_until.c\
						srcs/parsing/ft_tag_line.c\
						srcs/parsing/ft_check_color.c\
						srcs/parsing/test_map_border.c\
						srcs/parsing/test_map_content.c\
						srcs/parsing/ft_convert_map.c\
						srcs/parsing/ft_test_map.c\
						srcs/parsing/ft_get_window_dimensions.c\
						srcs/parsing/ft_create_texture_from_file.c\
						srcs/parsing/ft_get_color.c\
						srcs/parsing/ft_get_map.c\
						srcs/parsing/ft_map_list_to_char.c\
						srcs/parsing/ft_check_character.c\
						srcs/parsing/ft_backtrack.c\
						srcs/parsing/ft_map_is_closed.c\
						srcs/parsing/ft_check_line.c\
						srcs/window/ft_window.c\
						srcs/window/put_pixel.c\
						srcs/image/ft_image.c\
						srcs/maths/ft_degree_to_rad.c\
						srcs/maths/ft_perp_dist.c\
						srcs/objects/color/ft_color.c\
						srcs/objects/color/ft_add_light.c\
						srcs/objects/color/ft_add_color.c\
						srcs/objects/rectangle/ft_rectangle.c\
						srcs/objects/rectangle/ft_show_rectangle.c\
						srcs/objects/map/ft_minimap.c\
						srcs/objects/map/ft_clear_map.c\
						srcs/objects/map/ft_map_show.c\
						srcs/objects/map/ft_search_character.c\
						srcs/objects/map/ft_is_wall.c\
						srcs/objects/map/ft_is_sprite.c\
						srcs/objects/character/ft_character_show.c\
						srcs/objects/character/ft_character.c\
						srcs/objects/character/ft_character_move.c\
						srcs/objects/character/ft_cast_ray.c\
						srcs/objects/character/ft_character_rotate.c\
						srcs/display/ft_trace_column.c\
						srcs/display/ft_clear_image.c\
						srcs/display/ft_draw_ground.c\
						srcs/display/ft_draw_wall.c\
						srcs/display/ft_choose_texture.c\
						srcs/display/ft_draw_ceil.c\
						srcs/display/ft_draw_sprite.c\
						srcs/objects/game/ft_game.c\
						srcs/objects/texture/ft_texture.c\
						srcs/objects/sprites/ft_sprites.c\
						srcs/objects/ray/ft_ray.c\
						srcs/objects/ray/ft_add_sprite.c\
						srcs/objects/bitmap/ft_bitmap.c\

LIBFT_PATH			= 	"./lib/libft/"
LIB_FT_LIST_PATH	= 	"./lib/lib_ft_list/"
MLX_PATH			= 	"./lib/minilibx-linux/"
FT_VECTOR_PATH		= "./lib/ft_vector/"

MAIN 				= 	srcs/main.c

OBJS_MAIN 			= 	$(MAIN:.c=.o)
OBJS    			= 	$(SRCS:.c=.o)

LIBRARY	 			= 	-L ./lib/minilibx-linux -lmlx -lm -lXext -lX11 -lbsd \
		  				-L ./lib/lib_ft_list -lftlist \
		  				-L ./lib/libft -lft \
						-L ./lib/ft_vector -lftvector

CC      			= 	clang

RM      			= 	rm -f

HEADERS 			= 	-I ./includes/ -I ./lib/

CFLAGS  			= 	-Werror -Wall -Wextra -Ofast -pedantic-errors ${HEADERS}

INCS = ./includes/cub3d.h ./includes/objects.h

################################################################################
#									cube3d make
################################################################################

%.o: %.c ${INCS}
	$(CC) $(CFLAGS) -c $< -o $@

all     :	$(NAME)

$(NAME) : $(OBJS) $(OBJS_MAIN)
	make -C $(LIBFT_PATH)
	make -C $(LIB_FT_LIST_PATH)
	make -C $(MLX_PATH)
	make -C $(FT_VECTOR_PATH)
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${OBJS_MAIN} ${LIBRARY}

clean   :
	make clean -C $(LIBFT_PATH)
	make clean -C $(LIB_FT_LIST_PATH)
	make clean -C $(MLX_PATH)
	make clean -C $(FT_VECTOR_PATH)
	$(RM) $(OBJS)
	$(RM) ${OBJS_MAIN}

fclean  : clean
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(LIB_FT_LIST_PATH)
	make fclean -C $(FT_VECTOR_PATH)
	$(RM) $(NAME)

run 	: all
	./${NAME} ./maps/map1.cub

save: all
	./${NAME} ./maps/map1.cub --save

re      : fclean all

################################################################################
#												Extra make
################################################################################

norm: fclean
	~/.norminette/norminette.rb

.PHONY  :	all clean fclean re bonus%
