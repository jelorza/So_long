#ifndef SO_LONG_H
# define SO_LONG_H

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<mlx.h>

typedef struct win{

	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	int		width;
	int		height;
	int		prueba;

}	t_mlx_img;

typedef struct map{
	
	int		map_width;
	int 	map_height;
	int 	chars[3];
	char	**map_data;
	int		p_pos[2];
	
}	t_arg_map;

typedef struct mlx{

	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		endian;
	int		line_length;
	char	key;
	t_mlx_img imgs;

}	t_mlx_mlx;


char	*get_next_line(int fd);
int		ft_strlen(char *str);
void	ft_check_map(char *argv, t_arg_map *map);
void	ft_get_height(char *argv, t_arg_map *map);
void	ft_get_width(char *argv, t_arg_map *map);
void	ft_check_line(char *line, int line_counter, t_arg_map *map);
void	ft_get_map(t_arg_map *map, char *argv);
void	ft_map_init(char *arg, t_arg_map *map, t_mlx_mlx *mlx);
void	ft_create_map(t_arg_map *map, t_mlx_mlx *mlx);
void	ft_create_wall_and_floor(t_arg_map *map, t_mlx_mlx *mlx);
void	ft_create_objects_and_exit(t_arg_map *map, t_mlx_mlx *mlx);
void	ft_create_player(t_arg_map *map, t_mlx_mlx *mlx);
void	ft_hooks(t_mlx_mlx *mlx, t_arg_map *map);
void	ft_get_moves(t_arg_map *map, t_mlx_mlx *mlx);
void	ft_move_up(t_arg_map *map, t_mlx_mlx *mlx);
void	ft_free(t_arg_map *map);


#endif
