NAME    	=	cub3D
LIBFT_PATH	= "./lib/libft/"
LIBFT		= "./lib/libft/libft.a"
SCENES		= "scenes/"

SRCS    =	srcs/window/ft_window.c\
			srcs/window/put_pixel.c\
			srcs/image/ft_image.c\
			srcs/maths/ft_atof.c\
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
			srcs/objects/color/ft_color.c\
			srcs/objects/color/ft_add_light.c\
			srcs/objects/color/ft_add_color.c\
			srcs/objects/rectangle/ft_rectangle.c\
			srcs/objects/rectangle/ft_show_rectangle.c\
			srcs/display/ft_trace_line.c\

			
			

MAIN 	= 	srcs/main.c

OBJS_MAIN = $(MAIN:.c=.o)

OBJS    = 	$(SRCS:.c=.o)

CFLAGS  =	-Werror -Wall -Wextra

MLX 	= 	-lmlx -framework OpenGL -framework Appkit

CC      = 	gcc

RM      = 	rm -f



#############################################################################################################
#												Mini RT make
#############################################################################################################

all     :	$(NAME)

$(NAME) : $(OBJS) $(OBJS_MAIN)
	make -C $(LIBFT_PATH)
	${CC} ${CFLAGS} ${MLX} -o ${NAME} ${LIBFT} ${OBJS} ${OBJS_MAIN}

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