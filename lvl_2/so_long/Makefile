# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 16:08:47 by momayaz           #+#    #+#              #
#    Updated: 2022/01/13 12:42:48 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCM = check_pos.c\
		destroy.c\
		fill_2.c\
		fill_read_check.c\
		find_fill.c\
		utils.c\
		so_long.c

SRCB = bonus/animation_b.c\
		bonus/check_pos_b.c\
		bonus/fill_read_check_b.c\
		bonus/find_fill_b.c\
		bonus/norm.c\
		bonus/so_long_bonus.c\
		bonus/utils_b.c

NAME = so_long

BNAME = so_long_bonus

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : ${SRCM} so_long.h
	$(CC)  ${SRCM} -lmlx -framework OpenGL -framework AppKit -o ${NAME}


$(BNAME) : ${SRCB} so_long.h
			$(CC) $(CFLAGS) ${SRCB} -lmlx -framework OpenGL -framework AppKit -o ${BNAME}

bonus :	$(BNAME)

clean : 
	rm -rf so_long

fclean : clean

re : fclean all

