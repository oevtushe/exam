# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/28 13:45:43 by oevtushe          #+#    #+#              #
#    Updated: 2018/05/28 15:50:31 by oevtushe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= infadd

OBJS_DIR	:= objs

SRCS		:= ft_strnew.c \
			   ft_strlen.c \
			   ft_strcmp.c \
			   ft_putstr.c \
			   tr_lzeroes.c \
			   add_values.c \
			   prefix_tools.c \
			   main.c
OBJS		:= $(SRCS:%.c=$(OBJS_DIR)/%.o)

DEPS		:= infadd.h

CC			:= gcc
CKEYS		:= -Wall -Werror -Wextra
RM			:= rm -rf

$(NAME): $(OBJS)
	@$(CC) $(CKEYS) -o $@ $^

$(OBJS_DIR)/%.o: %.c $(DEPS)
	@$(CC) $(CKEYS) -c $< -o $@

clean:
	@$(RM) $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean
	@$(MAKE)

$(OBJS): |$(OBJS_DIR)

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)
