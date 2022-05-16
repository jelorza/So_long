/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:11:08 by jelorza-          #+#    #+#             */
/*   Updated: 2022/05/16 18:11:13 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_if_empty(char *line)
{
	if (line == 00)
	{
		printf("ERROR: El mapa esta vacio");
		exit(1);
	}
}

void	ft_check_charact(t_mlx_mlx *mlx)
{
	if (mlx->chars[1] < 1)
	{
		printf("ERROR: El mapa no contiene objetos");
		exit(1);
	}
	else if (mlx->chars[2] < 1)
	{
		printf("ERROR: El mapa no contiene salida");
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
			&& line[i] != 'E' && line[i] != 'C' && line[i] != 'V')
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
