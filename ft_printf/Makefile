# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/01 18:54:43 by marvin            #+#    #+#              #
#    Updated: 2024/06/01 18:54:43 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
INCLUDE = ft_printf.h

SRC = ft_printf.c ft_basics.c ft_hexadecimals.c ft_pointers.c

OBJ = $(SRC:.c=.o)

CC = gcc
RM = rm -f
AR = ar rc
RN = ranlib

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I. -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(RN) $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
