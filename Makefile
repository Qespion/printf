# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oespion <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/03 09:43:34 by oespion           #+#    #+#              #
#    Updated: 2018/05/03 09:52:55 by oespion          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_printf

FLAGS	=	-Wall -Wextra -Werror

INC_DIR	=	includes

LIB_DIR	=	libft/

SRCS	=	srcs/printf.c

OBJS	=	$(SRCS:.c=o)

all		=	$(NAME)

$(NAME):	$(OBJS)
			gcc $(FLAGS) $(OBJS) -o $(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re
