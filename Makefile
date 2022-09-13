# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 12:16:17 by hepiment          #+#    #+#              #
#    Updated: 2022/09/12 18:45:14 by hepiment         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
INCLUDE = -I ./include/
CFLAGS = -g -Wall -Wextra -Werror


RM = rm -rf

PATH_SRC = ./src/

PATH_OBJS = ./objs/

SRC =	$(PATH_SRC)pipex.c \
		$(PATH_SRC)execute.c \
		$(PATH_SRC)utils.c \

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) -Llibft -lft -o $(NAME)

$(PATH_OBJS)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C ./libft
	$(RM) ./objs

fclean: clean
	@make fclean -C ./libft
	$(RM) $(NAME)

re: fclean all
	@make re -C ./libft

.PHONY: all clean fclean re