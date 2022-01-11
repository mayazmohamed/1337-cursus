# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 14:10:39 by momayaz           #+#    #+#              #
#    Updated: 2021/11/27 21:37:29 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_printf_util.c\
		ft_printf_util_1.c\
		ft_printf_util_2.c\
		ft_printf_util_3.c\
		ft_printf_util_4.c\
		ft_prepa.c\
		ft_printf.c 
OBJ = ${SRC:.c=.o}
CC = cc -c
CFLAGS = -Wall -Werror -Wextra -I. 
NAME = libftprintf.a

${NAME} : ${OBJ}
	ar cr ${NAME} ${OBJ}
all : ${NAME}

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) $^
bonus : all

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all