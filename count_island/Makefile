NAME := count_island

SRCS := ft_memalloc.c \
		ft_strnew.c \
		read_line.c \
		read_map.c \
		is_valid_map.c \
		free_ptr_arr.c \
		ft_memrealloc.c \
		count_island.c
OBJ_DIR := obj
OBJS := $(SRCS:%.c=$(OBJ_DIR)/%.o)
KEYS := -Wall -Werror -Wextra -g

DEPS := island.h

all: $(NAME)

$(OBJ_DIR)/%.o: %.c $(DEPS)
	@echo "\033[34mCompiling: $@"
	@gcc $(KEYS) -o $@ -c $<


$(NAME): $(OBJS)
	@echo "\033[33mLinking..."
	@gcc $(KEYS) -o $(NAME) $^

$(OBJS): |$(OBJ_DIR)

clean:
	@echo "\033[32mCleaning..."
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
re: fclean
	@make -s

$(OBJ_DIR):
	mkdir obj
