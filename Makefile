# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkocaaga <kkocaaga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 02:23:33 by kkocaaga          #+#    #+#              #
#    Updated: 2022/06/29 15:26:10 by kkocaaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap_utils.c sort_the_list.c smaller_list.c indexing.c check.c \
		push_swap_utils_2.c sort_the_list2.c errors.c read_numbers.c read_numbers_utils.c main.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror #-g
LIBPRINT = ./ft_printf/libftprintf.a

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ) $(LIBPRINT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBPRINT) -o $(NAME)

all: $(NAME)

$(LIBPRINT):
		make -C ./ft_printf

bonus: $(OBJ)
	make -C ./ft_printf
	$(CC) $(CFLAGS) $(SRC) ./ft_printf/libftprintf.a ./gnl/get_next_line.c ./gnl/get_next_line_utils.c checker.c -o checker

clean:
	rm -rf $(OBJ)
	rm -rf checker
	rm -rf main.o
	make -C ./ft_printf clean

fclean: clean
	rm -rf $(OBJ) $(NAME)
	make -C ./ft_printf fclean

re: fclean all

.PHONY: all re clean fclean 