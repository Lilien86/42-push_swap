# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lauger <lauger@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 09:46:39 by lauger            #+#    #+#              #
#    Updated: 2024/01/17 13:56:15 by lauger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./push_swap

LIBFT = ./libft
LIBFT_LIBRARY = $(LIBFT)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT)
LDFLAGS = -L $(LIBFT) -lft

SRC = ./src/main.c ./src/arg_to_lst.c ./src/swap.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT_LIBRARY):
	make --quiet -C $(LIBFT)

$(NAME): $(LIBFT_LIBRARY) $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT) -c $< -o $@

clean:
	make --quiet -C $(LIBFT) clean
	rm -f $(NAME) $(OBJ)

fclean: clean
	make --quiet -C $(LIBFT) fclean
	rm -f $(NAME) $(OBJ)

re: fclean all

gdb: CFLAGS += -g
gdb: fclean all

.PHONY: all clean fclean re
