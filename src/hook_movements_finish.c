/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_movements_finish.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:09:39 by jelorza-          #+#    #+#             */
/*   Updated: 2022/05/16 17:09:50 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_mlx_mlx *mlx)
{
	printf("YOU EXIT THE GAME\n");
	mlx_destroy_window(mlx->mlx, mlx->win);
	ft_free(mlx);
	exit (0);
	return (0);
}

void	ft_you_win(t_mlx_mlx *mlx)
{
	printf("YOU WON\n");
	mlx_destroy_window(mlx->mlx, mlx->win);
	ft_free(mlx);
	exit (0);
}

void	ft_put_exit(t_mlx_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	while (y < mlx->map_height)
	{
		x = 0;
		while (x < mlx->map_width)
		{
			if (mlx->map_data[y][x] == 'E')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs.img5,
					x * 50, y * 50);
			}
			x++;
		}
		y++;
	}
}
