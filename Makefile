# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/14 14:00:58 by pemora            #+#    #+#              #
#    Updated: 2020/09/07 12:34:25 by lmariott         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_traceroute
CC ?= clang
CFLAGS ?= -Wall -Wextra -Werror -g3

SRC := src/main.c\
	   src/getopt.c\
	   src/resolv.c\
	   src/init.c\
	   src/fill_content.c\
	   src/fill_hdrs.c\
	   src/request_socket.c\
	   src/icmp6_checksum.c\
	   src/trouteloop.c\
	   src/send_packet.c\
	   src/is_mine.c\
	   src/is_done.c\
	   src/clean_troute.c

HDR := libft/libft.h	

HDRDIR := include/
LIBDIR := libft/

OBJ := $(SRC:.c=.o)
LIBFT := libft/libft.a
LIBS := $(LIBFT)

all: $(NAME) 

$(LIBFT):
	make -j 8 -C libft/

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBS) -I$(HDRDIR) -I$(LIBDIR)

%.o: %.c $(HDR) Makefile
	$(CC) $(CFLAGS) -o $@ -c $< -I$(HDRDIR) -I$(LIBDIR)

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
