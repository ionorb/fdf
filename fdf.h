/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 00:40:42 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/12 02:47:40 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx/mlx.h"

typedef struct s_data
{
	int		height;
	int		width;
	int		**matrix;
	void	*mlx;
	void	*win;
}	t_data;

char	*get_next_line(int fd);
void	read_file(char *filename, t_data *data);
char	**ft_split(char *s, char *str);
int		ft_atoi(const char *nptr);
int		ft_hasnl(char	*str);
char	*ft_strjoin(char *s1, char *s2);
//void	draw_line(int x0, int y0, int x1, int y1, t_data *data);
void	draw_line(float x0, float y0, float x1, float y1, t_data *data);
int		mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
#endif
