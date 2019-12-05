# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: relkassm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 13:49:30 by relkassm          #+#    #+#              #
#    Updated: 2019/11/28 15:33:01 by relkassm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../fdf

FLAG = -Werror -Wextra -Wall

SRC = main.c check_file.c store.c fdf.c line.c events.c
INC  = fdf.h
OBJ = main.o check_file.o store.o fdf.o line.o events.o

BIN = ../libft/libft.a

MLX_PATH = /usr/local/

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) $(OBJ) $(BIN) -lmlx  -L  $(MLX_PATH)lib/ -I $(MLX_PATH)include -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
