# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 18:58:02 by momayaz           #+#    #+#              #
#    Updated: 2022/05/10 19:00:41 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	Bureaucrat.cpp\
		Form.cpp\
		main.cpp


NAME = FormUp,Maggots!

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) Bureaucrat.hpp Form.hpp
	$(CC) $(CFLAGS) $(SRC) -o $@

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all