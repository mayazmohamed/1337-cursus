# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 23:45:05 by momayaz           #+#    #+#              #
#    Updated: 2022/05/05 11:23:31 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	HumanA.cpp HumanB.cpp Weapon.cpp main.cpp

NAME =  UnnecessaryViolence

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all : ${NAME}

${NAME} : 	$(SRC) HumanA.hpp HumanB.hpp Weapon.hpp
			${CC} ${CFLAGS} ${SRC} -o ${NAME}

clean :
		rm -rf ${NAME}

fclean : clean

re : fclean all