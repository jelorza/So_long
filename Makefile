NAME = so_long

BONUS = so_long_bonus

SRC = src/so_long.c gnl/get_next_line.c gnl/get_next_line_utils.c src/check_map_init.c src/check_map_line.c src/create_map_init.c src/create_map.c src/hook_movements_init.c src/hook_movements_finish.c src/hook_movements_put_imgs.c
SRCB = bonus/so_long_bonus.c gnl/get_next_line.c gnl/get_next_line_utils.c bonus/check_map_init_bonus.c bonus/check_map_line_bonus.c bonus/create_map_init_bonus.c bonus/create_map_bonus.c bonus/hook_movements_init_bonus.c bonus/hook_movements_finish_bonus.c bonus/hook_movements_put_imgs_bonus.c

OBJS = $(SRC:.c=.o)
BOBJS = $(SRCB:.c=.o)

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

bonus:	$(BONUS)

$(BONUS):	$(BOBJS)
			make -C mlx/
			$(CC) $(CFLAGS) $^ -o  $@ $(MLX)
			
clean:
	$(RM) $(OBJS)
	$(RM) $(BOBJS)
	make clean -C mlx/

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS)

re: fclean all 

.PHONY:		all clean fclean re
