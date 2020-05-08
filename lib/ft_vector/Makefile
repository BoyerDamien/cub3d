# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 18:42:28 by dboyer            #+#    #+#              #
#    Updated: 2020/05/08 17:02:16 by dboyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftvector.a
 
SRCS 	=	srcs/ft_vector.c\
			srcs/ft_vec_add.c\
			srcs/ft_vec_add_scalar.c\
			srcs/ft_vec_cross_product.c\
			srcs/ft_vec_direction.c\
			srcs/ft_vec_dist.c\
			srcs/ft_vec_div_scalar.c\
			srcs/ft_vec_div.c\
			srcs/ft_vec_dot.c\
			srcs/ft_vec_length.c\
			srcs/ft_vec_mul_scalar.c\
			srcs/ft_vec_mul.c\
			srcs/ft_vec_normalise.c\
			srcs/ft_vec_sub_scalar.c\
			srcs/ft_vec_sub.c\
			srcs/ft_vec_update.c\
			srcs/ft_vec_update.c

OBJS 	=	$(SRCS:.c=.o)

HEADERS = -I ./includes/

CFLAGS 	= -Werror -Wall -Wextra -O3 ${HEADERS} 

CC 		= clang

RM	=	rm -f

INCS = ./includes/ft_vector.h

%.o: %.c ${INCS}
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJS)
		ar rcs $(NAME) $(OBJS) 

all		:	$(NAME)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re		:	fclean all

.PHONY	: all clean fclean re
