# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/02 01:22:36 by momayaz           #+#    #+#              #
#    Updated: 2022/05/05 11:24:37 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	Fixed.cpp\
		main.cpp\
		Point.cpp\
		bsp.cpp

NAME = BSP

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all : ${NAME}

${NAME} : 	$(SRC) Fixed.hpp Point.hpp
			${CC} ${CFLAGS} ${SRC} -o ${NAME}

clean :
		rm -rf ${NAME}

fclean : clean

re : fclean all