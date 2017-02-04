# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 15:25:55 by jcentaur          #+#    #+#              #
#    Updated: 2017/02/03 19:56:49 by jcentaur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c intsplit.c getmap.c draw.c drawmap.c drowaline.c

OBJ = $(SRC:%.c=%.o)

NAME = fdf

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o fdf -framework OpenGL -framework AppKit -lmlx -L./libft -lft

%.o:%.c
	gcc -o $@ -Wall -Werror -Wextra -c $<

clean:
	/bin/rm $(OBJ)

fclean: clean
	/bin/rm $(NAME)

re: fclean all
