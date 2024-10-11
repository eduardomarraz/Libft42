# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eduamart <eduamart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 15:46:17 by eduamart          #+#    #+#              #
#    Updated: 2024/10/11 10:15:45 by eduamart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC		=	ft_printf.c			\
			ft_auxprint.c			\
			ft_hexadecimals.c	\
			ft_pointers.c		\

OBJ		=	${SRC:.c=.o}

CC		=	gcc
RM		=	rm -rf
AR		=	ar rcs

CFLAGS	=	-Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME):	${OBJ} 
	${AR} ${NAME} ${OBJ}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re