/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorza- <jelorza-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:49:16 by jelorza-          #+#    #+#             */
/*   Updated: 2022/05/12 18:52:57 by jelorza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>

typedef struct win{
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*img6;
	int		width;
	int		height;
	int		counter;
}	t_mlx_img;

typedef struct mlx{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			endian;
	int			line_length;
	char		key;
	int			map_width;
	int			map_height;
	int			chars[3];
	char		**map_data;
	int			p_pos[2];
	int			e_pos;
	t_mlx_img	imgs;
}	t_mlx_mlx;

char	*get_next_line(int fd);
int		ft_strlen(char *str);
void	ft_check_map(char *argv, t_mlx_mlx *mlx);
void	ft_get_height(char *argv, t_mlx_mlx *mlx);
void	ft_get_width(char *argv, t_mlx_mlx *mlx);
void	ft_check_line(char *line, int line_counter, t_mlx_mlx *mlx);
void	ft_check_line_end(char *line, int line_counter, t_mlx_mlx *mlx);
void	ft_check_line_end_end(char *line, int line_counter,
			int i, t_mlx_mlx *mlx);
void	ft_get_map(t_mlx_mlx *mlx, char *argv);
void	ft_map_init(char *arg, t_mlx_mlx *mlx);
void	ft_create_map(t_mlx_mlx *mlx);
void	ft_get_line(int fd, t_mlx_mlx *mlx);
void	ft_create_wall_and_floor(t_mlx_mlx *mlx);
void	ft_create_objects_and_exit(t_mlx_mlx *mlx);
void	ft_create_player(t_mlx_mlx *mlx);
void	ft_create_enemy(t_mlx_mlx *mlx);
void	ft_hooks(t_mlx_mlx *mlx);
int		key_hook(int kc, t_mlx_mlx *mlx);
void	ft_get_moves(t_mlx_mlx *mlx);
void	ft_move_up(t_mlx_mlx *mlx, char c);
void	ft_put_exit(t_mlx_mlx *mlx);
void	ft_free(t_mlx_mlx *mlx);
void	ft_move_up(t_mlx_mlx *mlx, char c);
void	ft_move_right(t_mlx_mlx *mlx, char c);
void	ft_move_down(t_mlx_mlx *mlx, char c);
void	ft_move_left(t_mlx_mlx *mlx, char c);
int		ft_exit(t_mlx_mlx *mlx);
void	ft_you_win(t_mlx_mlx *mlx);
void	ft_is_killed(t_mlx_mlx *mlx);
void	ft_change_img(t_mlx_mlx *mlx, char c);
void	ft_change_up_img(t_mlx_mlx *mlx, char charact);
void	ft_save_imgs(t_mlx_mlx *mlx);
void	ft_create_background(t_mlx_mlx *mlx);
void	ft_check_charact(t_mlx_mlx *mlx);

#endif
