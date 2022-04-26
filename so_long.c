#include "so_long.h"

//primero gestiono el mapa. Para ello tengo que recojer las medidas del mapa y controlar los errores (es rectangular, esta bien cerrado, cada uno de los caracteres son correctos y por lo menos existe 1 de cada.
//Para ello empezare a pasar el gnl y contar la altura y la anchura.

int  main(int argc, char **argv)
{
	t_arg_map map;

	if (argc == 2 && argv[1][ft_strlen(argv[1]) -1] == 'r' && argv[1][ft_strlen(argv[1]) - 2] == 'e' && argv[1][ft_strlen(argv[1]) - 3] == 'b')
	{
		ft_checkmap(argv[1], &map);
		printf("Height %d\n", map.height);
		printf("Width %d\n", map.width);
	}
	else
		printf("argv error");
}

void	ft_checkmap(char *argv, t_arg_map *map)
{
	ft_get_height(argv, map);
	ft_get_width(argv, map);
//	ft_check_errors(argv);
}

void	ft_get_width(char *argv, t_arg_map *map)
{
	int		fd;
	char	*line;
	int		i;;

	i = 1;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("");
		exit(1);
	}
	line = get_next_line(fd);
	map->width = ft_strlen(line);
	while (line)
	{
		ft_check_line(line, i++);
		line = get_next_line(fd);
		if (line)
		{
	//		printf("%d\n", ft_strlen(line));
			if (ft_strlen(line) != map->width)
			{
				perror("El mapa no es rectangulo");
				exit(1);
			}
		}
	//	printf("%s\n",line);
	}
	map->width--;
	close(fd);
}

void	ft_check_line(char *line, int line_counter)
{
	int i;
	
	printf("%d\n", line_counter);
	i = 0;
	if(line_counter == 1)
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
		printf("esta bien");

}

void	ft_get_height(char *argv, t_arg_map *map)
{
	int		fd;
	char	*line;
	
	map->height = 0;
	line = "1";
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("");
		exit(1);
	}
	while (line)
	{
		line = get_next_line(fd);
		map->height++;
	}
	close(fd);
	map->height--;
}
