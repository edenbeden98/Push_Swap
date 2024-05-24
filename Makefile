# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 14:21:39 by eamsalem          #+#    #+#              #
#    Updated: 2024/05/24 16:00:14 by eamsalem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Werror -Wextra -g3

OBJDIR = ./build
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

LIBFTDIR = ../libft
LIBFT = $(LIBFTDIR)/libft.a

SRCS =	rotate_fns.c \
		swap_fns.c \
		rev_rotate_fns.c \
		push_fns.c \
		sort_fns.c \
		push_swap.c	\
		bucket_sort.c \
		print_fns.c \
		check_fns.c

all: $(OBJDIR) $(NAME) $(LIBFT)

$(OBJDIR)/%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJDIR) $(OBJS)
	cc $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	make -C $(LIBFTDIR) all

clean:
	make -C $(LIBFTDIR) clean
	rm -fr $(OBJDIR)

fclean: clean
	make -C $(LIBFTDIR) fclean
	rm -fr $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re
