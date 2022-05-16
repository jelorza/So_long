/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:34:55 by jelorza-          #+#    #+#             */
/*   Updated: 2022/05/16 17:20:30 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hooks(t_mlx_mlx *mlx)
{
	mlx_hook (mlx->win, 2, 1L << 0, key_hook, mlx);
	mlx_hook(mlx->win, 17, 1L << 5, ft_exit, mlx);
}

int	key_hook(int kc, t_mlx_mlx *mlx)
{
	if (kc == 13)
		mlx->key = 'w';
	else if (kc == 2)
		mlx->key = 'd';
	else if (kc == 0)
		mlx->key = 'a';
	else if (kc == 1)
		mlx->key = 's';
	else if (kc == 53)
		mlx->key = 'x';
	if (kc == 13 || kc == 2 || kc == 0 || kc == 1 || kc == 53)
	{
		ft_get_moves(mlx);
		mlx->imgs.counter++;
		printf("mov %d\n", mlx->imgs.counter);
	}
	return (0);
}

void	ft_get_moves(t_mlx_mlx *mlx)
{
	if (mlx->key == 'w')
		ft_move_up(mlx, 'w');
	else if (mlx->key == 'd')
		ft_move_right(mlx, 'd');
	else if (mlx->key == 'a')
		ft_move_left(mlx, 'a');
	else if (mlx->key == 's')
		ft_move_down(mlx, 's');
	else if (mlx->key == 'x')
		ft_exit(mlx);
	if (mlx->chars[1] == 0)
		ft_put_exit(mlx);
}	

void	ft_change_pos(t_mlx_mlx *mlx, char c)
{
	if (c == 'w')
		mlx->p_pos[0]--;
	else if (c == 'd')
		mlx->p_pos[1]++;
	else if (c == 'a')
		mlx->p_pos[1]--;
	else if (c == 's')
		mlx->p_pos[0]++;
}

void	ft_change_img(t_mlx_mlx *mlx, char c)
{
	mlx->map_data[mlx->p_pos[0]][mlx->p_pos[1]] = '0';
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs.img4,
		mlx->p_pos[1] * 50, mlx->p_pos[0] * 50);
	ft_change_pos(mlx, c);
}
