# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/07 16:31:31 by momayaz           #+#    #+#              #
#    Updated: 2022/05/07 17:28:57 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	AMateria.cpp\
		Character.cpp\
		Cure.cpp \
		Ice.cpp\
		MateriaSource.cpp\
		main.cpp


NAME = InterfaceAndRecap

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) AMateria.hpp Character.hpp Cure.hpp ICharacter.hpp IMateriaSource.hpp Ice.hpp MateriaSource.hpp
	$(CC) $(CFLAGS) $(SRC) -o $@

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all