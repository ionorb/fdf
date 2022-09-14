/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 02:22:45 by yoel              #+#    #+#             */
/*   Updated: 2022/09/14 02:33:35 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_abs(int n)
{
	long	num;

	num = (long)n;
	if (num < 0)
		return (num *= -1);
	return (num);
}

float	*arr_cpy(float *arr, int size, int zoom)
{
	int		i;
	float	*cpy;

	cpy = malloc(size * sizeof (float));
	i = 0;
	while (i < size)
	{
		cpy[i] = arr[i] * zoom;
		i++;
	}
	return (cpy);
}

void	make3d(float *x, float *y, float z, t_data *data)
{
	float	scale;
	float	x_angle;
	float	y_angle;

	x_angle = data->x_angle;
	y_angle = data->y_angle;
	scale = data->z_scale;
	scale /= 10;
	x_angle /= 10;
	y_angle /= 10;
	*x = (*x - *y) * cos(x_angle);
	*y = (*x + *y) * sin(y_angle) - (z * scale);
}

void	draw_line(float *pts, t_data *data)
{
	float	xstep;
	float	ystep;
	float	z0;
	float	z1;
	float	*ptz;
	int		max;
	long long	i;

	z0 = data->matrix[(int)(pts[1] - data->y_offset)][(int)(pts[0] - data->x_offset)];
	z1 = data->matrix[(int)(pts[3] - data->y_offset)][(int)(pts[2] - data->x_offset)];
	make3d(&pts[0], &pts[1], z0, data);
	make3d(&pts[2], &pts[3], z1, data);
	ptz = arr_cpy(pts, 4, data->zoom);
	xstep = ptz[2] - ptz[0];
	ystep = ptz[3] - ptz[1];
	if (ft_abs(xstep) >= ft_abs(ystep))
		max = (int)ft_abs(xstep);
	else
		max = (int)ft_abs(ystep);
	xstep /= max;
	ystep /= max;
	while ((int)(ptz[0] - ptz[2]) || (int)(ptz[1] - ptz[3]))
	{
		i = ((ptz[0] * (data->bits_per_pixel / 8)) + (ptz[1] * data->size_line));
	//	mlx_pixel_put(data->mlx, data->win, ptz[0], ptz[1], 255);
		ft_putnbr_fd(i, 1);
		printf("ptz[0]:%f, ptz[1]:%f\n", ptz[0], ptz[1]);
		if (ptz[0] >= 0 && ptz[0] < 800 * (data->bits_per_pixel / 8) && ptz[1] >= 0 && ptz[1] <= 800 )
		{
			write(1, "woo\n", 4);
			data->addr[i] = mlx_get_color_value(data->mlx, 255);
			data->addr[i + 1] = mlx_get_color_value(data->mlx, 255);
			data->addr[i + 2] = mlx_get_color_value(data->mlx, 255) >> 8;
			data->addr[i + 3] = mlx_get_color_value(data->mlx, 255) >> 16;
		}
		ptz[0] += xstep;
		ptz[1] += ystep;
	}
	write(1, "boo\n", 4);
	free(ptz);
	free(pts);
}

float	*make_pts(float x0, float y0, float x1, float y1)
{
	float	*arr;

	arr = malloc(4 * sizeof (float));
	arr[0] = x0;
	arr[1] = y0;
	arr[2] = x1;
	arr[3] = y1;
	return (arr);
}

void	draw(t_data *data)
{
	int		y;
	int		x;

	ft_bzero(data->addr, 800 * 800 * (data->bits_per_pixel / 8));
	y = data->y_offset;
	while (y < data->height + data->y_offset)
	{
		x = data->x_offset;
		while (x < data->width + data->x_offset)
		{
			if (x < data->width - 1 + data->x_offset)
				draw_line(make_pts(x, y, x + 1, y), data);
			if (y < data->height - 1 + data->y_offset)
				draw_line(make_pts(x, y, x, y + 1), data);
			x += 1;
		}
		y += 1;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
