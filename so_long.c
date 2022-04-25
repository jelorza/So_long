//#include "get_next_line.h"
#include "so_long.h"

//primero gestiono el mapa. Para ello tengo que recojer las medidas del mapa y controlar los errores (es rectangular, esta bien cerrado, cada uno de los caracteres son correctos y por lo menos existe 1 de cada.
//Para ello empezare a pasar el gnl y contar la altura y la anchura.

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int  main(int argc, char **argv)
{
	t_arg_map map;

	if (argc == 2 && argv[1][ft_strlen(argv[1]) -1] == 'r' && argv[1][ft_strlen(argv[1]) - 2] == 'e' && argv[1][ft_strlen(argv[1]) - 3] == 'b')
	{
		ft_checkmap(argv[1], &map);
	}
	else
		printf("argv error");
}

void	ft_checkmap(char *argv, t_arg_map *map)
{
	ft_get_dimension(argv, map);
//	ft_check_errors(argv);

}

void	ft_get_dimension(char *argv, t_arg_map *map)
{
	int fd;
	int line;
	
	map->height = 0;
	line = 1;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		perror("el archivo no existe");
	while (line)
	{
		line = get_next_line(fd);
		map->height++;
	}

}

