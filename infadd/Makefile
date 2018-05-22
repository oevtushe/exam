NAME		:= inf_add

OBJS_DIR	:= objs

SRCS		:= ft_strnew.c \
			   ft_strlen.c \
			   add_values.c \
			   prefix_tools.c \
			   main.c
OBJS		:= $(SRCS:%.c=$(OBJS_DIR)/%.o)

DEPS		:= inf_add.h

CC			:= gcc
CKEYS		:= -Wall -Werror -Wextra
RM			:= rm -rf

$(NAME): $(OBJS)
	@$(CC) $(CKEYS) -o $@ $^

$(OBJS_DIR)/%.o: %.c $(DEPS)
	@$(CC) $(CKEYS) -c $< -o $@

clean:
	@$(RM) $(OBJS_DIR)

$(OBJS): |$(OBJS_DIR)

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)
