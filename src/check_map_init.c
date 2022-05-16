/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:24:26 by jelorza-          #+#    #+#             */
/*   Updated: 2022/05/16 18:10:34 by jelorza-         ###   ########.fr       */
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

	line = get_next_line(fd);
	ft_check_if_empty(line);
	mlx->map_width = ft_strlen(line);
	while (line)
	{
		ft_check_line(line, ++i, mlx);
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
