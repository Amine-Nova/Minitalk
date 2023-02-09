# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 11:42:11 by abenmous          #+#    #+#              #
#    Updated: 2022/10/27 18:33:34 by abenmous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_putnbr_un.c ft_putnbr_hexu.c ft_putnbr_hex.c ft_putnbr_p.c \


NAME = libftprintf.a

CC		= gcc

CFLAGS  = -Wall -Werror -Wextra

RM		= rm -f

OBJS = ${SRCS:.c=.o}

$(NAME): $(OBJS)
	ar rcs ${NAME} ${OBJS}
%.o : %.c
	$(CC) $(CFLAGS) -c $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all