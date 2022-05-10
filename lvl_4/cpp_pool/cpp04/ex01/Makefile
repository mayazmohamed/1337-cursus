# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 13:02:47 by momayaz           #+#    #+#              #
#    Updated: 2022/05/06 15:27:40 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	Animal.cpp \
		main.cpp\
		Cat.cpp\
		Dog.cpp\
		Brain.cpp


NAME = IDon’tWantToSetTheWorldOnFire

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) Animal.hpp Cat.hpp Dog.hpp Brain.hpp
	$(CC) $(CFLAGS) $(SRC) -o $@

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all