/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:22:35 by jelorza-          #+#    #+#             */
/*   Updated: 2022/05/16 17:33:05 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_map(t_mlx_mlx *mlx)
{	
	ft_save_imgs(mlx);
	ft_create_background(mlx);
	ft_create_wall_and_floor(mlx);
	ft_create_objects_and_exit(mlx);
	ft_create_player(mlx);
}

void	ft_save_imgs(t_mlx_mlx *mlx)
{
	mlx->imgs.img1 = mlx_xpm_file_to_image(mlx->mlx,
			"imgs/bob.xpm", &mlx->imgs.width, &mlx->imgs.height);
	mlx->imgs.img2 = mlx_xpm_file_to_image(mlx->mlx,
			"imgs/burger.xpm", &mlx->imgs.width, &mlx->imgs.height);
	mlx->imgs.img3 = mlx_xpm_file_to_image(mlx->mlx,
			"imgs/wall.xpm", &mlx->imgs.width, &mlx->imgs.height);
	mlx->imgs.img4 = mlx_xpm_file_to_image(mlx->mlx,
			"imgs/water.xpm", &mlx->imgs.width, &mlx->imgs.height);
	mlx->imgs.img5 = mlx_xpm_file_to_image(mlx->mlx,
			"imgs/home.xpm", &mlx->imgs.width, &mlx->imgs.height);
}
