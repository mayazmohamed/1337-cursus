# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 15:24:07 by momayaz           #+#    #+#              #
#    Updated: 2022/03/04 15:43:10 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCM =	philo/list_creat.c\
		philo/philo.c\
		philo/philo_rout.c\
		philo/utils.c

SRCB =	philo_bonus/exec.c\
		philo_bonus/parsing.c\
		philo_bonus/philo_bonus.c\
		philo_bonus/utils1.c\
		philo_bonus/utils2.c

NAME = philo
NAMEB = philo_bonus

CFLAGS = -Wall -Wextra -Werror

$(NAME) : ${SRCM} philo/philo.h
	$(CC) $(CFLAGS) ${SRCM} -o ./philo/${NAME}



all : $(NAME)

$(NAMEB) : ${SRCB} philo_bonus/philo_bonus.h
	$(CC) $(CFLAGS) ${SRCB} -o ./philo_bonus/${NAMEB}
	
bonus : $(NAMEB)

clean : 
	rm -rf ./philo/${NAME}
	rm -rf ./philo_bonus/${NAMEB}

fclean : clean

re : fclean all
