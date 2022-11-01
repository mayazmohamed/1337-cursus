# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 10:54:20 by momayaz           #+#    #+#              #
#    Updated: 2022/11/01 12:47:30 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp

ISRC = implementTest.cpp

VSRC = vectormain.cpp

MSRC = map.cpp

STSRC = stacktest.cpp

SSRC = set.cpp

HEADR =	implement/equal.hpp \
		implement/enable_if.hpp \
		implement/iterator.hpp \
		implement/iterator_traits.hpp \
		implement/is_integral.hpp \
		implement/pair.hpp \
		implement/lexicographical_compare.hpp \
		map/map.hpp \
		red_black_tree/red_black_tree.hpp \
		stack/stack.hpp \
		vector/vector.hpp \
		set/set.hpp
		
NAME = ft_containers

INAME = implementtest

VNAME = vectortest

MNAME = maptest

STNAME = stacktest

SNAME = settest

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) $(HEADR)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

vector		: $(VNAME) 

$(VNAME): $(VSRC) $(HEADR)
	$(CC) $(FLAGS) $(VSRC) -o $(VNAME)

implement	: $(INAME) 

$(INAME): $(ISRC) $(HEADR)
	$(CC) $(FLAGS) $(ISRC) -o $(INAME)

map			: $(MNAME) 

$(MNAME): $(MSRC) $(HEADR)
	$(CC) $(FLAGS) $(MSRC) -o $(MNAME)

stack		: $(STNAME) 

$(STNAME): $(STSRC) $(HEADR)
	$(CC) $(FLAGS) $(STSRC) -o $(STNAME)

bonus		: $(SNAME)

$(SNAME): $(SSRC) $(HEADR)
	$(CC) $(FLAGS) $(SSRC) -o $(SNAME)
	
clean:
	rm -f $(NAME) $(INAME) $(VNAME) $(MNAME) $(STNAME) $(SNAME)
	
fclean: clean

re: fclean all

.PHONY: all vector implement map stack clean bonus clean fclean re
