#include "so_long.h"

// Movimiento up creando, no me crea la imagen. Teng dos funciones, uno me cambia la casilla en la que eestoy y el otro me canbia a la nueva casilla.

int  main(int argc, char **argv)
{
	t_arg_map map;
	t_mlx_mlx mlx;

	if (argc == 2 && argv[1][ft_strlen(argv[1]) -1] == 'r' && argv[1][ft_strlen(argv[1]) - 2] == 'e' && argv[1][ft_strlen(argv[1]) - 3] == 'b')
	{
		ft_check_map(argv[1], &map);
		ft_get_map(&map, argv[1]);
		ft_map_init(argv[1], &map, &mlx);
		ft_create_map(&map, &mlx);
		ft_hooks(&mlx, &map);
		printf("Height %d\n", map.map_height);
		printf("Width %d\n", map.map_width);
    	mlx_loop(mlx.mlx);
	}
	else
		printf("argv error");
	ft_free(&map);
	system("leaks so_long");
	return (0);
}

void	ft_change_up(t_arg_map *map, t_mlx_mlx *mlx, char c)
{
	t_mlx_img img;

	if (map->map_data[(map->p_pos[0]) - 1][map->p_pos[1]] == 'C')
	{
		printf("objects = %d\n", map->chars[1]);
		map->chars[1]--;
	}
	map->map_data[0][1] = '0';
	img.img1 = mlx_xpm_file_to_image(mlx->mlx, "./bob.xpm", &img.width, &img.height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img1, map->p_pos[0] * 50, map->p_pos[1] * 50);


}

void	ft_change_img(t_arg_map *map, t_mlx_mlx *mlx)
{
	t_mlx_img img;

	printf("objects = %d\n", map->chars[1]);
	printf("%c\n", map->map_data[map->p_pos[0]][map->p_pos[1]]);
	printf("%d\n", map->p_pos[0]);
	printf("%d\n", map->p_pos[1]);
	map->map_data[map->p_pos[0]][map->p_pos[1]] = '0';
	printf("%c\n", map->map_data[map->p_pos[0]][map->p_pos[1]]);
	map->p_pos[0]--;
	printf("%d\n", map->p_pos[0]);
//	mlx_destroy_image(mlx->mlx, img_ptr);
//	img.img1 = mlx_xpm_file_to_image(mlx->mlx, "./water.xpm", &img.width, &img.height);
//	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img1, map->p_pos[0] * 50, map->p_pos[1] * 50);
}

void 	ft_move_up(t_arg_map *map, t_mlx_mlx *mlx)
{
	char charact;

	if (map->map_data[(map->p_pos[0]) - 1][map->p_pos[1]] != '1')
	{
		charact = map->map_data[(map->p_pos[0]) - 1][map->p_pos[1]];
		ft_change_img(map, mlx);
	//	ft_change_up_img(map, mlx);
	}
}

void	ft_get_moves(t_arg_map *map, t_mlx_mlx *mlx)
{
	if (mlx->key == 'w')
		ft_move_up(map, mlx);
/*
	if (mlx->key == 'd')
		ft_move_right();
	if (mlx->key == 'a')
		ft_move_left();
	if (mlx->key == 's')
		ft_move_down();
	else if (mlx->key == 'x')
		exit(0);
*/
	printf("%c\n", mlx->key);	
}

int	key_hook(int kc, t_arg_map *map, t_mlx_mlx *mlx)
{
	if (kc == 13)
		mlx->key = 'w';
	else if (kc == 2)
		mlx->key = 'd';
	else if (kc == 0)
		mlx->key = 'a';
	else if (kc == 1)
		mlx->key = 's';
	else if (kc == 53)
		mlx->key = 'x';
	if (kc == 13 || kc == 2 || kc == 0 || kc == 1 || kc == 53)
		ft_get_moves(map, mlx);
	return (0);
}

void	ft_hooks(t_mlx_mlx *mlx, t_arg_map *map)
{
	int i = 0;
//	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_key_hook(mlx->win, key_hook, map);
}

void	ft_create_map(t_arg_map *map, t_mlx_mlx *mlx)
{
	ft_create_wall_and_floor(map, mlx);
	ft_create_objects_and_exit(map, mlx);
	ft_create_player(map, mlx);
}

void	ft_create_player(t_arg_map *map, t_mlx_mlx *mlx)
{
	t_mlx_img img;
	int y;
	int x;

	y = 0;
	img.img1 = mlx_xpm_file_to_image(mlx->mlx, "./bob.xpm", &img.width, &img.height);
	while (y < map->map_height)
	{
		x = 0;
		while (x < map->map_width)
		{
			if (map->map_data[y][x] == 'P' )
				mlx_put_image_to_window(mlx->mlx, mlx->win, img.img1, x * 50, y * 50);
			x++;	
		}
		y++;
	}
}

void	ft_create_objects_and_exit(t_arg_map *map, t_mlx_mlx *mlx)
{
	t_mlx_img img;
	int y;
	int x;

	y = 0;
	img.img1 = mlx_xpm_file_to_image(mlx->mlx, "./burger1.xpm", &img.width, &img.height);
	while (y < map->map_height)
	{
		x = 0;
		while (x < map->map_width)
		{
			if (map->map_data[y][x] == 'C' )
				mlx_put_image_to_window(mlx->mlx, mlx->win, img.img1, x * 50, y * 50);
			x++;	
		}
		y++;
	}
}

void	ft_create_wall_and_floor(t_arg_map *map, t_mlx_mlx *mlx)
{
	t_mlx_img img;
	int y;
	int x;

	y = 0;
	img.img1 = mlx_xpm_file_to_image(mlx->mlx, "./wall.xpm", &img.width, &img.height);
	img.img2 = mlx_xpm_file_to_image(mlx->mlx, "./water.xpm", &img.width, &img.height);
	while (y < map->map_height)
	{
		x = 0;
		while (x < map->map_width)
		{
			if (map->map_data[y][x] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, img.img1, x * 50, y * 50);
			else if (map->map_data[y][x] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->win, img.img2, x * 50, y * 50);
			x++;
		}
		y++;
	}
}

void	ft_map_init(char *arg, t_arg_map *map, t_mlx_mlx *mlx)
{
	mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, map->map_width * 50, map->map_height * 50, "So Long");
  	mlx->img = mlx_new_image(mlx->mlx, map->map_width * 50, map->map_height * 50);
//	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
}

void	ft_get_map(t_arg_map *map, char *argv)
{
	int i;
	int fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("");
		exit(1);
	}
	printf("%d\n", map->map_height);
	map->map_data = malloc (sizeof(char*) * map->map_height + 1);
	if (!map->map_data)
		exit(1);
	while (i < map->map_height)
	{
		map->map_data[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	map->map_data[i] = 00;
	i = 0;
	while (i < map->map_height)
	{
		printf("%s", map->map_data[i]);
		i++;
	}

}

void	ft_check_map(char *argv, t_arg_map *map)
{
	ft_get_height(argv, map);
	ft_get_width(argv, map);
}

void	ft_get_width(char *argv, t_arg_map *map)
{
	int		fd;
	char	*line;
	int		i;
	
	map->chars[0] = 0;
	map->chars[1] = 0;
	map->chars[2] = 0;
	i = 1;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("");
		exit(1);
	}
	line = get_next_line(fd);
	map->map_width = ft_strlen(line);
	while (line)
	{
		ft_check_line(line, i++, map);
		free(line);
		line = get_next_line(fd);
		if (line)
		{
			if (ft_strlen(line) != map->map_width)
			{
				perror("El mapa no es rectangulo");
				exit(1);
			}
		}
	}
	map->map_width--;
	close(fd);
	if (map->chars[1] < 1 || map->chars[2] < 1)
	{
		perror("El mapa no contiene ni 'e' ni 'c'");
		exit(1);
	}
	else if(map->chars[0] != 1)
	{
		perror("Algo pasa con el p");
		exit(1);
	}
}

void	ft_check_line(char *line, int line_counter, t_arg_map *map)
{
	int i;

	i = 0;
	printf("%d\n", line_counter);
	if(line_counter == 1 || line_counter == map->map_height)
	{
		while (i < ft_strlen(line) - 1)
		{
			if (line[i] != '1')
			{
				perror("El mapa no esta cerrado correctamente");
				exit(1);
			}
			i++;
		}
	}
	else
	{
		while (i < ft_strlen(line) - 1)
		{
			if (line[0] != '1' || line[map->map_width - 2] != '1')
			{
				perror("El mapa no esta cerrado correctamentee");
				exit(1);
			}
			else if (line[i] != '1' && line[i] != '0' && line[i] != 'P' && line[i] != 'E' && line[i] != 'C')
			{
				perror("El mapa contiene caracteres incorrectos");
				exit(1);
			}
			else if(line[i] == 'P')
			{
				map->chars[0]++;
				map->p_pos[0] = line_counter - 1;
				map->p_pos[1] = i;
			}
			else if(line[i] == 'C')
				map->chars[1]++;
			else if(line[i] == 'E')
				map->chars[2]++;
			i++;
		}
	}
}

void	ft_get_height(char *argv, t_arg_map *map)
{
	int		fd;
	char	*line;
	
	map->map_height = 0;
	fd = open(argv, O_RDONLY);
	line = malloc (1);
	if (fd == -1)
	{
		perror("");
		exit(1);
	}
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		map->map_height++;
	}
//	free(line);
	close(fd);
	map->map_height--;
}

void	ft_free(t_arg_map *map)
{
	int i;

	printf("Height %d\n", map->map_height);
	i = 0;
	while (i < map->map_height)
	{
		free(map->map_data[i]);
		i++;
	}
	free(map->map_data);
}
