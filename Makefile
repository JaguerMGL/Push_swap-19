# -----------------------------------Makefile------------------------------------
NAME 	= push_swap
DEBUG 	= debug.out
# -----------------------------------Sources-------------------------------------
SRCS	= free.c \
			ft_split_utils.c \
			ft_split.c \
			full_rot.c \
			init_stack_utils.c \
			init_stack.c \
			main.c \
			push_swap_utils.c \
			push_swap_utils2.c \
			push_swap.c \
			push.c \
			rev_rotate.c \
			rotate.c \
			swap.c \
			tiny_sort.c \
			top_rot.c \
			
SRC		= ${addprefix sources/, ${SRCS}}
OBJS	= ${SRC:.c=.o}
# -----------------------------------Compilation---------------------------------
CC			= cc
FLAGS		= -Wall -Wextra -Werror -Iincludes
RM			= rm -f
FSANITIZE	= -fsanitize=address -g
# -----------------------------------Rules---------------------------------------
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

debug: $(OBJS)
	$(CC) $(CFLAGS) $(FSANITIZE) $(OBJS) -o $(DEBUG)

clean:
	$(RM) $(OBJS)
	@echo "It's clean."

fclean: clean
	$(RM) $(NAME) $(DEBUG)
	@echo "It's super clean."

re: fclean all
# -----------------------------------.phony-------------------------------------
.PHONY: all clean fclean re debug