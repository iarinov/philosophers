# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 12:16:24 by aiarinov          #+#    #+#              #
#    Updated: 2022/09/14 13:51:45 by aiarinov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME = philosophers
SRC = main.c actions.c time.c free.c init.c print.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	make -C ./libftprintf
	gcc $(OBJ) ./libft/libft.a ./libftprintf/libftprintf.a -o $(NAME) $(FLAGS)

clean:
	make clean -C ./libft/
	make clean -C ./libftprintf/
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft/
	make fclean -C ./libftprintf/
	rm -f $(NAME)

re: fclean all
