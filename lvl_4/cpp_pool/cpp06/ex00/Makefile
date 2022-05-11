# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 15:39:57 by momayaz           #+#    #+#              #
#    Updated: 2022/05/11 15:41:42 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	Cast.cpp\
		main.cpp


NAME = ConversionOfScalarTypes

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) Cast.hpp
	$(CC) $(CFLAGS) $(SRC) -o $@

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all