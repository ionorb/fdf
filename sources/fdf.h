/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 00:40:42 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/15 14:11:49 by yoel             ###   ########.fr       */
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
	int		zoom;
	int		x_offset;
	int		y_offset;
	int		z_scale;
	int		x_angle;
	int		y_angle;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*addr;
	int		run;
}	t_data;

typedef	struct s_pt
{
	float	x;
	float	y;
	float	z;
}	t_pt;

char	*get_next_line(int fd);
void	read_file(char *filename, t_data *data);
int		ft_hasnl(char	*str);
//void	draw_line(int x0, int y0, int x1, int y1, t_data *data);
void	draw_line(t_pt *from, t_pt *to, t_data *data);
void	draw(t_data *data);
#endif
