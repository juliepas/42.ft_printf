# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpascal <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 22:47:15 by jpascal           #+#    #+#              #
#    Updated: 2016/11/24 00:55:48 by jpascal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

SRC_NAME = ft_atoi.c \
		   ft_isalnum.c \
		   ft_isalpha.c \
		   ft_isascii.c \
		   ft_isdigit.c \
		   ft_isprint.c \
		   ft_putchar.c \
		   ft_putendl.c \
		   ft_putstr.c \
		   ft_strcat.c \
		   ft_strchr.c \
		   ft_strclr.c \
		   ft_strcmp.c \
		   ft_strcpy.c \
		   ft_strdup.c \
		   ft_strequ.c \
		   ft_strlen.c \
		   ft_strncat.c \
		   ft_strncmp.c \
		   ft_strncpy.c \
		   ft_strnequ.c \
		   ft_strrchr.c \
		   ft_toupper.c \
		   ft_tolower.c \
		   ft_strnew.c \
		   ft_putnbr.c \
		   ft_putchar_fd.c \
		   ft_putstr_fd.c \
		   ft_putendl_fd.c \
		   ft_putnbr_fd.c \
		   ft_striter.c \
		   ft_striteri.c \
		   ft_memalloc.c \
		   ft_memdel.c \
		   ft_strdel.c \
		   ft_strstr.c \
		   ft_strnstr.c \
		   ft_strsub.c \
		   ft_strjoin.c \
		   ft_strtrim.c \
		   ft_strlcat.c \
		   ft_memset.c \
		   ft_bzero.c \
		   ft_memcpy.c \
		   ft_memccpy.c \
		   ft_memmove.c \
		   ft_strmap.c \
		   ft_strmapi.c \
		   ft_memchr.c \
		   ft_memcmp.c \
		   ft_itoa.c \
		   ft_strsplit.c \
		   ft_lstnew.c \
		   ft_lstdelone.c \
		   ft_lstdel.c \
		   ft_lstadd.c \
		   ft_lstiter.c \
		   ft_lstmap.c \
		   ft_count_words.c \
		   ft_swap.c \
		   ft_nbrlen.c \
		   ft_puttab.c \
		   ft_puttab_fd.c \
		   ft_strchrint.c \
		   ft_strjoinchar.c \
		   ft_putnbrendl.c \
		   ft_strjoinfree.c \
		   ft_strrev.c \
		   ft_itoa_base.c \
		   ft_strjoincharrev.c

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = 	obj/

CC = gcc

CFLAGS = -Werror -Wall -Wextra -g

CPPFLAGS = -I includes

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)
	
$(NAME):
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPLAGS) -c $(SRC_NAME)
	@mv $(OBJ_NAME) $(OBJ_PATH)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -f $(NAME)

re: fclean all
