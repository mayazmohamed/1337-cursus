# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 15:47:41 by momayaz           #+#    #+#              #
#    Updated: 2022/04/29 15:48:18 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	main.cpp

NAME =  HITHISISBRAIN

CC = c++

CFLAGS = -Wall -Werror -Wextra

all : ${NAME}

${NAME} : 	$(SRC)
			${CC} ${CFLAGS} ${SRC} -o ${NAME}

clean :
		rm -rf ${NAME}

fclean : clean

re : fclean all