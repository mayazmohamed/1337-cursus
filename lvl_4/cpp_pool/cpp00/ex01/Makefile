# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/28 17:10:40 by momayaz           #+#    #+#              #
#    Updated: 2022/05/05 11:21:49 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	Contact.cpp\
		PhoneBook.cpp\
		MyAwesomePhoneBook.cpp

NAME = MyAwesomePhoneBook

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all : ${NAME}

${NAME} : 	$(SRC) Contact.hpp PhoneBook.hpp
			${CC} ${CFLAGS} ${SRC} -o ${NAME}

clean :
		rm -rf ${NAME}

fclean : clean

re : fclean all