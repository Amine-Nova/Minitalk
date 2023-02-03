# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 17:16:31 by abenmous          #+#    #+#              #
#    Updated: 2023/02/01 19:54:14 by abenmous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

BONUS_SERVER = server_bonus

BONUS_CLIENT = client_bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror

PRINTF = printf/libftprintf.a


all : $(SERVER) $(CLIENT) 

$(SERVER) : server.o $(PRINTF)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT) : client.o function.o $(PRINTF)
	$(CC) $(CFLAGS) $^ -o $@

client.o function.o : client.c function.c

server.o: server.c

bonus : $(BONUS_SERVER) $(BONUS_CLIENT)

$(BONUS_SERVER) : server_bonus.o $(PRINTF)
		$(CC) $(CFLAGS) $^ -o $@
$(BONUS_CLIENT) : client_bonus.o function_bonus.o $(PRINTF)
		$(CC) $(CFLAGS) $^ -o $@

client_bonus.o function_bonus.o : client_bonus.c function_bonus.c

server_bonus.o: server_bonus.c

$(PRINTF):
	make -C printf

clean : 
	rm -rf *.o
	make clean -C printf

fclean : clean
	rm -rf $(SERVER) $(CLIENT)
	rm -rf $(BONUS_SERVER) $(BONUS_CLIENT)
	make fclean -C printf

re : fclean all

.PHONY: all clean bonus re