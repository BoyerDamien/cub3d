# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/20 09:03:17 by dboyer            #+#    #+#              #
#    Updated: 2020/04/28 17:40:45 by dboyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	=	cub3D
LIBFT_PATH	= "./lib/libft/"

SCENES		= "scenes/"

SRCS    =	srcs/parsing/ft_display_message.c\
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
			srcs/window/ft_window.c\
			srcs/window/put_pixel.c\
			srcs/image/ft_image.c\
			srcs/maths/ft_atof.c\
			srcs/maths/ft_degree_to_rad.c\
			srcs/maths/ft_map_value.c\
			srcs/objects/vector/ft_vec_add.c\
			srcs/objects/vector/ft_vec_sub.c\
			srcs/objects/vector/ft_vec_mul.c\
			srcs/objects/vector/ft_vec_div.c\
			srcs/objects/vector/ft_vec_add_scalar.c\
			srcs/objects/vector/ft_vec_sub_scalar.c\
			srcs/objects/vector/ft_vec_mul_scalar.c\
			srcs/objects/vector/ft_vec_div_scalar.c\
			srcs/objects/vector/ft_vec_dot.c\
			srcs/objects/vector/ft_vec_length.c\
			srcs/objects/vector/ft_vec_direction.c\
			srcs/objects/vector/ft_vector.c\
			srcs/objects/vector/ft_vec_update.c\
			srcs/objects/vector/ft_vec_normalise.c\
			srcs/objects/vector/ft_vec_cross_product.c\
			srcs/objects/vector/ft_vec_dist.c\
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
			srcs/objects/game/ft_game.c\
			srcs/objects/texture/ft_texture.c\
			lib/get_next_line/get_next_line.c\
			lib/get_next_line/get_next_line_utils.c\


MAIN 	= 	srcs/main.c

OBJS_MAIN = $(MAIN:.c=.o)

OBJS    = 	$(SRCS:.c=.o)

CFLAGS  =	-Werror -Wall -Wextra -O3

LIBFT		= -L ./lib/libft -lft

MLX 	= 	-L./minilibx-linux -lmlx -lm -lXext -lX11 -lbsd

CC      = 	gcc

RM      = 	rm -f



################################################################################
#												Mini RT make
################################################################################

all     :	$(NAME)

$(NAME) : $(OBJS) $(OBJS_MAIN)
	make -C $(LIBFT_PATH)
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${OBJS_MAIN} ${MLX} ${LIBFT}

clean   :
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJS)
	$(RM) ${OBJS_MAIN}

fclean  : clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

run 	: $(NAME)
	./${NAME} ./maps/map1.cub

re      : fclean all

################################################################################
#												Extra make
################################################################################

norm:
	norminette CheckForbiddenHeader $(LIBFT_PATH)
	norminette CheckForbiddenHeader ./srcs

.PHONY  :	all clean fclean re bonus%
