/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 02:22:45 by yoel              #+#    #+#             */
/*   Updated: 2022/09/15 21:20:14 by yoel             ###   ########.fr       */
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

void	make_isometric(t_pt *pt, t_data *data)
{
	float	scale;
	float	previous_x;
	float	previous_y;

	scale = data->z_scale;
	scale /= 10;
	previous_x = pt->x;
	previous_y = pt->y;
	pt->x = (previous_x - previous_y) * cos(0.523599);
	pt->y = -pt->z * scale + (previous_x + previous_y) * sin(0.523599);
}

void	ft_project(t_pt *pt, t_data *data)
{
	pt->x += data->x_offset;
	pt->y += data->y_offset;
	make_isometric(pt, data);
	pt->x *= data->zoom;
	pt->y *= data->zoom;
}

int		get_max(float a, float b)
{
	int	max;

	if (ft_abs(a) >= ft_abs(b))
		max = (int)ft_abs(a);
	else
		max = (int)ft_abs(b);
	return (max);
}

void	draw_line(t_pt *from, t_pt *to, t_data *data)
{
	float	xstep;
	float	ystep;
	int		i;
	int		max;
	int		color;

	xstep = to->x - from->x;
	ystep = to->y - from->y;
	max = get_max(xstep, ystep);
	xstep /= max;
	ystep /= max;
	while ((int)(from->x - to->x) || (int)(from->y - to->y))
	{
		i = (((int)(from->x) * (int)(data->bits_per_pixel / 8)) + ((int)(from->y) * (int)(data->size_line)));
		if (from->x >= 0 && from->x < 800 * (data->bits_per_pixel / 8) && from->y >= 0 && from->y <= 800 )
		{
	//		mlx_pixel_put(data->mlx, data->win, from->x, from->y, 255);
			color = 0x1e8a76;
			data->addr[i] = color;
			data->addr[i + 1] = color >> 8;
			data->addr[i + 2] = color >> 16;
		}
		from->x += xstep;
		from->y += ystep;
	}
}

void	make_pt(float x, float y, t_pt *pt, t_data *data)
{
	pt->z = data->matrix[(int)y][(int)x];
	pt->x = x;
	pt->y = y;
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
	ft_bzero(data->addr, 800 * 800 * (data->bits_per_pixel / 8));
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
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
			x += 1;
		}
		y += 1;
	}
	free(from);
	free(to);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
