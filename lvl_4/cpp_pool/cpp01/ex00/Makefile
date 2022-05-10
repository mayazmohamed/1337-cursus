# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 14:06:17 by momayaz           #+#    #+#              #
#    Updated: 2022/05/05 11:22:10 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	Zombie.cpp\
		main.cpp\
		newZombie.cpp\
		randomChump.cpp

NAME = BraiiiiiiinnnzzzZ

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all : ${NAME}

${NAME} : 	$(SRC) Zombie.hpp
			${CC} ${CFLAGS} ${SRC} -o ${NAME}

clean :
		rm -rf ${NAME}

fclean : clean

re : fclean all