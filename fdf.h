/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 00:40:42 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/13 01:06:55 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "minilibx/mlx.h"

typedef struct s_data
{
	int		height;
	int		width;
	int		**matrix;
	void	*mlx;
	void	*win;
	int		zoom;
	int		x_offset;
	int		y_offset;
	int		z_scale;
	int		x_angle;
	int		y_angle;
	int		run;
}	t_data;

char	*get_next_line(int fd);
void	read_file(char *filename, t_data *data);
char	**ft_split(char *s, char *str);
int		ft_atoi(const char *nptr);
int		ft_hasnl(char	*str);
char	*ft_strjoin(char *s1, char *s2);
//void	draw_line(int x0, int y0, int x1, int y1, t_data *data);
void	draw_line(float *pts, t_data *data);
void	draw(t_data *data);
void	ft_putnbr_fd(int n, int fd);
#endif
