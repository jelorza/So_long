#include "so_long.h"

void	ft_create_map(t_mlx_mlx *mlx)
{	
	ft_save_imgs(mlx);
	ft_create_background(mlx);
	ft_create_wall_and_floor(mlx);
	ft_create_objects_and_exit(mlx);
	ft_create_player(mlx);
	ft_create_enemy(mlx);
}

void	ft_save_imgs(t_mlx_mlx *mlx)
{
	mlx->imgs.img1 = mlx_xpm_file_to_image(mlx->mlx, "./bob.xpm", &mlx->imgs.width, &mlx->imgs.height);
	mlx->imgs.img2 = mlx_xpm_file_to_image(mlx->mlx, "./burger.xpm", &mlx->imgs.width, &mlx->imgs.height);
	mlx->imgs.img3 = mlx_xpm_file_to_image(mlx->mlx, "./wall.xpm", &mlx->imgs.width, &mlx->imgs.height);
	mlx->imgs.img4 = mlx_xpm_file_to_image(mlx->mlx, "./water.xpm", &mlx->imgs.width, &mlx->imgs.height);
	mlx->imgs.img5 = mlx_xpm_file_to_image(mlx->mlx, "./home.xpm", &mlx->imgs.width, &mlx->imgs.height);
	mlx->imgs.img6 = mlx_xpm_file_to_image(mlx->mlx, "./calamardo.xpm", &mlx->imgs.width, &mlx->imgs.height);
}


void	ft_create_enemy(t_mlx_mlx *mlx)
{
	int y;
	int x;

	y = 0;
	while (y < mlx->map_height)
	{
		x = 0;
		while (x < mlx->map_width)
		{
			if (mlx->map_data[y][x] == 'V')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs.img6, x * 50, y * 50);
			x++;	
		}
		y++;
	}
}

void	ft_create_background(t_mlx_mlx *mlx)
{
	int y;
	int x;

	y = 0;
	while (y < mlx->map_height)
	{
		x = 0;
		while (x < mlx->map_width)
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs.img4, x * 50, y * 50);
			x++;	
		}
		y++;
	}
}

void	ft_create_wall_and_floor(t_mlx_mlx *mlx)
{
	int y;
	int x;

	y = 0;
	while (y < mlx->map_height)
	{
		x = 0;
		while (x < mlx->map_width)
		{
			if (mlx->map_data[y][x] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs.img3, x * 50, y * 50);
			else if (mlx->map_data[y][x] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs.img4, x * 50, y * 50);
			x++;
		}
		y++;
	}
}

void	ft_create_objects_and_exit(t_mlx_mlx *mlx)
{
	int y;
	int x;

	y = 0;
	while (y < mlx->map_height)
	{
		x = 0;
		while (x < mlx->map_width)
		{
			if (mlx->map_data[y][x] == 'C' )
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs.img2, x * 50, y * 50);
			else if (mlx->map_data[y][x] == 'E' )
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs.img5, x * 50, y * 50);
			}
			x++;	
		}
		y++;
	}
}

void	ft_create_player(t_mlx_mlx *mlx)
{
	int y;
	int x;

	y = 0;
	while (y < mlx->map_height)
	{
		x = 0;
		while (x < mlx->map_width)
		{
			if (mlx->map_data[y][x] == 'P' )
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs.img1, x * 50, y * 50);
			x++;	
		}
		y++;
	}
}
