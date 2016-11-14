# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbuys <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/24 08:59:44 by jbuys             #+#    #+#              #
#    Updated: 2016/06/24 11:33:32 by jbuys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CC = gcc

C_FLAGS = -Wall -Wextra -Werror -g

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRC_PATH = ./src/

INCL = /includes/wolf3d.h

SRC = $(SRC_PATH)main.c $(SRC_PATH)ray_casting.c		\
	  $(SRC_PATH)read_map.c $(SRC_PATH)draw.c			\
	  $(SRC_PATH)key_hook.c $(SRC_PATH)freq.c			\

OBJ = $(SRC_PATH)main.o $(SRC_PATH)ray_casting.o		\
	  $(SRC_PATH)read_map.o $(SRC_PATH)draw.o			\
	  $(SRC_PATH)key_hook.o $(SRC_PATH)freq.o			\

all: $(NAME)

$(NAME):
	@echo "\nCrystal is preparing to compile Wolf3D..."
	@$(CC) $(C_FLAGS) -c $(SRC) -I $(INCL)
	@echo "Crystal has successfully created all your object files..."
	@mv *.o src/
	@echo "Crystal has successfully moved all the object files to src/"
	@$(CC) -o $(NAME) $(C_FLAGS) $(OBJ) $(MLX_FLAGS) -L libft/ -lft
	@echo "Crystal has successfully compiled your Wolf3D.\n"

clean:
	@rm -f $(OBJ)
	@echo "Crystal has removed your object files."

fclean: clean
	@rm -f $(NAME)
	@echo "Crystal has successfully removed the executable."

re: fclean all
	@echo "Crystal has successfully recompiled."

norme: 
	@norminette $(SRC)
