# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 14:36:00 by momayaz           #+#    #+#              #
#    Updated: 2022/05/12 14:36:39 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.cpp


NAME = EasyFind

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) easyfind.hpp
	$(CC) $(CFLAGS) $(SRC) -o $@

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all