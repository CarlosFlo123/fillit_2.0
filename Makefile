# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abao <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/27 14:04:17 by abao              #+#    #+#              #
#    Updated: 2018/08/10 03:09:00 by cflores-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
W = -Wall -Wextra -Werror
SRC = *.c
OBJ = *.o

all: $(NAME)
$(NAME):
	make -C libft
	gcc -o $(NAME) $(W) $(SRC) -Llibft -lft -I fillit.h

clean:
	make clean -C libft
	/bin/rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME)

re: fclean all
