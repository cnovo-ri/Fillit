# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/15 13:14:57 by cnovo-ri          #+#    #+#              #
#    Updated: 2017/01/05 18:20:54 by cnovo-ri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

SRC=main.c check_tetri.c open_read.c

LIB=./libft/libft.a

OBJ=$(SRC:.c=.o)

FLAG=-Wall Wextra -Werror

CC=clang

all: $(NAME)

$(NAME): $(LIB)
	$(CC) $(FLAGS) -c $(SRC) -I . -I ./libft
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -L ./libft -l ft

$(LIB):
	make re -C ./libft

clean:
	rm -f $(OBJ)
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re 
