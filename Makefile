# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/05 17:35:05 by mbenkara          #+#    #+#              #
#    Updated: 2018/02/05 17:35:16 by mbenkara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = srcs/main.c srcs/ft_validator.c srcs/ft_utilities.c srcs/ft_utilities2.c srcs/ft_map.c srcs/ft_solver.c

OBJ = ./main.o ./ft_validator.o ./ft_utilities.o ./ft_utilities2.o ./ft_map.o ./ft_solver.o

LIBFT = make -C ./libft

LIBFT_RE = make re -C ./libft

INCLUDES = ./libft

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):
	$(LIBFT)
	gcc $(FLAGS) -I$(INCLUDES) -c $(SRC)
	gcc $(OBJ) -o $(NAME) -L./libft -lft

clean:
	/bin/rm -f $(OBJ)
	make clean -C ./libft

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C ./libft

re: fclean all
