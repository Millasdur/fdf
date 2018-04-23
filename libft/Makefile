# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlely <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/12 13:17:54 by hlely             #+#    #+#              #
#    Updated: 2018/04/23 14:15:19 by hlely            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
AR = ar rc

### FT_PRINTF ###
PRINTF_NAME = ft_printf.c		\
			  ft_converter.c	\
			  ft_number.c		\
			  ft_unumber.c		\
			  ft_octal.c		\
			  ft_get_attr.c		\
			  ft_padding.c		\
			  ft_get_number.c	\
			  handle_plus_space.c	\
			  ft_handle_hash.c		\
			  ft_string.c			\
			  ft_else.c				\
			  ft_pointer.c			\
			  ft_char.c				\
			  ft_strpadding.c		\
			  ft_charpadding.c		\
			  ft_flag.c			
PRINTF_PATH = ft_printf/
SRC = $(addprefix $(PRINTF_PATH), $(PRINTF_NAME))

### LIBFT ###
LIB_NAME = ft_putchar.c\
		   ft_epur.c\
		   ft_puterr.c\
		   ft_puterrnl.c\
		   ft_realloc.c\
		   ft_swapstr.c\
		   ft_nb_word.c\
		   ft_list_at.c\
		   ft_list_size.c\
		   ft_nbdigit.c\
		   get_next_line.c\
		   ft_putnbrcolor.c\
		   ft_putcolornl.c\
		   ft_match.c\
		   ft_putcolor.c\
		   ft_tablen.c\
		   ft_tabdel.c\
		   ft_putcolornl.c\
		   ft_list_reverse.c\
		   ft_list_sort.c\
		   ft_issort.c\
		   ft_atoi.c\
		   ft_power.c\
		   ft_sqrt.c\
		   ft_bzero.c\
		   ft_isalnum.c\
		   ft_isalpha.c\
		   ft_isascii.c\
		   ft_isdigit.c\
		   ft_isprint.c\
		   ft_itoa.c\
		   ft_itoa_base.c\
		   ft_uitoa_base.c\
		   ft_lstadd.c\
		   ft_lstaddlast.c\
		   ft_lstdel.c\
		   ft_lstdelone.c\
		   ft_lstiter.c\
		   ft_lstmap.c\
		   ft_lstnew.c\
		   ft_memalloc.c\
		   ft_memccpy.c\
		   ft_memchr.c\
		   ft_memcmp.c\
		   ft_memcpy.c\
		   ft_memdel.c\
		   ft_memmove.c\
		   ft_memset.c\
		   ft_putchar.c\
		   ft_putchar_fd.c\
		   ft_putendl.c\
		   ft_putendl_fd.c\
		   ft_putnbr.c\
		   ft_putnbr_fd.c\
		   ft_putstr.c\
		   ft_putnstr.c\
		   ft_putstr_fd.c\
		   ft_strcat.c\
		   ft_strchr.c\
		   ft_strclr.c\
		   ft_strcmp.c\
		   ft_strcpy.c\
		   ft_strdel.c\
		   ft_strdup.c\
		   ft_strequ.c\
		   ft_striter.c\
		   ft_striteri.c\
		   ft_strjoin.c\
		   ft_strjoindel.c\
		   ft_strjoinddel.c\
		   ft_strlcat.c\
		   ft_strlen.c\
		   ft_strmap.c\
		   ft_strmapi.c\
		   ft_strncat.c\
		   ft_strncmp.c\
		   ft_strncpy.c\
		   ft_strnequ.c\
		   ft_strnew.c\
		   ft_strnstr.c\
		   ft_strrchr.c\
		   ft_strsplit.c\
		   ft_strstr.c\
		   ft_strsub.c\
		   ft_strsubdel.c\
		   ft_strtrim.c\
		   ft_tolower.c\
		   ft_lowercase.c\
		   ft_uppercase.c\
		   ft_abs.c\
		   ft_toupper.c
LIB_PATH = libft/
SRC += $(addprefix $(LIB_PATH), $(LIB_NAME))

### PATHS OBJECTS AND SOURCE FILES ###
PATHSRC = ./srcs/
SRCS = $(addprefix $(PATHSRC), $(SRC))
OBJ = $(SRCS:.c=.o)

### INCLUDES ###
LIBINCLUDES = includes/
LIBINC = -I$(LIBINCLUDES)
LFLAGS = -Wall -Wextra

ifneq ($(NOERR),yes)
	LFLAGS += -Werror
endif

ifeq ($(DEV),yes)
	LFLAGS += -g
endif

ifeq ($(SAN),yes)
	LFLAGS += -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
endif

all : $(NAME)

$(NAME) : $(OBJ)
	@$(AR) $@ $^
	@ranlib $@
	@echo
	@echo "\033[1;38;2;255;244;24m <<< libft -> ready >>>\033[0m"

%.o:%.c
	@$(CC) $(LFLAGS) $(LIBINC) -o $@ -c $<
	@echo "\033[38;2;255;95;30m\c"
	@echo "Compilation" $<"\033[0m\033[K\c"
	@echo "\033[70D\c"

clean :
	@/bin/rm -rf $(OBJ)


fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
