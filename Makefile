# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 19:02:36 by chomobon          #+#    #+#              #
#    Updated: 2025/04/11 17:44:23 by chomobon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = ft_comprobations.c ft_execute_movements.c ft_fill_stacks.c \
ft_movements.c ft_parse_args.c ft_push_swap.c ft_push_utils.c \
ft_reversemovements.c ft_heuristics.c ft_set_tg_pos.c \
ft_sort_mt_three.c ft_sort_three.c ft_sort.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft
LIBFT_LIB = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	@make bonus -C $(LIBFT)
	
clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFT)
	
fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_LIB)

re: fclean all

.PHONY: all clean fclean re