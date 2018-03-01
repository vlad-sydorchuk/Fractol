#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 08:42:30 by vsydorch          #+#    #+#              #
#    Updated: 2017/04/19 10:10:10 by vsydorch         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol
LIB = libft/libft.a
SRCS =  srcs/main.c srcs/one_fractol.c srcs/additional.c srcs/ft_info.c\
	srcs/ft_hooks.c srcs/ft_init_st.c srcs/ft_itoa_upd.c\
	srcs/mandatory.c srcs/bonus.c
HEADERS = includes/fractol.h
FLAGS = -Wall -Wextra -Werror -g
FLAGS_MLX = -lmlx -framework OpenGl -framework AppKit
BINS = $(SRCS:.c=.o)
all: $(NAME)
libclean:
	make -C libft/ clean
libfclean:
	make -C libft/ fclean
$(NAME): $(BINS)
	make -C libft/
	gcc -o $(NAME) $(BINS) $(FLAGS) $(FLAGS_MLX) $(LIB)
%.o: %.c
	gcc $(FLAGS) -c -o $@ $<
clean: libclean
	/bin/rm -f $(BINS)
fclean: libfclean clean
	/bin/rm -f $(NAME)
re: fclean all