NAME = push_swap

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I include -I external/ft_printf -I external/libft

# ================= LIBRARIES ================= #

LIBFT_DIR = external/libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = external/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

# ================= SOURCES ================= #

SRC = \
src/main/push_swap.c \
src/utils/push_swap_utils_1.c \
src/utils/push_swap_utils_2.c \
src/utils/push_swap_utils_3.c \
src/utils/algorithm_utils_2.c \
src/utils/indexing.c \
src/parsing/validation_utils_1.c \
src/parsing/validation_utils_2.c \
src/operations/stack_operations.c \
src/algorithms/core/algorithms_utils.c \
src/algorithms/simple/simple_algorithm.c \
src/algorithms/simple/simple_algorithm_utils.c \
src/algorithms/medium/medium_algorithm.c \
src/algorithms/medium/medium_algorithm_utils_1.c \
src/algorithms/medium/medium_algorithm_utils_2.c \
src/algorithms/medium/medium_algorithm_utils_3.c \
src/algorithms/medium/medium_algorithm_utils_4.c \
src/algorithms/medium/medium_algorithm_utils_5.c \
src/algorithms/complex/complex_algorithm.c \
src/algorithms/complex/complex_algorithm_utils.c

OBJ = $(SRC:.c=.o)

RM = rm -f

# ================= RULES ================= #

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(FT_PRINTF) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
