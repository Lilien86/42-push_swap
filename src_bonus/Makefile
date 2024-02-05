# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 09:46:39 by lauger            #+#    #+#              #
#    Updated: 2024/02/05 13:16:41 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

LIBFT = ../libft
LIBFT_LIBRARY = $(LIBFT)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT)
LDFLAGS = -L $(LIBFT) -lft

SRC = main_bonus.c arg_to_lst.c check_is_move.c utils_bonus.c move_to_lst.c to_do_movement.c \
swap.c rotate.c r_rotate.c push.c\


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
