# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 21:08:23 by momayaz           #+#    #+#              #
#    Updated: 2022/05/05 11:23:48 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	Harl.cpp  main.cpp

NAME = Harl2.0

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all : ${NAME}

${NAME} : 	$(SRC) Harl.hpp
			${CC} ${CFLAGS} ${SRC} -o ${NAME}

clean :
		rm -rf ${NAME}

fclean : clean

re : fclean all