# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bruda-si <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 15:49:29 by bruda-si          #+#    #+#              #
#    Updated: 2023/10/09 15:59:14 by bruda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -std=c99
SRC = ft_memset.c ft_bzero.c ft_isalnum.c ft_isdigit.c ft_isalpha.c ft_isascii.c ft_strlen.c \
	ft_strlcpy.c ft_memmove.c ft_memcpy.c ft_isprint.c ft_strlcat.c ft_tolower.c ft_toupper.c
OBJ = $(SRC:.c=.o)
PROGRAM = main.c

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

program: all
	$(CC) $(CFLAGS) $(PROGRAM) $(NAME)
	./a.out

.PHONY: all clean fclean re
