/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 02:22:45 by yoel              #+#    #+#             */
/*   Updated: 2022/09/12 23:39:38 by yoel             ###   ########.fr       */
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

void	draw_line(float *pts, t_data *data)
{
	float	xstep;
	float	ystep;
	float	*ptz;
	int		max;

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
	}
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

	y = data->y_offset;
	while (y < data->height + data->y_offset)
	{
		x = data->x_offset;
		while (x < data->width - 1 + data->x_offset)
		{
			draw_line(make_pts(x, y, x + 1, y), data);
			if (y != data->height - 1 + data->y_offset)
				draw_line(make_pts(x, y, x, y + 1), data);
			x += 1;
		}
		if (y < data->height - 1 + data->y_offset)
			draw_line(make_pts(x, y, x, y + 1), data);
		y += 1;
	}
}
