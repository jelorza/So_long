#ifndef SO_LONG_H
# define SO_LONG_H

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<mlx.h>

typedef struct map{
	
	int		width;
	int 	height;
	int 	chars[3];
	char	**map_data;
	
}	t_arg_map;

typedef struct mlx{

	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		endian;
	int		line_length;

}	t_mlx_mlx;

char	*get_next_line(int fd);
int		ft_strlen(char *str);
void	ft_check_map(char *argv, t_arg_map *map);
void	ft_get_height(char *argv, t_arg_map *map);
void	ft_get_width(char *argv, t_arg_map *map);
void	ft_check_line(char *line, int line_counter, t_arg_map *map);
void	ft_get_map(t_arg_map *map, char *argv);
void	ft_map_init(char *arg, t_arg_map *map, t_mlx_mlx *mlx);
void	ft_create_map(char *arg, t_arg_map *map, t_mlx_mlx *mlx);
void	ft_free(t_arg_map *map);


#endif
