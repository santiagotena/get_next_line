# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 21:39:54 by stena-he          #+#    #+#              #
#    Updated: 2022/06/10 23:42:17 by stena-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	get_next_line.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = get_next_line.c get_next_line_utils.c main.c
			
OUT_SRC = $(SRC:%.c=%.o)

g:
	gcc $(CFLAGS) $(SRC)
	./a.out

all: $(NAME)

$(NAME): $(OUT_SRC)
	ar -rcs	$(NAME)	$(OUT_SRC)

clean:
	${RM} $(OUT_SRC)

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re