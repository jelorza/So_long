#include "so_long.h"

//Tengo las imagenes credas. Ahora voy con la gestion de ls hooks y movimientos. Paa eso tengo que contar los objetos, y la posicion en la que esta el jugador. Pongo los contadores en el struct_map. Hago una funcion donde gestiono la tecla y la tecla la linko con una funcion ue haga el movimiento y cambie la imegen del mapa.

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
		ft_hooks();
		printf("Height %d\n", map.map_height);
		printf("Width %d\n", map.map_width);
		ft_free(&map);
    	mlx_loop(mlx.mlx);
	}
	else
		printf("argv error");
	system("leaks so_long");
	return (0);
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

void	ft_create_map(t_arg_map *map, t_mlx_mlx *mlx)
{
	ft_create_wall_and_floor(map, mlx);
	ft_create_objects(map, mlx);
	ft_create_player(map, mlx);
//	ft_create_exit(map, mlx);
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

void	ft_create_objects(t_arg_map *map, t_mlx_mlx *mlx)
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
				map->chars[0]++;
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
