# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlely <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/12 13:17:54 by hlely             #+#    #+#              #
#    Updated: 2018/04/24 12:51:31 by hlely            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc

FLAGS = -Wall -Wextra

### FDF ###
PRINTF_NAME = main.c			\
			  key_event.c		\
			  parse_input.c		\
			  fill_point.c		\
			  isometric.c		\
			  img.c				\
			  ft_put_pixel.c	
PRINTF_PATH = /
SRC = $(addprefix $(PRINTF_PATH), $(PRINTF_NAME))


### PATHS OBJECTS AND SOURCE FILES ###
PATHSRC = ./srcs/
SRCS = $(addprefix $(PATHSRC), $(SRC))
OBJ = $(SRCS:.c=.o)

### LIBFT ###
LIBINC = ./libft
INC += -I$(LIBINC)/includes

### FDF INCLUDES ###
INCLUDES = ./includes/
INC += -I$(INCLUDES)

ifneq ($(NOERR),yes)
	FLAGS += -Werror
endif

ifeq ($(DEV),yes)
	FLAGS += -g
endif

ifeq ($(SAN),yes)
	FLAGS += -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
endif

OBJ = $(SRCS:%.c=%.o)

LIB = ./libft/libft.a ./minilibx_macos/libmlx.a

all : makelib $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) -framework OpenGL -framework AppKit $(INC) -o $@ $^ $(LIB)
	@echo "\033[K\033[35m***** done *****\033[0m"

%.o:%.c
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<
	@echo "\033[38;2;255;95;30m\c"
	@echo " [$@] > compiled\033[0m\033[K\c"
	@echo "\033[70D\c"

makelib :
	@make -C $(LIBINC) NOERR=$(NOERR) DEV=$(DEV) SAN=$(SAN)

clean : cleanlib
	@/bin/rm -rf $(OBJ)
	@echo "\033[31m--== objects trashed ==--\033[0m"

cleanlib :
	@make clean -C ./libft

fclean : fcleanlib clean
	@/bin/rm -f $(NAME)
	@echo "\033[033m--== binary trashed ==--\033[0m"

fcleanlib :
	@make fclean -C ./libft

re : fclean all

.PHONY : all clean fclean re
