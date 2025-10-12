# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/12 03:56:02 by juan-her          #+#    #+#              #
#    Updated: 2025/10/12 04:28:51 by juan-her         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
LIBFT_URL = ./libft
LIBFT = $(LIBFT_URL)/libft.a
SRC_URL = ./source
SRC = $(SRC_URL)/ft_printf.C $(SRC_URL)/ft_print_str.c \
		$(SRC_URL)/ft_print_char.C $(SRC_URL)/ft_print_int.c
OBJ = $(SRC:$(SRC_URL).c=.o)
INCLUDE = libft.h
RM = rm -f

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_URL)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

%.o: $(SRC_URL)/%.C
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_URL) clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_URL) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re