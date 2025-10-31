# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/12 03:56:02 by juan-her          #+#    #+#              #
#    Updated: 2025/10/14 20:30:07 by juan-her         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SRC_URL = ./src
SRC = $(SRC_URL)/ft_printf.c $(SRC_URL)/ft_write_str.c \
		$(SRC_URL)/ft_write_int.c $(SRC_URL)/ft_write_punt.c\
		$(SRC_URL)/ft_write_hex.c $(SRC_URL)/ft_printf_utils.c
OBJ_URL = ./obj
OBJ = $(SRC:$(SRC_URL)/%.c=$(OBJ_URL)/%.o)
INCLUDE = ft_printf.h
RM = rm -rf

all: $(NAME)
	@echo "Library done."

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "File $(NAME) and objects created."

$(OBJ_URL):
	@mkdir -p $(OBJ_URL)

$(OBJ_URL)/%.o: $(SRC_URL)/%.c | $(OBJ_URL)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_URL)
	@echo "Objects deleted."

fclean: clean
	@$(RM) $(NAME)
	@echo "Library deleted."

re: fclean all
	@echo "Re Library."

.PHONY: all clean fclean re
