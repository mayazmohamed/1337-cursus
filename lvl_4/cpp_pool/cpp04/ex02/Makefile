# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 13:02:47 by momayaz           #+#    #+#              #
#    Updated: 2022/05/17 13:39:47 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	Animal.cpp \
		main.cpp\
		Cat.cpp\
		Dog.cpp\
		Brain.cpp\
		WrongCat.cpp\
		WrongAnimal.cpp


NAME = Abstractclass

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) Animal.hpp Cat.hpp Dog.hpp Brain.hpp WrongAnimal.hpp  WrongCat.hpp
	$(CC) $(CFLAGS) $(SRC) -o $@

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all