# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/21 12:21:52 by ignmarti          #+#    #+#              #
#    Updated: 2026/02/08 13:04:46 by ignmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	   stack.c \
	   push.c \
	   swap.c \
	   rotate.c \
	   reverse_rotate.c \
	   parseV2.c\
	   sort_small.c \
	   utils.c \
	   disorder.c \
	   simple_algo.c \
	   medium_algo.c \
	   medium_helper.c \
	   complex_algo.c \
	   complex_helper.c \
	   free_utils.c \
	   adaptive.c \
	   bench.c \
	   parse_utils1.c \
	   parse_utils2.c \
	   bench_utils.c

OBJS = $(SRCS:.c=.o)

LIBFT = ./Libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./Libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C ./Libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./Libft clean

re: fclean all
