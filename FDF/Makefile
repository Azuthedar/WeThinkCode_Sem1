# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbuys <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 10:21:32 by jbuys             #+#    #+#              #
#    Updated: 2016/11/03 10:35:29 by jbuys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SP = ./src/

SRC = $(SP)init.c \
	$(SP)mlx_win.c \
	$(SP)event.c \
	$(SP)calc_grid.c \
	$(SP)chk_size.c \
	$(SP)draw.c \
	$(SP)error.c \
	$(SP)main.c

OBJ = init.o \
	mlx_win.o \
	event.o \
	calc_grid.o \
	chk_size.o \
	draw.o \
	error.o \
	main.o

INCLUDES =  -I ./include/

CFLAGS = -Werror -Wextra -Wall -g3

MLXFL = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	@gcc -c $(SRC) $(INCLUDES)
	@echo "Compiled files into OBJ files."
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(MLXFL) $(INCLUDES) -L libft/ -lft
	@echo "Compiled files into an EXECUTABLE file."

clean:
	@rm -f $(OBJ)
	@echo "Removed all obj files"

fclean: clean
	@rm -f $(NAME)
	echo "Removed EXECUTABLE"

re: fclean all

.norm:
	@norminette $(SRC)
	@echo "Normed all files"

.db: $(NAME)
	lldb $(NAME)