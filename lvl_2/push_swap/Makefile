# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 13:36:24 by momayaz           #+#    #+#              #
#    Updated: 2021/12/31 14:23:05 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRCM = join_file.c\
		mini_utils.c\
		push_swap.c\
		push_to_a.c\
		push_to_b.c\
		sort_ft_2.c\
		split_file.c\
		swap_ft_2.c\
		utils.c\
		list_manupulation.c\
		push_to_a2.c\
		sort_ft_1.c\
		sort_ft_3.c\
		swap_ft_1.c\
		swap_sort.c

SRCB = join_file.c\
		mini_utils.c\
		push_to_a.c\
		push_to_b.c\
		sort_ft_2.c\
		split_file.c\
		swap_ft_2.c\
		utils.c\
		list_manupulation.c\
		push_to_a2.c\
		sort_ft_1.c\
		sort_ft_3.c\
		swap_ft_1.c\
		swap_sort.c\
		bonus/checker.c

NAME = push_swap

BNAME = checker

CFLAGS = -Wall -Wextra -Werror

$(NAME) : ${SRCM} push_swap.h
	$(CC) $(CFLAGS) ${SRCM} -o ${NAME}

all : $(NAME)

$(BNAME) : ${SRCB} push_swap.h
	$(CC) $(CFLAGS) ${SRCB} -o ${BNAME}

bonus : $(BNAME)

clean :

fclean : clean
	rm -rf ${NAME} checker

re : fclean all


