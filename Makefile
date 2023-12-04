# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 15:55:17 by aleite-b          #+#    #+#              #
#    Updated: 2023/12/04 15:57:09 by aleite-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
FLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

SOURCES = src/check_sorted.c \
			src/index.c \
			src/instructions.c \
			src/instructions2.c \
			src/instructions3.c \
			src/lst.c \
			src/lst2.c \
			src/main.c \
			src/rotate_a.c \
			src/rotate_b.c \
			src/rotate_do.c \
			src/sort.c \
			src/utils.c \
			
OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

.c.o:
	$(CC) $(FLAGS) -I. -c $< -o $@

$(NAME): $(OBJECTS) 
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS)

bonus: $(BONUS_OBJECTS)
	$(CC) $(FLAGS) -o $(NAME) $(BONUS_OBJECTS)

all: $(NAME)

re: clean fclean all

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)
	make fclean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft


.PHONY: all clean fclean re bonus
