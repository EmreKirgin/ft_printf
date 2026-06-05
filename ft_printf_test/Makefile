# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekirgin <ekirgin@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/04 17:02:08 by ekirgin           #+#    #+#              #
#    Updated: 2026/05/04 17:11:33 by ekirgin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FT_PRINTF_DIR = /home/ekirgin/Emre/Core/ft_printf

SRC = main.c \
		$(FT_PRINTF_DIR)/ft_printf.c \
	  	$(FT_PRINTF_DIR)/ft_print_char.c \
		$(FT_PRINTF_DIR)/ft_print_number.c \
		$(FT_PRINTF_DIR)/ft_print_hex.c \
		$(FT_PRINTF_DIR)/ft_print_pointer.c

all: $(NAME)

$(NAME): $(SRC)
		$(CC) $(CFLAGS) $(SRC) -I$(FT_PRINTF_DIR) -o $(NAME)

run: $(NAME)
	./$(NAME)
	
clean:
		$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
