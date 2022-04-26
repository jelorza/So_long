/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:57:09 by jelorza-          #+#    #+#             */
/*   Updated: 2022/04/26 11:52:52 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<fcntl.h>
# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>

# define BUFFER_SIZE 1
//gcc -g3 -fsanitize=address -Wall -Wextra -Werror get_next_line.c 
//main_getNextLine.c get_next_line_utils.c

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_join(char *rest_buff, char *buff, int bit_counter);
int		ft_find_char(char *rest_buff, char c);
char	*ft_line_out(char *rest_buff);
char	*ft_new_rest(char *rest_buff);
int		ft_rest_buff_to_null(char *rest_buff);
char	*ft_str_joined(char *rest_buff, char *buff);

#endif
