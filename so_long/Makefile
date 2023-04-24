# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esordone <esordone@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 12:07:44 by esordone          #+#    #+#              #
#    Updated: 2023/04/24 12:09:42 by esordone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-------------------------------------COLORS-----------------------------------#
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#-----------------------------------VARIABLES----------------------------------#
NAME = so_long

SRC = so_long.c\

INCLUDE = so_long.h

OBJ = $(SRC:.c=.o)

LIBFT = libft

CC = gcc

FLAGS = -Wall -Werror -Wextra

CLEAN = rm -rf

HEADER = libft.h

#-------------------------------------RULES------------------------------------#
%.o : %.c $(INCLUDE) Makefile
	@$(CC) $(FLAGS) -c $< -o $@

all: makelibft $(NAME)
	@echo "$(GREEN)*SUCCESSFULL COMPILATION!* $(DEF_COLOR)"

makelibft :
	@$(MAKE) -C $(LIBFT) bonus
	@echo "$(YELLOW)Libft compiled!$(DEF_COLOR)"

$(NAME): $(OBJ) libft/libft.a
	@$(CC) $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)

clean:
	@$(CLEAN) $(OBJ)
	@cd libft && make clean
	@echo "$(RED)Object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(CLEAN) $(NAME)
	@cd libft && make fclean
	@echo "$(CYAN)Executables files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Everything has been remade!$(DEF_COLOR)"

.PHONY: all makelibft clean fclean re
