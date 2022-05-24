# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 17:02:33 by momayaz           #+#    #+#              #
#    Updated: 2022/05/23 15:19:11 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.cpp\
		Span.cpp


NAME = Span

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) Span.hpp
	$(CC) $(CFLAGS) $(SRC) -o $@

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all