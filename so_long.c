#include "so_long.h"

//Ya tengo el control de errores, ahora empiezo con la minilib. Habrir ventana y empezar con las imagenes.

int  main(int argc, char **argv)
{
	t_arg_map map;

	if (argc == 2 && argv[1][ft_strlen(argv[1]) -1] == 'r' && argv[1][ft_strlen(argv[1]) - 2] == 'e' && argv[1][ft_strlen(argv[1]) - 3] == 'b')
	{
		ft_checkmap(argv[1], &map);
		ft_map_init(argv[1], &map);
		printf("Height %d\n", map.height);
		printf("Width %d\n", map.width);
	}
	else
		printf("argv error");
}

void	ft_map_init(char *str, 

void	ft_checkmap(char *argv, t_arg_map *map)
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
	map->width = ft_strlen(line);
	while (line)
	{
		ft_check_line(line, i++, map);
		line = get_next_line(fd);
		if (line)
		{
			if (ft_strlen(line) != map->width)
			{
				perror("El mapa no es rectangulo");
				exit(1);
			}
		}
	}
	map->width--;
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
	if(line_counter == 1 || line_counter == map->height)
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
			if (line[0] != '1' || line[map->width - 2] != '1')
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
