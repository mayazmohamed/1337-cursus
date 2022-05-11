# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 16:20:19 by momayaz           #+#    #+#              #
#    Updated: 2022/05/11 16:35:02 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	A.cpp\
		B.cpp\
		Base.cpp\
		C.cpp\
		main.cpp


NAME = IdentifyRealType

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) A.hpp B.hpp Base.hpp C.hpp
	$(CC) $(CFLAGS) $(SRC) -o $@

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all