#ifndef SO_LONG_H
# define SO_LONG_H

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include "get_next_line.h"

typedef struct map{
	
	int	width;
	int height;
	
}	t_arg_map;

int		ft_strlen(char *str);
void	ft_checkmap(char *argv, t_arg_map *map);
void	ft_get_dimension(char *argv, t_arg_map *map);


#endif
