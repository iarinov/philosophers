# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 16:51:07 by aiarinov          #+#    #+#              #
#    Updated: 2022/04/22 11:17:06 by aiarinov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Werror -Wextra -Wall

NAME = libftprintf.a
SOURCE = ft_printf.c ft_print_hex.c ft_print_percent.c ft_printadresse.c ft_printchar.c \
			ft_printnbr.c ft_printstr.c ft_unsign.c \

OBJ = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/
	ar -rs $(NAME) $(OBJ) ./libft/*.o

clean:
	make clean -C ./libft/
	rm -f *.o

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME)

re: fclean all
