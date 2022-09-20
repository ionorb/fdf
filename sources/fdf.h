/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 00:40:42 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/20 19:56:45 by yridgway         ###   ########.fr       */
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


/*int	make_color(float percent, int start, int end)
{
	return ((int)((1 - percent) * start + percent * end));
}
	r = make_color(percent, (from->color >> 16) & 0xFF,
		(to->color >> 16) & 0xFF);
	g = make_color(percent, (from->color >> 8) & 0xFF,
		(to->color >> 8) & 0xFF);
	b = make_color(percent, (from->color) & 0xFF,
		(to->color) & 0xFF);*/

typedef struct s_data
{
	int	height;
	int	width;
	int	**matrix;
	void	*mlx;
	void	*win;
	void	*img;
	float	zoom;
	float	x_offset;
	float	y_offset;
	float	z_scale;
	int	bits_per_pixel;
	int	size_line;
	int	endian;
	char	*addr;
	float	ang_x;
	float	ang_y;
	float	ang_z;
	int	is_pressed;
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

//init
t_data	*ft_init_data(char **av);
int	ft_close(void *data);

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
float	maxz(t_data *data);
float	minz(t_data *data);

int	key_press(int key, t_data *data);

//color
float	percentage(int start, int end, int current);
int	get_color(t_pt *from, t_pt *to, t_pt *current);
int	get_default_color(int z, t_data *data);
#endif
