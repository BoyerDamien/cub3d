NAME    	=	cub3D
LIBFT_PATH	= "./lib/libft/"
LIBFT		= "./lib/libft/libft.a"
SCENES		= "scenes/"

SRCS    =	srcs/window/ft_window.c\
			srcs/window/put_pixel.c\
			srcs/image/ft_image.c\
			srcs/maths/ft_atof.c\
			srcs/maths/ft_degree_to_rad.c\
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
			srcs/objects/map/ft_check_map.c\
			srcs/objects/character/ft_character_show.c\
			srcs/objects/character/ft_character.c\
			srcs/objects/character/ft_character_move.c\
			srcs/objects/character/ft_cast_ray.c\
			srcs/objects/character/ft_character_rotate.c\
			srcs/display/ft_trace_line.c\
			srcs/display/ft_clear_image.c\
			srcs/display/ft_draw_ground.c\
			srcs/objects/game/ft_game.c\
			srcs/algorithms/find_obstacles.c\

			
			

MAIN 	= 	srcs/main.c

OBJS_MAIN = $(MAIN:.c=.o)

OBJS    = 	$(SRCS:.c=.o)

CFLAGS  =	-Werror -Wall -Wextra

MLX 	= 	-L./linux_mlx/mlx/ -lmlx -framework OpenGL -framework Appkit

CC      = 	gcc

RM      = 	rm -f



#############################################################################################################
#												Mini RT make
#############################################################################################################

all     :	$(NAME)

$(NAME) : $(OBJS) $(OBJS_MAIN)
	make -C $(LIBFT_PATH)
	${CC} ${CFLAGS} ${MLX} -o ${NAME} ${LIBFT} ./minilib/libmlx.a ${OBJS} ${OBJS_MAIN}

clean   :
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJS)
	$(RM) ${OBJS_MAIN}

fclean  : clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

run 	: $(NAME)
	./${NAME}

re      : fclean all

#############################################################################################################
#												Extra make
#############################################################################################################

norm:
	norminette CheckForbiddenHeader $(LIBFT_PATH)
	norminette CheckForbiddenHeader ./srcs

.PHONY  :	all clean fclean re bonus%