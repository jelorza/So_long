/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_movements_put_imgs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:11:01 by jelorza-          #+#    #+#             */
/*   Updated: 2022/05/16 17:19:47 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_mlx_mlx *mlx, char c)
{
	char	charact;

	charact = mlx->map_data[(mlx->p_pos[0]) - 1][mlx->p_pos[1]];
	if (charact != '1')
	{
		if (charact == 'V')
			ft_is_killed(mlx);
		else if (charact == 'E' && mlx->chars[1] == 0)
			ft_you_win(mlx);
		else if (charact != 'E')
		{
			ft_change_img(mlx, c);
			ft_change_up_img(mlx, charact);
		}
	}
}

void	ft_move_right(t_mlx_mlx *mlx, char c)
{
	char	charact;

	charact = mlx->map_data[(mlx->p_pos[0])][mlx->p_pos[1] + 1];
	if (charact != '1')
	{
		if (charact == 'V')
			ft_is_killed(mlx);
		else if (charact == 'E' && mlx->chars[1] == 0)
			ft_you_win(mlx);
		else if (charact != 'E')
		{
			ft_change_img(mlx, c);
			ft_change_up_img(mlx, charact);
		}
	}
}

void	ft_move_left(t_mlx_mlx *mlx, char c)
{
	char	charact;

	charact = mlx->map_data[(mlx->p_pos[0])][mlx->p_pos[1] - 1];
	if (charact != '1')
	{
		if (charact == 'V')
			ft_is_killed(mlx);
		else if (charact == 'E' && mlx->chars[1] == 0)
			ft_you_win(mlx);
		if (charact != 'E')
		{
			ft_change_img(mlx, c);
			ft_change_up_img(mlx, charact);
		}
	}
}

void	ft_move_down(t_mlx_mlx *mlx, char c)
{
	char	charact;

	charact = mlx->map_data[(mlx->p_pos[0]) + 1][mlx->p_pos[1]];
	if (charact != '1')
	{
		if (charact == 'V')
			ft_is_killed(mlx);
		else if (charact == 'E' && mlx->chars[1] == 0)
			ft_you_win(mlx);
		else if (charact != 'E')
		{
			ft_change_img(mlx, c);
			ft_change_up_img(mlx, charact);
		}
	}
}

void	ft_change_up_img(t_mlx_mlx *mlx, char c)
{
	if (mlx->map_data[(mlx->p_pos[0])][mlx->p_pos[1]] == 'C')
		mlx->chars[1]--;
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->imgs.img4, mlx->p_pos[1] * 50, mlx->p_pos[0] * 50);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs.img1,
		mlx->p_pos[1] * 50, mlx->p_pos[0] * 50);
}
