# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 11:28:22 by momayaz           #+#    #+#              #
#    Updated: 2022/01/11 12:11:38 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCM =	check_and_fill.c\
		exec_file.c\
		list_manipulation.c\
		pipex.c\
		split_file.c\
		utils.c\
		utils2.c

SRCB =	bonus/check_and_fill_b.c\
		bonus/exec_file_b.c\
		bonus/here_doc.c\
		bonus/list_manipulation_b.c\
		bonus/pipex_bonus.c\
		bonus/split_file.c\
		bonus/utils2_b.c\
		bonus/utils_b.c

NAME = pipex
NAMEB = pipex_bonus

CFLAGS = -Wall -Wextra -Werror

$(NAME) : ${SRCM} pipex.h
	$(CC) $(CFLAGS) ${SRCM} -o ${NAME}



all : $(NAME)

$(NAMEB) : ${SRCB} pipex.h
	$(CC) $(CFLAGS) ${SRCB} -o ${NAMEB}
	
bonus : $(NAMEB)

clean : 
	rm -rf ${NAME}

fclean : clean

re : fclean all

