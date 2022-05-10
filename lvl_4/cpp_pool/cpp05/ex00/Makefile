# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 18:58:30 by momayaz           #+#    #+#              #
#    Updated: 2022/05/10 19:00:11 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	Bureaucrat.cpp\
		main.cpp


NAME = Mommy,WhenIGrowUp,IUantToBeABureaucrat!

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) Bureaucrat.hpp
	$(CC) $(CFLAGS) $(SRC) -o $@

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all