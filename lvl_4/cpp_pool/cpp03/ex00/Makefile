# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 12:17:45 by momayaz           #+#    #+#              #
#    Updated: 2022/05/05 11:20:42 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ClapTrap.cpp \
		main.cpp

HDR = ClapTrap.hpp

NAME = Aaaaand...OPEN!

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(SRC) -o $@

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all