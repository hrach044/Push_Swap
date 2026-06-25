NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
		input_parse.c \
		stack_utils.c \
		stack_utils2.c \
		stack_utils3.c \
		stack_utils4.c \
		ft_split.c \
		stack_ops_swap.c \
		stack_ops_push.c \
		stack_ops_rotate.c \
		stack_ops_rrotate.c \
		disorder.c \
		benchmark.c \
		sort_simple.c \
		sort_medium.c \
		sort_complex.c \
		sort_adaptive.c \
		sort_hard.c

BONUS_SRCS = checker.c \
				bonus_utils.c \
				input_parse.c \
				stack_utils.c \
				stack_utils2.c \
				stack_utils3.c \
				stack_utils4.c \
				ft_split.c \
				stack_ops_push.c \
				stack_ops_swap.c \
				stack_ops_rotate.c \
				stack_ops_rrotate.c 

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re

