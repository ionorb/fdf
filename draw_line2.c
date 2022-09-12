/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 02:22:45 by yoel              #+#    #+#             */
/*   Updated: 2022/09/12 23:18:58 by yoel             ###   ########.fr       */
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

/*void	plotlow(float *pts, t_data *data)
{
	float	x;
	float	y;
	float	grad;

	y = pts[1];
	x = pts[0];
	if (pts[3] - pts[1] == 0)
		grad = 1;
	else
		grad = ft_abs(pts[2] - pts[0]) / ft_abs(pts[3] - pts[1]);
	while (y <= pts[3])
	{
		mlx_pixel_put(data->mlx, data->win, x, y, 0xffffff);
		x += grad;
		y += 1;
	}
	printf("x:%f y:%f\n", x, y);
}

void	plothigh(float *pts, t_data *data)
{
	float	x;
	float	y;
	float	grad;

	y = pts[1];
	x = pts[0];
	if (pts[3] - pts[1] == 0)
		grad = 1;
	else
		grad = ft_abs(pts[2] - pts[0]) / ft_abs(pts[3] - pts[1]);
	while (y <= pts[3])
	{
		mlx_pixel_put(data->mlx, data->win, x, y, 0xffffff);
		x -= grad;
		y += 1;
	}
	printf("x:%f y:%f\n", x, y);
}

void	draw_line(float *pts, t_data *data)
{
	float	*pts1;
	int		i;

	i = -1;
	while (++i < 4)
		pts[i] *= 1;
	pts1 = malloc(4 * sizeof (float));
	pts1[0] = pts[1];
	pts1[1] = pts[0];
	pts1[2] = pts[3];
	pts1[3] = pts[2];
	if (pts[2] >= pts[0] && pts[3] >= pts[1])
		plotlow(pts, data);
	else if (pts[2] <= pts[0] && pts[3] >= pts[1])
		plothigh(pts, data);
	else if (pts[2] >= pts[0] && pts[3] <= pts[1])
		plothigh(pts1, data);
	else if (pts[2] <= pts[0] && pts[3] <= pts[1])
		plotlow(pts1, data);
}*/

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

void	draw_line(float *pts, t_data *data)
{
	float	xstep;
	float	ystep;
	float	*ptz;
	int		max;
	
/*	max = -1;
	while (++max < 4)
	{
		printf("before[%d]:%f ", max, pts[max]);
		pts[max] *= 6;
		printf("after[%d]:%f\n", max, pts[max]);
	}*/
	max = -1;
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
		mlx_pixel_put(data->mlx, data->win, ptz[0], ptz[1], 0xffffff);
		ptz[0] += xstep;
		ptz[1] += ystep;
	//	printf("x0:[%f], y0:[%f]\n", ptz[0], ptz[1]);
	}
//	write(1, "wow\n", 4);
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

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width - 1)
		{
			draw_line(make_pts(x, y, x + 1, y), data);
			if (y != data->height - 1)
				draw_line(make_pts(x, y, x, y + 1), data);
			x += 1;
		}
		if (y < data->height - 1)
			draw_line(make_pts(x, y, x, y + 1), data);
		y += 1;
	}
}
