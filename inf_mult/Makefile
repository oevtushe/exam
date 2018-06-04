# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/04 11:15:21 by oevtushe          #+#    #+#              #
#    Updated: 2018/06/04 16:47:00 by oevtushe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= inf_mult

IM_OBJS_DIR := objs

IM_SRCS		:= main.c		 \
			   ft_strnew.c	 \
			   ft_strcmp.c	 \
			   ft_putstr.c	 \
			   ft_memalloc.c \
			   swap_funcs.c	 \
			   mult_values.c \
			   prefix_add.c	 \
			   ft_strlen.c

IM_OBJS		:= $(IM_SRCS:%.c=$(IM_OBJS_DIR)/%.o)

IM_DEPS		:= inf_mult.h

CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra
RM			:= rm -rf

all: $(NAME)

$(NAME): $(IM_OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $^
	@echo "Executable $(NAME) created !"

clean:
	@$(RM) $(IM_OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean
	@$(MAKE)

$(IM_OBJS_DIR)/%.o: %.c $(IM_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(IM_OBJS): |$(IM_OBJS_DIR)

$(IM_OBJS_DIR):
	@mkdir $@
