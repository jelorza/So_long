NAME = so_long

SRC = so_long.c gnl/get_next_line.c gnl/get_next_line_utils.c check_map.c hook_movements.c create_map.c

OBJS = $(SRC:.c=.o)

CC = gcc -fsanitize=address -g3
FLAGS = -Wall -Wextra -Werror

RM = rm -r -f
MLX = -L mlx -lmlx -framework OpenGL -framework Appkit
SAN = -g3 -fsanitize=address

all: $(NAME)

%.o: %.c
	$(CC) -c $< -o $@ -Imlx

$(NAME): $(OBJS)
	make -C mlx/
	$(CC) $(FLAGS) $^ -o  $@ $(MLX) #$(SAN)

clean:
	$(RM) $(OBJS)
	make clean -C mlx/

fclean: clean
	$(RM) $(NAME)

re: fclean all
