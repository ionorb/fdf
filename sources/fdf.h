/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 00:40:42 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/20 16:15:35 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../libs/mlx-linux/mlx.h"
# include "../libs/libft/libft.h"

typedef struct s_data
{
	int		height;
	int		width;
	int		**matrix;
	void	*mlx;
	void	*win;
	void	*img;
	float		zoom;
	int		x_offset;
	int		y_offset;
	int		z_scale;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*addr;
	int		tallest;
	float	ang_x;
	float	ang_y;
	float	ang_z;
	int		is_pressed;
	int	winheight;
	int	winwidth;
}	t_data;

typedef	struct s_pt
{
	float	x;
	float	y;
	float	z;
	int	color;
}	t_pt;

char	*get_next_line(int fd);
void	read_file(char *filename, t_data *data);
int	ft_hasnl(char	*str);
//void	draw_line(t_pt *from, t_pt *to, t_data *data);
void	draw(t_data *data);
t_data	*ft_init_data(char **av);

//keypress
void    ft_offset(int key, t_data *data);
void    ft_angle(int key, t_data *data);
void    ft_scale(int key, t_data *data);
void    ft_zoom(int key, t_data *data);

//3d
void	ft_project(t_pt *pt, t_data *data);
void	make_pt(float x, float y, t_pt *pt, t_data *data);
void	make_isometric(t_data *data);

//utils
float	ft_abs(int n);
int	get_max(float a, float b);
#endif
