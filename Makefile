NAME = so_long

SRC = so_long.c gnl/get_next_line.c gnl/get_next_line_utils.c

OBJS = $(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

RM = rm -r -f
MLX = -L mlx -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

%.o: %.c
	$(CC)  -Imlx -c $< -o $@

$(NAME): $(OBJS)
	make -C mlx/
	$(CC) $(FLAGS) $^ $(MLX) -o $@

clean:
	$(RM) $(OBJS)
	make clean -C mlx/

fclean: clean
	$(RM) $(NAME)

re: fclean all
