# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 15:55:17 by aleite-b          #+#    #+#              #
#    Updated: 2023/12/07 20:36:47 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
FLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

SOURCES = push_swap/index.c \
			push_swap/main.c \
			push_swap/rotate_a.c \
			push_swap/rotate_b.c \
			push_swap/rotate_do.c \
			push_swap/sort.c \
			utils/instructions.c \
			utils/instructions2.c \
			utils/instructions3.c \
			utils/is_sorted.c \
			utils/lst.c \
			utils/lst2.c \
			utils/utils.c \

SOURCES = checker/get_next_line.c \
			checker/get_next_line_utils.c \
			checker/main.c \
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
	$(CC) $(FLAGS) -o $(NAME) $(BONUS_OBJECTS)

all: $(NAME)

re: clean fclean all

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)


.PHONY: all clean fclean re bonus
