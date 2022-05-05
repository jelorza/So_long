#include "so_long.h"

// Ya tengo todos los movimientos y pinto la salida cuando cojo todos los objetos. Tengo que cambiar el orden de las funciones al hace un movimiento para que desaparezca el objeto cuando me poso encima. Despues tengo que gestionar la salida. (con un booleano se si esta o no esta). Cuando me poso encima se cierra el programa. Tambien me falta gestioar el 'esc' y la 'x' roja. 

int  main(int argc, char **argv)
{

	t_mlx_mlx mlx;

	if (argc == 2 && argv[1][ft_strlen(argv[1]) -1] == 'r' && argv[1][ft_strlen(argv[1]) - 2] == 'e' && argv[1][ft_strlen(argv[1]) - 3] == 'b')
	{
		ft_check_map(argv[1], &mlx);
		ft_get_map(&mlx, argv[1]);
		ft_map_init(argv[1], &mlx);
		ft_create_map(&mlx);
		ft_hooks(&mlx);
		printf("Height %d\n", mlx.map_height);
		printf("Width %d\n", mlx.map_width);
    	mlx_loop(mlx.mlx);
	}
	else
		printf("argv error");
//	ft_free(&map);
	return (0);
}


void	ft_change_up_img(t_mlx_mlx *mlx, char c)
{
	if (mlx->map_data[(mlx->p_pos[0])][mlx->p_pos[1]] == 'C')
		mlx->chars[1]--;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs.img1, mlx->p_pos[1] * 50, mlx->p_pos[0] * 50);
}

void	ft_change_pos(t_mlx_mlx *mlx, char c)
{
	if (c == 'w')
		mlx->p_pos[0]--;
	else if (c == 'd') 
		mlx->p_pos[1]++;
	else if (c == 'a')
		mlx->p_pos[1]--;
	else if (c == 's')
		mlx->p_pos[0]++;
}

void	ft_change_img(t_mlx_mlx *mlx, char c)
{
	printf("objects = %d\n", mlx->chars[1]);
	printf("%c\n", mlx->map_data[mlx->p_pos[0]][mlx->p_pos[1]]);
	printf("%d\n", mlx->p_pos[0]);
	printf("%d\n", mlx->p_pos[1]);
	mlx->map_data[mlx->p_pos[0]][mlx->p_pos[1]] = '0';
	printf("%c\n", mlx->map_data[mlx->p_pos[0]][mlx->p_pos[1]]);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs.img4, mlx->p_pos[1] * 50, mlx->p_pos[0] * 50);
	ft_change_pos(mlx, c);
}

void 	ft_move_up(t_mlx_mlx *mlx, char c)
{
	char charact;

	charact = mlx->map_data[(mlx->p_pos[0]) - 1][mlx->p_pos[1]];
	if (charact != '1')
	{
		ft_change_img(mlx, c);
		ft_change_up_img(mlx, charact);
	}
}

void	ft_move_down(t_mlx_mlx *mlx, char c)
{
	char charact;

	charact = mlx->map_data[(mlx->p_pos[0]) + 1][mlx->p_pos[1]];
	if (charact != '1')
	{
		ft_change_img(mlx, c);
		ft_change_up_img(mlx, charact);
	}
}

void	ft_move_left(t_mlx_mlx *mlx, char c)
{
	char charact;

	charact = mlx->map_data[(mlx->p_pos[0])][mlx->p_pos[1] - 1];
	if (charact != '1')
	{
		ft_change_img(mlx, c);
		ft_change_up_img(mlx, charact);
	}
}

void	ft_move_right(t_mlx_mlx *mlx, char c)
{
	char charact;

	charact = mlx->map_data[(mlx->p_pos[0])][mlx->p_pos[1] + 1];
	if (charact != '1')
	{
		ft_change_img(mlx, c);
		ft_change_up_img(mlx, charact);
	}
}

void	ft_get_moves(t_mlx_mlx *mlx)
{
	if (mlx->key == 'w')
		ft_move_up(mlx, 'w');
	else if (mlx->key == 'd')
		ft_move_right(mlx, 'd');
	else if (mlx->key == 'a')
		ft_move_left(mlx, 'a');
	if (mlx->key == 's')
		ft_move_down(mlx, 's');
	if (mlx->chars[1] == 0)
		ft_put_exit(mlx);
/*
	else if (mlx->key == 'x')
		exit(0);
*/
	printf("%c\n", mlx->key);	
}

void	ft_put_exit(t_mlx_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs.img5, mlx->e_pos[1] * 50, mlx->e_pos[0] * 50);
}

int	key_hook(int kc, t_mlx_mlx *mlx)
{
	printf("%c\n", mlx->key);	
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
		ft_get_moves(mlx);
	return (0);
}




void	ft_hooks(t_mlx_mlx *mlx)
{
	int i = 0;
	mlx_hook(mlx->win, 2, 1L<<0, key_hook, mlx);
}

void	ft_save_imgs(t_mlx_mlx *mlx)
{
	mlx->imgs.img1 = mlx_xpm_file_to_image(mlx->mlx, "./bob.xpm", &mlx->imgs.width, &mlx->imgs.height);
	mlx->imgs.img2 = mlx_xpm_file_to_image(mlx->mlx, "./burger.xpm", &mlx->imgs.width, &mlx->imgs.height);
	mlx->imgs.img3 = mlx_xpm_file_to_image(mlx->mlx, "./wall.xpm", &mlx->imgs.width, &mlx->imgs.height);
	mlx->imgs.img4 = mlx_xpm_file_to_image(mlx->mlx, "./water.xpm", &mlx->imgs.width, &mlx->imgs.height);
	mlx->imgs.img5 = mlx_xpm_file_to_image(mlx->mlx, "./home.xpm", &mlx->imgs.width, &mlx->imgs.height);
}

void	ft_create_background(t_mlx_mlx *mlx)
{
	int y;
	int x;

	y = 0;
	while (y < mlx->map_height)
	{
		x = 0;
		while (x < mlx->map_width)
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs.img4, x * 50, y * 50);
			x++;	
		}
		y++;
	}
}

void	ft_create_map(t_mlx_mlx *mlx)
{	
	ft_save_imgs(mlx);
	ft_create_background(mlx);
	ft_create_wall_and_floor(mlx);
	ft_create_objects_and_exit(mlx);
	ft_create_player(mlx);
}

void	ft_create_player(t_mlx_mlx *mlx)
{
	int y;
	int x;

	y = 0;
	while (y < mlx->map_height)
	{
		x = 0;
		while (x < mlx->map_width)
		{
			if (mlx->map_data[y][x] == 'P' )
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs.img1, x * 50, y * 50);
			x++;	
		}
		y++;
	}
}

void	ft_create_objects_and_exit(t_mlx_mlx *mlx)
{
	int y;
	int x;

	y = 0;
	while (y < mlx->map_height)
	{
		x = 0;
		while (x < mlx->map_width)
		{
			if (mlx->map_data[y][x] == 'C' )
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs.img2, x * 50, y * 50);
			else if (mlx->map_data[y][x] == 'E' )
			{
				mlx->e_pos[0] = x;
				mlx->e_pos[1] = y;
			}
			x++;	
		}
		y++;
	}
}

void	ft_create_wall_and_floor(t_mlx_mlx *mlx)
{
	int y;
	int x;

	y = 0;
	while (y < mlx->map_height)
	{
		x = 0;
		while (x < mlx->map_width)
		{
			if (mlx->map_data[y][x] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs.img3, x * 50, y * 50);
			else if (mlx->map_data[y][x] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs.img4, x * 50, y * 50);
			x++;
		}
		y++;
	}
}

void	ft_map_init(char *arg, t_mlx_mlx *mlx)
{
	mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, mlx->map_width * 50, mlx->map_height * 50, "So Long");
  	mlx->img = mlx_new_image(mlx->mlx, mlx->map_width * 50, mlx->map_height * 50);
//	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
}

void	ft_get_map(t_mlx_mlx *mlx, char *argv)
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
	printf("%d\n", mlx->map_height);
	mlx->map_data = malloc (sizeof(char*) * mlx->map_height + 1);
	if (!mlx->map_data)
		exit(1);
	while (i < mlx->map_height)
	{
		mlx->map_data[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	mlx->map_data[i] = 00;
	i = 0;
	while (i < mlx->map_height)
	{
		printf("%s", mlx->map_data[i]);
		i++;
	}

}

void	ft_check_map(char *argv, t_mlx_mlx *mlx)
{
	ft_get_height(argv, mlx);
	ft_get_width(argv, mlx);
}

void	ft_get_width(char *argv, t_mlx_mlx *mlx)
{
	int		fd;
	char	*line;
	int		i;
	
	mlx->chars[0] = 0;
	mlx->chars[1] = 0;
	mlx->chars[2] = 0;
	i = 1;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("");
		exit(1);
	}
	line = get_next_line(fd);
	mlx->map_width = ft_strlen(line);
	while (line)
	{
		ft_check_line(line, i++, mlx);
		free(line);
		line = get_next_line(fd);
		if (line)
		{
			if (ft_strlen(line) != mlx->map_width)
			{
				perror("El mapa no es rectangulo");
				exit(1);
			}
		}
	}
	mlx->map_width--;
	close(fd);
	if (mlx->chars[1] < 1 || mlx->chars[2] < 1)
	{
		perror("El mapa no contiene ni 'e' ni 'c'");
		exit(1);
	}
	else if(mlx->chars[0] != 1)
	{
		perror("Algo pasa con el p");
		exit(1);
	}
}

void	ft_check_line(char *line, int line_counter, t_mlx_mlx *mlx)
{
	int i;

	i = 0;
	printf("%d\n", line_counter);
	if(line_counter == 1 || line_counter == mlx->map_height)
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
			if (line[0] != '1' || line[mlx->map_width - 2] != '1')
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
				mlx->chars[0]++;
				mlx->p_pos[0] = line_counter - 1;
				mlx->p_pos[1] = i;
			}
			else if(line[i] == 'C')
				mlx->chars[1]++;
			else if(line[i] == 'E')
				mlx->chars[2]++;
			i++;
		}
	}
}

void	ft_get_height(char *argv, t_mlx_mlx *mlx)
{
	int		fd;
	char	*line;
	
	mlx->map_height = 0;
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
		mlx->map_height++;
	}
//	free(line);
	close(fd);
	mlx->map_height--;
}

void	ft_free(t_mlx_mlx *mlx)
{
	int i;

	printf("Height %d\n", mlx->map_height);
	i = 0;
	while (i < mlx->map_height)
	{
		free(mlx->map_data[i]);
		i++;
	}
	free(mlx->map_data);
}
