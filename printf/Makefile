# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/12 03:56:02 by juan-her          #+#    #+#              #
#    Updated: 2025/10/13 03:31:26 by juan-her         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
LIBFT_URL = ./libft
LIBFT = $(LIBFT_URL)/libft.a
SRC_URL = ./src
SRC = $(SRC_URL)/ft_printf.c $(SRC_URL)/ft_write_str.c \
		$(SRC_URL)/ft_write_int.c $(SRC_URL)/ft_write_punt.c\
		$(SRC_URL)/ft_write_hex.c
OBJ_URL = ./obj
OBJ = $(patsubst $(SRC_URL)/%.c,$(OBJ_URL)/%.o,$(SRC))
INCLUDE = libft.h
RM = rm -rf

all: $(LIBFT) $(NAME)
	@echo "Se ha creado la biblioteca."

$(LIBFT):
	$(MAKE) -C $(LIBFT_URL)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "Archivo $(NAME) creado."

$(OBJ_URL):
	@mkdir -p $(OBJ_URL)

$(OBJ_URL)/%.o: $(SRC_URL)/%.c | $(OBJ_URL)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Se han creado los objetos"

clean:
	$(MAKE) -C $(LIBFT_URL) clean
	$(RM) $(OBJ_URL)
	@echo "Se han borrado los objetos."

fclean: clean
	$(MAKE) -C $(LIBFT_URL) fclean
	$(RM) $(NAME)
	@echo "Se han borrado las bibliotecas."

re: fclean all
	@echo "Se ha vuelto a hacer la biblioteca."

.PHONY: all clean fclean re
