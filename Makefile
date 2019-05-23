# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 19:03:50 by ncoursol          #+#    #+#              #
#    Updated: 2019/05/23 16:14:15 by dberger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NO_COLOR = \033[0m
COMP_COLOR = \033[33m
BIN_COLOR = \033[32m
BIN2_COLOR = \033[36m
PROG_COLOR = \033[35m

NAME = ft_printf
CC = gcc
FLAGS = -Wall -Wextra -Werror

LIB_SRC = libftprintf.a

LIB_DIR = ./libft

SOURCES = ft_format_csp.c\
ft_format_di.c\
ft_format_f.c\
ft_format_ou.c\
ft_format_xx.c\
ft_check_add.c\
ft_convert.c\
ft_printf.c\
ft_lltoa.c\
ft_dtoh.c\
ft_otoa.c\

OBJ = $(SOURCES:.c=.o)

INCLUDE = ft_printf.h

.PHONY: all clean fclean re norme

$(NAME): $(OBJ)
	(cd $(LIB_DIR) && $(MAKE))
	$(CC) $(FLAGS) -c $(SOURCES)
	ar rc $(LIB_SRC) $(OBJ)
	ranlib $(LIB_SRC)
	$(CC) $(FLAGS) -o $(NAME) $(LIB_SRC) $(LIB_DIR)/libft.a
	@echo "$(COMP_COLOR)   --- Compiled ! ---  $(NO_COLOR)"

all: $(NAME)

norme: fclean
	norminette $(SRC)

clean:
	rm -rf $(OBJ)
	(cd $(LIB_DIR) && $(MAKE) $@)
	@echo "$(BIN2_COLOR)   --- Binary   deleted ---        $(NO_COLOR)"

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIB_SRC)
	(cd $(LIB_DIR) && $(MAKE) $@)
	@echo "$(PROG_COLOR)   --- Program  deleted ---        $(NO_COLOR)"

re: fclean all
