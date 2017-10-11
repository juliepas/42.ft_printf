# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpascal <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 22:47:15 by jpascal           #+#    #+#              #
#    Updated: 2017/05/22 19:18:27 by jpascal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PATH = ./

SRC_NAME =	ft_printf.c \
			parseur_printf.c \
			add_struct.c \
			attributs.c \
			convert_string.c \
			convert_char.c \
			convert_decimal.c \
			gestion_precision.c \
			itoa_base_spe.c \
			itoa_base_x.c \
			convert_octal.c \
			convert_hexadecimal.c \
			printstr.c \
			ft_memalloc.c \
			ft_atoi.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_nbrlen.c \
			ft_putchar.c \
			ft_putnbr.c \
			ft_putstr.c \
			ft_strchrint.c \
			ft_strdel.c \
			ft_strjoinchar.c \
			ft_strlen.c \
			ft_strncat.c \
			ft_strnew.c \
			ft_bzero.c \
			ft_strcmp.c \
			ft_strdup.c \
			ft_strjoinfree.c \
			ft_strjoin.c \
			ft_isalpha.c \
			ft_memmove.c \
			ft_memdel.c \
			ft_strncpy.c

OBJ_NAME = $(SRC_NAME:.c=.o)

LIB_NAME = libft.a

LIB_PATH =  libft/

OBJ_PATH = 	./obj/

CC = gcc

W_FLAGS = -Werror -Wall -Wextra -g

I_FLAGS = -I includes

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix $(LIB_PATH),$(LIB_NAME))

all: $(NAME)

$(NAME):
	@make -C $(LIB_PATH)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -c $(SRC) $(I_FLAGS) $(W_FLAGS)
	@mv $(OBJ_NAME) $(OBJ_PATH)
	@ar rc $(NAME) $(OBJ) $(LIB)

clean:
	@make clean -C $(LIB_PATH)
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME) 

re: fclean all