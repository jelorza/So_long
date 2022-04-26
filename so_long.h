#ifndef SO_LONG_H
# define SO_LONG_H

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

typedef struct map{
	
	int	width;
	int height;
	
}	t_arg_map;

int		ft_strlen(char *str);
void	ft_checkmap(char *argv, t_arg_map *map);
void	ft_get_height(char *argv, t_arg_map *map);
void	ft_get_width(char *argv, t_arg_map *map);
void	ft_check_line(char *line, int line_counter);
char	*get_next_line(int fd);


#endif
