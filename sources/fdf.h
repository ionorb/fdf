/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 00:40:42 by myaccount         #+#    #+#             */
/*   Updated: 2022/10/10 23:51:01 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include "../libs/mlx-linux/mlx.h"
# include "../libs/libft/libft.h"

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define PURPLE 0xA020F0
# define PINK 0xFF00FF
# define YELLOW 0xFFFF00
# define ORANGE 0xFFA500
# define PI 3.141

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
	int		height;
	int		width;
	int		**matrix;
	void	*mlx;
	void	*win;
	void	*img;
	float	zoom;
	float	x_offset;
	float	y_offset;
	float	z_scale;
	float	scaler;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*addr;
	float	ang_x;
	float	ang_y;
	float	ang_z;
	int		is_pressed;
	int		winheight;
	int		winwidth;
	float	maxz;
	float	minz;
	int		centrex;
	int		centrey;
	int		mousex;
	int		mousey;
	int		prev_mousex;
	int		prev_mousey;
}	t_data;

typedef struct s_pt
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_pt;

//general
char	*get_next_line(int fd, int a);
void	read_file(char *filename, t_data *data);
int		ft_hasnl(char	*str);
void	draw(t_data *data);
void	ft_put_pixel(t_pt *from, t_pt *to, t_pt *current, t_data *data);

//init
t_data	*ft_init_data(char **av);
int		ft_close(void *data);
void	ft_freedata(t_data *data);

//keypress
void	ft_offset(int key, t_data *data);
void	ft_angle(int key, t_data *data);
void	ft_scale(int key, t_data *data);
void	ft_zoom(int key, t_data *data);

//3d
void	ft_project(t_pt *pt, t_data *data);
void	make_pt(float x, float y, t_pt *pt, t_data *data);
void	make_isometric(t_data *data);
void	rotate_x(t_pt *pt, t_pt *save, t_data *data);
void	rotate_y(t_pt *pt, t_pt *save, t_data *data);
void	rotate_z(t_pt *pt, t_pt *save, t_data *data);

//utils
float	ft_abs(float n);
int		get_max(float a, float b);
float	maxz(t_data *data);
float	minz(t_data *data);

int		key_press(int key, t_data *data);

//color
float	percentage(int start, int end, int current);
int		get_color(t_pt *from, t_pt *to, t_pt *current);
int		get_default_color(int z, t_data *data);

//grid
int		make_grid(t_pt *from, t_pt *to, t_data *data);
int		make_grid_rev(t_pt *from, t_pt *to, t_data *data);
int		get_inversion(t_data *data);
int		draw_line(t_pt *from, t_pt *to, t_data *data);
#endif
