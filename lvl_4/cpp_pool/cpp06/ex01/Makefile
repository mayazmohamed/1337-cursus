# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 16:14:52 by momayaz           #+#    #+#              #
#    Updated: 2022/05/11 16:35:13 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	Serialization.cpp\
		main.cpp


NAME = Serialization

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) Serialization.hpp
	$(CC) $(CFLAGS) $(SRC) -o $@

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all