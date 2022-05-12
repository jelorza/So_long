/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:24:26 by jelorza-          #+#    #+#             */
/*   Updated: 2022/05/12 13:48:28 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map(char *argv, t_mlx_mlx *mlx)
{
	ft_get_height(argv, mlx);
	ft_get_width(argv, mlx);
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
	close(fd);
	mlx->map_height--;
}

void	ft_get_width(char *argv, t_mlx_mlx *mlx)
{
	int		fd;

	mlx->chars[0] = 0;
	mlx->chars[1] = 0;
	mlx->chars[2] = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("");
		exit(1);
	}
	ft_get_line(fd, mlx);
}

void	ft_get_line(int fd, t_mlx_mlx *mlx)
{
	int		i;
	char	*line;

	i = 1;
	line = get_next_line(fd);
	if (line == 00)
	{
		printf("ERROR: El mapa esta vacio");
		exit(1);
	}
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
				printf("ERROR: El mapa no es rectangulo");
				exit(1);
			}
		}
	}
	mlx->map_width--;
	close(fd);
	ft_check_charact(mlx);
}

void	ft_check_charact(t_mlx_mlx *mlx)
{
	if (mlx->chars[1] < 1 || mlx->chars[2] < 1)
	{
		printf("ERROR: El mapa no contiene ni 'e' ni 'c'");
		exit(1);
	}
	else if (mlx->chars[0] != 1)
	{
		printf("ERROR: Algo pasa con el p");
		exit(1);
	}
}

void	ft_check_line(char *line, int line_counter, t_mlx_mlx *mlx)
{
	int	i;

	i = 0;
	if (line_counter == 1 || line_counter == mlx->map_height)
	{
		while (i < ft_strlen(line) - 1)
		{
			if (line[i] != '1')
			{
				printf("ERROR: El mapa no esta cerrado correctamente");
				exit(1);
			}
			i++;
		}
	}
	else
		ft_check_line_end(line, line_counter, mlx);
}

void	ft_check_line_end(char *line, int line_counter, t_mlx_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < ft_strlen(line) - 1)
	{
		if (line[0] != '1' || line[mlx->map_width - 2] != '1')
		{
			printf("EROR: El mapa no esta cerrado correctamentee");
			exit(1);
		}
		else if (line[i] != '1' && line[i] != '0' && line[i] != 'P'
			&& line[i] != 'E' && line[i] != 'C')
		{
			printf("ERROR: El mapa contiene caracteres incorrectos");
			exit(1);
		}
		ft_check_line_end_end(line, line_counter, i, mlx);
		i++;
	}
}

void	ft_check_line_end_end(char *line, int line_counter,
		int i, t_mlx_mlx *mlx)
{
	if (line[i] == 'P')
	{
		mlx->chars[0]++;
		mlx->p_pos[0] = line_counter - 1;
		mlx->p_pos[1] = i;
	}
	else if (line[i] == 'C')
		mlx->chars[1]++;
	else if (line[i] == 'E')
		mlx->chars[2]++;
}
