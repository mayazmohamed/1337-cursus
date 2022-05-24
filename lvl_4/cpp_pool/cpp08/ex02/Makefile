# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 09:59:06 by momayaz           #+#    #+#              #
#    Updated: 2022/05/24 09:59:48 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.cpp


NAME = MutatedAbomination

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) MutantStack.hpp
	$(CC) $(CFLAGS) $(SRC) -o $@

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all