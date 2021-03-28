# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgiron <jgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/14 12:12:09 by jgiron            #+#    #+#              #
#    Updated: 2021/03/28 14:52:43 by jgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS_SRCS = 	srcs/push_swap/main.c srcs/parser/parser.c srcs/get_next_line/get_next_line.c \
srcs/get_next_line/get_next_line_utils.c srcs/utils/utils.c srcs/operations/operations.c \
srcs/push_swap/solver.c srcs/push_swap/sort3.c srcs/push_swap/sort5.c srcs/utils/push_swap_utils1.c \
srcs/utils/push_swap_utils2.c

CHECKER_SRCS = 	srcs/checker/main.c srcs/parser/parser.c srcs/get_next_line/get_next_line.c \
srcs/get_next_line/get_next_line_utils.c srcs/utils/utils.c srcs/operations/operations.c

PS_OBJS = ${PS_SRCS:.c=.o}

CHECKER_OBJS = ${CHECKER_SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror

.c.o:
	gcc -c $< -o $(<:.c=.o)

PS_NAME = push_swap
CHECKER_NAME = checker

all: $(CHECKER_NAME) $(PS_NAME)

$(PS_NAME): $(PS_OBJS)
	gcc $(FLAGS) -o $(PS_NAME) $(PS_OBJS)

$(CHECKER_NAME): $(CHECKER_OBJS)
	gcc $(FLAGS) -o $(CHECKER_NAME) $(CHECKER_OBJS)


clean:
	rm -f $(PS_OBJS)
	rm -f $(CHECKER_OBJS)

fclean: clean
	rm -f $(PS_NAME)
	rm -f $(CHECKER_NAME)

re: fclean $(PS_NAME) $(CHECKER_NAME)

.PHONY: clean fclean re

