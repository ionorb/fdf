/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 02:22:45 by yoel              #+#    #+#             */
/*   Updated: 2022/09/16 17:13:56 by yoel             ###   ########.fr       */
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

int	get_max(float a, float b)
{
	int	max;

	if (ft_abs(a) >= ft_abs(b))
		max = (int)ft_abs(a);
	else
		max = (int)ft_abs(b);
	return (max);
}

int	get_color(t_pt *from, t_pt *to, t_data *data)
{
	int	color;

	color = 0xffffff;
	if (from->z == data->tallest || to->z == data->tallest)
		color = 0x800000;
	return (color);
}

void	ft_put_pixel(t_pt *from, t_pt *to, t_data *data)
{
	int	i;
	int	color;

	if (from->x >= 0 && from->x < 1800 * (data->bits_per_pixel / 8) && from->y >= 0 && from->y <= 1200)
	{
		i = (((int)(from->x) * (int)(data->bits_per_pixel / 8)) + ((int)(from->y) * (int)(data->size_line)));
		color = get_color(from, to, data);
		data->addr[i] = color;
		data->addr[i + 1] = color >> 8;
		data->addr[i + 2] = color >> 16;
	}
}

void	draw_line(t_pt *from, t_pt *to, t_data *data)
{
	float	xstep;
	float	ystep;
	int		max;

	xstep = to->x - from->x;
	ystep = to->y - from->y;
	max = get_max(xstep, ystep);
	xstep /= max;
	ystep /= max;
	while ((int)(from->x - to->x) || (int)(from->y - to->y))
	{
		ft_put_pixel(from, to, data);
		from->x += xstep;
		from->y += ystep;
	}
}

void	make_pt(float x, float y, t_pt *pt, t_data *data)
{
	pt->z = data->matrix[(int)y][(int)x];
	pt->x = x;
	pt->y = y;
	pt->z -= ((pt->z / 10) * data->z_scale) / 5;
	ft_project(pt, data);
}

void	draw(t_data *data)
{
	int		y;
	int		x;
	t_pt	*from;
	t_pt	*to;

	from = malloc(sizeof (t_pt));
	to = malloc(sizeof (t_pt));
	ft_bzero(data->addr, 1200 * 1800 * (data->bits_per_pixel / 8));
	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			if (x < data->width - 1)
			{
				make_pt(x, y, from, data);
				make_pt(x + 1, y, to, data);
				draw_line(from, to, data);
			}
			if (y < data->height - 1)
			{
				make_pt(x, y, from, data);
				make_pt(x, y + 1, to, data);
				draw_line(from, to, data);
			}
		}
	}
	free(from);
	free(to);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
