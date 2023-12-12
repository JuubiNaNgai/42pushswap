# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 15:55:17 by aleite-b          #+#    #+#              #
#    Updated: 2023/12/12 14:19:29 by aleite-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

CC = cc
FLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

SOURCES = push_swap_src/index.c \
			push_swap_src/main.c \
			push_swap_src/rotate.c \
			push_swap_src/rotate_do.c \
			push_swap_src/sort.c \
			utils/args.c \
			utils/instructions.c \
			utils/instructions2.c \
			utils/instructions3.c \
			utils/is_sorted.c \
			utils/lst.c \
			utils/lst2.c \
			utils/utils.c \

BONUS_SOURCES = checker_src/get_next_line.c \
			checker_src/get_next_line_utils.c \
			checker_src/main.c \
			utils/args.c \
			utils/instructions.c \
			utils/instructions2.c \
			utils/instructions3.c \
			utils/is_sorted.c \
			utils/lst.c \
			utils/lst2.c \
			utils/utils.c \
			
OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS) 
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS)

bonus: $(BONUS_OBJECTS)
	$(CC) $(FLAGS) -o $(BONUS_NAME) $(BONUS_OBJECTS)

all: $(NAME)

re: clean fclean all

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)


.PHONY: all clean fclean re bonus
