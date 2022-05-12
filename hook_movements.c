/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:34:55 by jelorza-          #+#    #+#             */
/*   Updated: 2022/05/12 19:28:13 by jelorza-         ###   ########.fr       */
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

void	ft_is_killed(t_mlx_mlx *mlx)
{
	printf("YOU HAVE BEEN KILLED\n");
	mlx_destroy_window(mlx->mlx, mlx->win);
	ft_free(mlx);
//	system("leaks so_long");
	exit (0);
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

int	ft_exit(t_mlx_mlx *mlx)
{
	printf("YOU EXIT THE GAME\n");
	mlx_destroy_window(mlx->mlx, mlx->win);
	ft_free(mlx);
//	system("leaks so_long");
	exit (0);
	return (0);
}

void	ft_you_win(t_mlx_mlx *mlx)
{
	printf("YOU WON\n");
	mlx_destroy_window(mlx->mlx, mlx->win);
	system("leaks so_long");
	ft_free(mlx);
	exit (0);
}

void	ft_put_exit(t_mlx_mlx *mlx)
{
	int y;
	int x;

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
