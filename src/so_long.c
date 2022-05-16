/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:03:34 by jelorza-          #+#    #+#             */
/*   Updated: 2022/05/16 16:53:34 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx_mlx	mlx;

	mlx.imgs.counter = 0;
	if (argc == 2 && argv[1][ft_strlen(argv[1]) - 1] == 'r' &&
			argv[1][ft_strlen(argv[1]) - 2] == 'e' &&
				argv[1][ft_strlen(argv[1]) - 3] == 'b')
	{
		ft_check_map(argv[1], &mlx);
		ft_get_map(&mlx, argv[1]);
		ft_map_init(argv[1], &mlx);
		ft_create_map(&mlx);
		ft_hooks(&mlx);
		mlx_loop(mlx.mlx);
	}
	else
		printf("argv error");
	return (0);
}

void	ft_map_init(char *arg, t_mlx_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->map_width * 50,
			mlx->map_height * 50, "So Long");
	mlx->img = mlx_new_image(mlx->mlx, mlx->map_width * 50,
			mlx->map_height * 50);
}

void	ft_get_map(t_mlx_mlx *mlx, char *argv)
{
	int	i;
	int	fd;

	i = 0;
	mlx->map_data = (char **)malloc (sizeof(char **) * (mlx->map_height + 1));
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("");
		exit(1);
	}
	if (!mlx->map_data)
		return ;
	while (i < mlx->map_height)
	{
		mlx->map_data[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	mlx->map_data[i] = 00;
}

void	ft_free(t_mlx_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->map_height)
	{
		free(mlx->map_data[i]);
		i++;
	}
	free(mlx->map_data);
}
