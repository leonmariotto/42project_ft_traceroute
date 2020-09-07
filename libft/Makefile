# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 20:17:20 by llenotre          #+#    #+#              #
#    Updated: 2020/05/03 16:58:00 by lmariott         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC =	ft_putstr.c\
         ft_arrinsert.c\
         ft_sort.c\
         ft_lstdelone.c\
         default_del.c\
         ft_putnstr_fd.c\
         ft_pow.c\
         ft_strncat.c\
         ft_fibonacci.c\
         ft_putstr_fd.c\
         ft_isupper.c\
         ft_last_char.c\
         ft_lstrev.c\
         ft_path_merge.c\
         ft_strcpy.c\
         ft_putendl.c\
         ft_striteri.c\
         ft_lstpush.c\
         ft_arrremove.c\
         ft_isprint.c\
         ft_arrtolst.c\
         ft_memchr.c\
         ft_memccpy.c\
         ft_lstnew_nodup.c\
         ft_strnequ.c\
         ft_putendl_fd.c\
         ft_strsplit.c\
         ft_strnulljoin.c\
         ft_lstback.c\
         ft_isalpha.c\
         ft_putnbr.c\
         ft_memcmp.c\
         ft_strlcat.c\
         ft_strncmp.c\
         ft_lstnew.c\
         ft_strsub.c\
         ft_strlen.c\
         ft_strnew.c\
         ft_strrchr.c\
         ft_strmap.c\
         ft_swap.c\
         ft_strstr.c\
         ft_get_filename.c\
         ft_strchr.c\
         ft_lstget.c\
         ft_putchar_fd.c\
         ft_itoabase.c\
         ft_putchar.c\
         ft_intlen.c\
         ft_tolower.c\
         ft_lstmap.c\
         ft_striter.c\
         ft_toupper.c\
         ft_factorial.c\
         ft_strrev.c\
         ft_memcpy.c\
         ft_strequ.c\
         ft_isdigit.c\
         ft_isspace.c\
         ft_memalloc.c\
         ft_atoibase.c\
         ft_itoa.c\
         ft_sqrt.c\
         ft_strtrim.c\
         ft_strnjoin.c\
         ft_lstsize.c\
         ft_arrdup.c\
         ft_lstadd.c\
         ft_lstdel.c\
         ft_isalnum.c\
         ft_isblank.c\
         ft_memdel.c\
         ft_isascii.c\
         ft_min.c\
         ft_lstiter.c\
         ft_max.c\
         ft_strnstr.c\
         ft_atoi.c\
         ft_bzero.c\
         ft_strclr.c\
         ft_strdel.c\
         ft_strdup.c\
         ft_strncpy.c\
         ft_putnbr_fd.c\
         ft_strcmp.c\
         ft_arrdup_str.c\
         ft_strjoin.c\
         ft_arrlen.c\
         ft_strcmp_casinsens.c\
         ft_arrfree.c\
         ft_lsttoarr.c\
         ft_strcat.c\
         ft_strmapi.c\
         ft_memset.c\
         ft_islower.c\
         ft_strndup.c\
         ft_memmove.c\
         ft_putnstr.c

HDR = libft.h, get_next_line.h
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
