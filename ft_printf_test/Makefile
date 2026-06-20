# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekirgin <ekirgin@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/04 17:02:08 by ekirgin           #+#    #+#              #
#    Updated: 2026/06/20 13:20:00 by ekirgin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
COMPARE_NAME = compare_output

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FT_PRINTF_DIR = ../ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

SRC = main.c
COMPARE_SRC = compare_output.c

OBJ = $(SRC:.c=.o)
COMPARE_OBJ = $(COMPARE_SRC:.c=.o)

all: $(NAME) $(COMPARE_NAME)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(FT_PRINTF_DIR) -c $< -o $@

$(NAME): $(OBJ) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(FT_PRINTF_LIB) -o $(NAME)

$(COMPARE_NAME): $(COMPARE_OBJ) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(COMPARE_OBJ) $(FT_PRINTF_LIB) -o $(COMPARE_NAME)

run: $(NAME)
	./$(NAME)

compare: $(COMPARE_NAME)
	./$(COMPARE_NAME)

clean:
	$(RM) $(OBJ) $(COMPARE_OBJ)
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME) $(COMPARE_NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all run compare clean fclean re
