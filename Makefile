# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmorgana <tmorgana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/19 17:25:14 by tmorgana          #+#    #+#              #
#    Updated: 2020/01/20 19:54:06 by tmorgana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

Color_Off='\033[0m'

BRed='\033[4;31m'
BGreen='\033[3;32m'
BCyan='\033[1;36m'

NAME = fillit

SOURCES_DIRECTORY = ./sources/
SOURCE_FILES = read.c solve.c main.c help_solve.c check_figure.c

SORCES = $(addprefix $(SOURCE_DIRECORY), $(SOURCE_FILES))

OBJECT_FILES = $(patsubst %.c, %.o, $(SOURCE_FILES))
OBJECTS_DIRECTORY = ./objects/
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECT_FILES))

LIBRARYS_DIRECTORY = ./includes/libft/
LIBRARY = -lm -L $(LIBRARYS_DIRECTORY) -lft

HEADERS_DIRECTORY = ./includes/
HEADER_FILES = fillit.h
HEADER = $(addprefix $(HEADERS_DIRECTORY), $(HEADER_FILES))

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C $(LIBRARYS_DIRECTORY)
	@$(CC) $(FLAGS) $^ $(LIBRARY) -o $(NAME)
	@printf $(BGreen)"CONGRATULATIONS!!! Program has been created\n"$(Color_Off)

$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY)%.c $(HEADER)
	@mkdir -p $(OBJECTS_DIRECTORY)
	@$(CC) $(FLAGS) -c $< -o $@ -I $(HEADERS_DIRECTORY)
	@printf $(BCyan)"$(CC)$(FLAGS) -c $< -o $@ -I $(HEADERS_DIRECTORY)\n"$(Color_Off)

clean:
	@/bin/rm -rf $(OBJECTS_DIRECTORY)
	@make clean -C ./includes/libft
	@printf $(BRed)"Objects cleared\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f ./includes/libft/libft.a
	@printf "Binaries have been cleared\n"$(Color_Off)

re: fclean all