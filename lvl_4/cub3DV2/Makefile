# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 14:45:57 by ygbouri           #+#    #+#              #
#    Updated: 2022/10/28 11:46:05 by momayaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = cub3D.c cub.c src/parsing/check_clr.c src/parsing/check_map.c src/parsing/pars_line.c\
		src/parsing/split.c src/parsing/utils.c src/parsing/utils1.c\
		src/parsing/utils2.c src/gamedis/gameutils.c src/gamedis/gameutils1.c\
		src/gamedis/gameutils2.c src/gamedis/gameutils3.c src/gamedis/gameutils4.c\
		src/gamedis/gameutils5.c src/gamedis/gameutils6.c src/gamedis/gameutils7.c\
		src/gamedis/gameutils8.c src/gamedis/gameutils9.c src/gamedis/gameutils10.c\
		src/gamedis/gameutils11.c  src/gamedis/gameutils12.c src/gamedis/gameutils13.c\
		src/gamedis/gameutils14.c src/gamedis/gameutils15.c

SRCB = cub3D_Bonus.c cub.c src/parsing/check_clr.c src/parsing/check_map.c src/parsing/pars_line.c\
		src/parsing/split.c src/parsing/utils.c src/parsing/utils1.c\
		src/parsing/utils2.c src/gamedis/gameutils.c src/gamedis/gameutils1.c\
		src/gamedis/gameutils2.c src/gamedis/gameutils3.c src/gamedis/gameutils4.c\
		src/gamedis/gameutils5.c src/gamedis/gameutils6.c src/gamedis/gameutils7.c\
		src/gamedis/gameutils8.c src/gamedis/gameutils9.c src/gamedis/gameutils10.c\
		src/gamedis/gameutils11.c  src/gamedis/gameutils12.c src/gamedis/gameutils13.c\
		src/gamedis/gameutils14.c src/gamedis/gameutils15.c

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

CC = @gcc

NAME = cub3D

NAMEB = cub3D_Bonus

MLX = -framework OpenGL -framework Appkit

CFLAGS = -Wall -Wextra 

HEADER = cub3d.h

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(SRC) -lmlx $(MLX) -o $(NAME) -g
	@echo "mandatory is done"

$(NAMEB) : $(OBJB) $(HEADER)
	@$(CC)  $(SRCB) -lmlx $(MLX) -o $(NAMEB) -g
	@echo "bonus is done"

bonus : $(NAMEB)

clean :
	@rm -rf $(OBJ) $(OBJB)
	@echo "clean"

fclean : clean
	@rm -rf $(NAME) $(NAMEB) 

re : fclean all
