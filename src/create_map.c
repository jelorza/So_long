/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_finish.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:33:31 by jelorza-          #+#    #+#             */
/*   Updated: 2022/05/16 17:34:05 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_background(t_mlx_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	while (y < mlx->map_height)
	{
		x = 0;
		while (x < mlx->map_width)
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win,
				mlx->imgs.img4, x * 50, y * 50);
			x++;
		}
		y++;
	}
}

void	ft_create_wall_and_floor(t_mlx_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	while (y < mlx->map_height)
	{
		x = 0;
		while (x < mlx->map_width)
		{
			if (mlx->map_data[y][x] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					mlx->imgs.img3, x * 50, y * 50);
			else if (mlx->map_data[y][x] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					mlx->imgs.img4, x * 50, y * 50);
			x++;
		}
		y++;
	}
}

void	ft_create_objects_and_exit(t_mlx_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	while (y < mlx->map_height)
	{
		x = 0;
		while (x < mlx->map_width)
		{
			if (mlx->map_data[y][x] == 'C' )
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					mlx->imgs.img2, x * 50, y * 50);
			else if (mlx->map_data[y][x] == 'E' )
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					mlx->imgs.img5, x * 50, y * 50);
			}
			x++;
		}
		y++;
	}
}

void	ft_create_player(t_mlx_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	while (y < mlx->map_height)
	{
		x = 0;
		while (x < mlx->map_width)
		{
			if (mlx->map_data[y][x] == 'P' )
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					mlx->imgs.img1, x * 50, y * 50);
			x++;
		}
		y++;
	}
}
